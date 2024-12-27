# ICC1-RUNCODES

## CONTEXTUALIZAÇÃO:
Esses códigos foram feitos na linguagem de programação C, ao longo do primeiro período da graduação em Bacharelado em Ciências de Computação na USP de São Carlos (ICMC), na disciplina de Laboratório de Introdução à Ciência de Computação I. 

## AUTOR DOS CÓDIGOS:
 - João Gabriel Pieroli da Silva 

## RESPONSÁVEIS PELA DISCIPLINA:
 - João do Espírito Santo Batista Neto (Docente)
 - Joao Luis Garcia Rosa (Docente)
 - Rudinei Goularte (Docente)
 - Marcelo Garcia Manzato (Docente)
 - Bruno Basckeira Chinaglia (Monitor)
 - Augusto Cavalcante Barbosa Pereira (Monitor) 
 - Luiz fellipe Catuzzi Araujo Hotoshi (Monitor)
 - Vitor Hugo Almeida Couto (Monitor)

## CORRETUDE:
Os códigos em questão foram submetidos à correção por meio de casos testes, conforme a descrição da problemática em que o código se pauta, na plataforma `Runcodes`. Em cada código, há uma breve descrição da ideia geral da proposta, a fim de explicitar, de forma mais sucinta, as orientações recebidas para a construção do respectivo algoritmo. Para simular a plataforma `Runcodes`, o autor optou por desenvolver um script em `bash` para automatizar a correção localmente dos códigos, conforme os casos testes ofertados pelos responsáveis pela disciplina.

## ESTRUTURAÇÃO DO REPOSITÓRIO:
  * **Makefile:**
  Apresenta as regras desenvolvidas quanto à automação dos comandos de terminal
  * **testar.sh:**
  Trata-se de um `bash script` em que se desenvolveu a lógica para corrigir o código, verificando a corretude conforme os casos testes fornecidos e executando-os com `valgrind`, em busca de erros quanto ao uso de memória.
  * **arquivos.txt**
  Representa uma lista com o nome dos códigos sem a extensão,com o único fito de facilitar copiar e colar no terminal os nomes dos arquivos
  * **DIRETÓRIOS:**
	   - ***arq_bin*** é um repositório em que estão separados os arquivos utilizados para códigos em que são necessária leitura de arquivo `.bin`.
	   - ***Codigos*** é aquele em que estão localizados os códigos desenvolvidos na linguagem C.
	   - ***Executaveis*** é aquele em que estão localizados os executáveis dos códigos desenvolvidos. Após uma nova compilação de um código, o seu respectivo executável é alterado automaticamente.
	   - ***Testes*** é o local em que estão localizados os casos testes, tanto as entradas, quanto as saídas esperadas, para aquela proposta, na forma 1.in, 1.out, 2.in, 2.out... Elas estão separadas também em repositórios, cujos nomes são os do respectivo executável do código.

## AUTOMAÇÃO:

A automação do processo de compilação, execução e teste dos códigos foi desenvolvida utilizando `make` com um conjunto de comandos descritos abaixo. Essa seção explica como utilizar o `Makefile` e os scripts relacionados.

### **Comandos Disponíveis no Makefile**

1. **Compilar todos os códigos**  
```
   make all
```
Este comando compila todos os arquivos .c localizados no diretório Codigos/ e gera os executáveis correspondentes na pasta Executaveis/.
2. **Executar um programa específico**
```
   make run
```
  Após chamar este comando, você será solicitado a informar o nome do programa (sem extensão). O comando verifica se o executável existe e o executa utilizando o `valgrind` para verificar o uso correto da memória.
	* EXEMPLO:
```
   make run
   Digite o nome do programa para rodar (sem extensão):
   meu_programa
```
 3. **Testar um programa específico com casos de teste**
```
make testes
```
Após chamar este comando, você será solicitado a informar o nome do programa (sem extensão). O comando verifica se o executável e os casos de teste estão presentes. Em seguida, o script `testar.sh` será utilizado para rodar o programa com os casos de teste localizados em `Testes/<nome_do_programa>/`, verificando não só a corretude, como a adequada utilização da memória, por meio do `valgrind`.
	* EXEMPLO:
```
   make testes
   Digite o nome do programa para rodar (sem extensão):
   meu_programa
```
4. **Limpar a pasta dos executáveis**
```
   make clean
```
O comando abaixo remove todos os executáveis localizados na pasta `Executaveis/` e apaga esse diretório em que estavam armazenados.