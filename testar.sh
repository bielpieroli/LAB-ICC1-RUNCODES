#!/bin/bash

# Verifica se o programa e a pasta de testes foram passados como argumentos
if [ "$#" -ne 2 ]; then
    echo "Uso: $0 <programa> <pasta_de_testes>"
    exit 1
fi

programa=$1
pasta_testes=$2

# Verifica se o executável existe
if [ ! -x "$programa" ]; then
    echo "Erro: Programa '$programa' não encontrado ou não é executável."
    exit 1
fi

# Verifica se a pasta de testes existe
if [ ! -d "$pasta_testes" ]; then
    echo "Erro: Pasta de testes '$pasta_testes' não encontrada."
    exit 1
fi

# Contadores para os resultados
PASSARAM=0
FALHARAM=0
ERROS_VALGRIND=0

# Itera sobre os arquivos de teste na pasta (ordenando numericamente)
for entrada in $(ls "$pasta_testes"/*.in | sort -V); do
    nome_base=$(basename "$entrada" .in)
    saida_esperada="$pasta_testes/$nome_base.out"

    # Verifica se o arquivo de saída esperada existe
    if [ ! -f "$saida_esperada" ]; then
        echo "Aviso: Arquivo de saída esperado '$saida_esperada' não encontrado. Pulando teste."
        continue
    fi

    # Executa o programa com Valgrind e verifica se há erros de memória
    echo "============================================="
    echo "Executando teste '$nome_base' com Valgrind..."
    echo "============================================="
    valgrind --leak-check=full --error-exitcode=1 ./$programa < "$entrada" > saida_obtida.tmp 2> valgrind_log.tmp
    valgrind_status=$?

    if [ $valgrind_status -ne 0 ]; then
        echo "🔴 Teste '$nome_base': FALHOU (erros de memória detectados pelo Valgrind)"
        cat valgrind_log.tmp
        ERROS_VALGRIND=$((ERROS_VALGRIND + 1))
        FALHARAM=$((FALHARAM + 1))
        rm -f saida_obtida.tmp valgrind_log.tmp
        continue
    fi

    # Compara a saída obtida com a saída esperada, ignorando espaços e quebras de linha extras
    if diff -w -B -q saida_obtida.tmp "$saida_esperada" > /dev/null; then
        echo "✅ Teste '$nome_base': SUCESSO"
        PASSARAM=$((PASSARAM + 1))
    else
        echo "❌ Teste '$nome_base': FALHOU"
        echo "--- Saída esperada: ---"
        cat "$saida_esperada"
        echo "--- Saída obtida: ---"
        cat saida_obtida.tmp
        echo "--- Linhas divergentes: ---"
        diff -w -B -y --suppress-common-lines "$saida_esperada" saida_obtida.tmp | sed 's/^/    /'
        FALHARAM=$((FALHARAM + 1))
    fi

    # Limpa os arquivos temporários
    rm -f saida_obtida.tmp valgrind_log.tmp
done

# Exibir resumo dos resultados
echo "============================================="
echo "Resumo dos Resultados:"
echo "============================================="
[ "$PASSARAM" -ne 0 ] && echo "✅ Passaram: $PASSARAM"
[ "$FALHARAM" -ne 0 ] && echo "❌ Falharam: $FALHARAM"
[ "$ERROS_VALGRIND" -ne 0 ] && echo "🔴 Erros de memória detectados: $ERROS_VALGRIND"
echo "============================================="

