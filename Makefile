CFLAGS = -Wall -Werror
LDFLAGS = -lm

CODIGOS_DIR = Codigos
EXEC_DIR = Executaveis

SRC = $(wildcard $(CODIGOS_DIR)/*.c)
EXEC = $(patsubst $(CODIGOS_DIR)/%.c,$(EXEC_DIR)/%,$(SRC))

# Regra principal para compilar todos os arquivos
all: $(EXEC_DIR) $(EXEC)

$(EXEC_DIR):
	@mkdir -p $(EXEC_DIR)

$(EXEC_DIR)/%: $(CODIGOS_DIR)/%.c | $(EXEC_DIR)
	gcc $(CFLAGS) $< -o $@ $(LDFLAGS)

# Regra para executar um arquivo específico
run: all
	@echo "Digite o nome do programa para rodar (sem extensão):"
	@read exec_name; \
	if [ -x "$(EXEC_DIR)/$$exec_name" ]; then \
		valgrind $(EXEC_DIR)/$$exec_name; \
	else \
		echo "Erro: Executável $$exec_name não encontrado."; \
	fi

# Regra para testar um arquivo específico com casos de teste
testes: all
	@echo "Digite o nome do programa para testar (sem extensão):"
	@read exec_name; \
	test_dir="Testes/$$exec_name"; \
	if [ -x "$(EXEC_DIR)/$$exec_name" ] && [ -d "$$test_dir" ]; then \
		./testar.sh $(EXEC_DIR)/$$exec_name $$test_dir; \
	else \
		echo "Erro: Programa ou pasta de testes não encontrados."; \
	fi

# Limpar os executáveis gerados
clean:
	rm -rf $(EXEC_DIR)
