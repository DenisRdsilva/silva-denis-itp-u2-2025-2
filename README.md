# Introdução a Técnicas de Programação - Unidade 2

**Aluno**: Dênis Rocha da Silva  
**Matrícula**: 20250052862  
**Período**: 2025.2

## 📂 Estrutura do Projeto
 - `projeto/`: Projeto principal da unidade 
 - `listas/`: Soluções das listas de exercícios 
 - `README.md`: Este arquivo 

## 🧮 Projeto: Calculadora de Matrizes

**Descrição**: Recebe matrizes como entrada e realiza a operação escolhida pelo usuário

**Repositório**: https://github.com/DenisRdsilva/silva-denis-itp-u2-2025-2

**Vídeo de Demonstração**: https://youtu.be/QJ0Rgan00kA

### Funcionalidades Implementadas:
- Solicita que o usuário escolha a operação, atualmente estão disponíveis soma, subtração, multiplicação, determinante e inversa;
- A depender da operação escolhida, solicita que o usuário forneça o número de linhas e depois o de colunas que será usado nas duas matrizes ou apenas um tamanho, que será usado tanto para as linhas quanto para as colunas;
- Pede pro usuário inserir elemento por elemento contido na matriz, o que é repetido até que o último elemento seja informado;
- Realiza a operação selecionada pelo usuário, e imprime a matriz resultante como saída.
- Pergunta ao usuário se ele deseja reiniciar o proframa, voltando para a escolha de operações, ou se ele quer encerrar.

### Conceitos da U1 Aplicados:
- Estruturas condicionais: Utilizadas na função que recebe o número de linhas e colunas, na função que direciona o tipo de operação a ser realizada entre as matrizes, e também para formatar a matriz de saída, incorporando espaços em branco e quebras de linha na impressão.
- Estruturas de repetição: Usada na escolha das operações, para apenas permitir um dos valores válidos, e usado também para inserir e para ler os elementos das matrizes através de laços aninhados.
- Vetores: Usados para armazenar os valores inseridos pelo usuário, correspondentes aos elementos contidos nas duas matrizes que estão sendo usadas para realizar as operações.
- Funções: Além da função main, estão sendo usadas outras cinco funções no código e elas são melhor detalhadas a seguir:
    - escolherOperacao() → Recebe e valida a operação desejada, retornando o inteiro equivalente a operação escolhida;
    - inserirLinhasOuColunas(int tipo) → Define as dimensões das matrizes, recebendo como entrada um int que designa o tipo da dimensão, com 0 equivalente a linha e 1 a colunas, 2 para tamanho único e a distinção entre eles é feito dentro da função por meio de estrutura condicional;
    - criarMatriz(int linhas, int colunas, int matriz[][], int indice) → Pede ao usuário para preencher cada elemento da matriz, indicando qual matriz está sendo preenchida (1 ou 2).
    - reiniciarOuEncerrar() → Pergunta ao usuário se ele quer reiniciar o programa ou encerrar. Se escolher 1, chama a main() novamente.
    - imprimirMatriz(int linhas, int colunas, void *matriz, TipoMatriz tipo) → Função genérica composta por loops aninhados que imprime uma matriz que pode ser: int, float. Usa ponteiro genérico e através de uma condicional direciona ao tipo correto para imprimir.
    - operacaoComDuasMatrizes(int linhas, int colunas, int matriz1[linhas][colunas], int matriz2[linhas][colunas]) → Executa soma, subtração ou multiplicação entre duas matrizes e depois imprime a matriz resultante. Utiliza dois loops aninhados para soma e subtração e três para multiplicação.
    - criarSubMatriz(int tamanho, int matriz[tamanho][tamanho], int sub[tamanho - 1][tamanho - 1], int linhaRemover, int colunaRemover) → Cria uma submatriz removendo uma linha e uma coluna da matriz original. É usada no cálculo dos cofatores que são usados tanto para os determinantes quanto para a inversão.
    - determinante(int tamanho, int matriz[tamanho][tamanho]) → Calcula o determinante recursivamente usando teorema de Laplace (fixando sempre a primeira linha). Reduz o problema até matrizes 2×2.
    - inversa(int tamanho, int matriz[tamanho][tamanho]) → Verifica se o determinante da matriz é zero, se for informa que a matriz não é inversível, se não for calcula a matriz inversa através da divisão dos elementos da matriz adjunta pelo determinante.

### Conceitos da U2 Aplicados:
    - Loops aninhados: Usado em múltiplas etapas do código tanto para criar, acessar e manipular os elementos das matrizes e para imprimir a resposta.
    - Matrizes: É o objeto principal do projeto, sendo utilizada para armazenar os valores informados pelo usuário e para armazenar os resultados das operações executadas.
    - Ponteiros: Usado na função de impressão de matrizes, pois a função que calcula a inversa gera uma matriz tipo float, enquanto que as demais são tipo int, e o ponteiro foi essencial para permitir, como parâmetro da função, qualquer um desses formatos.

## 📝 Listas de Exercícios 

### Semana 7 - Strings:
- ✅ Problema 1: Campo Minado 1D
- ✅ Problema 2: Detecção de placas 
- ✅ Problema 3: OpenMeet 

### Semana 8 - Repetições aninhadas:
- ✅ Problema 1: Estou com sorte (ou não) 
- ✅ Problema 2: Os dias mais chuvosos
- ✅ Problema 3: Esse sim é piloto 

### Semana 9 - Matrizes:
- ✅ Problema 1: Campo Agrícola 
- ✅ Problema 2: Sugestão de Amigos
- ✅ Problema 3: Campeonato de empates
- ✅ Problema 4: Uma pechincha!

### Semana 10 - Ponteiros/Alocação:
- ✅ Problema 1: Soma de Vetores
- ✅ Problema 2: Ocorrências no vetor
- ✅ Problema 3: Sopa de letrinhas

## 📘 Principais Aprendizados 
- Síntaxe da linguagem C;
- Configuração de ambiente para compilar e executar códigos em C;
- Definição de variáveis, estruturas condicionais e de repetição, funções e manipulação de vetores em C.

## 💻 Ambiente de Desenvolvimento
- **SO**: Windows
- **Compilador**: GCC versão 15.2.0 
- **Editor**: VSCode 