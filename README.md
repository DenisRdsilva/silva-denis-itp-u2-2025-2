# Introdução a Técnicas de Programação - Unidade 1

**Aluno**: Dênis Rocha da Silva  
**Matrícula**: 20250052862  
**Período**: 2025.2

## 📂 Estrutura do Projeto
 - `projeto/`: Projeto principal da unidade 
 - `listas/`: Soluções das listas de exercícios 
 - `README.md`: Este arquivo 

## 🧮 Projeto: Calculadora de Matrizes

**Descrição**: Recebe matrizes como entrada e realiza a operação escolhida pelo usuário

**Repositório**: https://github.com/DenisRdsilva/silva-denis-itp-u1-2025-2

**Vídeo de Demonstração**: https://youtu.be/wvAlzBxETu4

### Funcionalidades Implementadas:
- Solicita que o usuário escolha a operação, atualmente estão disponíveis apenas soma e subtração;
- Solicita que o usuário forneça o número de linhas e depois o de colunas que será usado nas duas matrizes;
- Pede pro usuário inserir elemento por elemento contido na matriz, o que é repetido até que o último elemento da segunda matriz seja informado;
- Realiza a operação selecionada pelo usuário, e imprime a matriz resultante como saída.

### Conceitos da U1 Aplicados:
- Estruturas condicionais: Utilizadas na função que recebe o número de linhas e colunas, na função que direciona o tipo de operação a ser realizada entre as matrizes, e também para formatar a matriz de saída, incorporando espaços em branco e quebras de linha na impressão.
- Estruturas de repetição: Usada na escolha das operações, para apenas permitir um dos valores válidos, e usado também para inserir e para ler os elementos das matrizes através de laços aninhados.
- Vetores: Usados para armazenar os valores inseridos pelo usuário, correspondentes aos elementos contidos nas duas matrizes que estão sendo usadas para realizar as operações.
- Funções: Além da função main, estão sendo usadas outras cinco funções no código e elas são melhor detalhadas a seguir:
    - escolherOperacao() → Recebe e valida a operação desejada, retornando o inteiro equivalente a operação escolhida;
    - inserirLinhasOuColunas(int tipo) → Define as dimensões das matrizes, recebendo como entrada um int que designa o tipo da dimensão, com 0 equivalente a linha e 1 a colunas, e a distinção entre eles é feito dentro da função por meio de estrutura condicional;
    - criarMatriz(int linhas, int colunas, int matriz[linhas][colunas], int indice) → Preenche a matriz com os valores fornecidos pelo usuário, através de estruturas de laço aninhadas, usando o número de linhas e colunas, a matriz com o tamanho das linhas e colunas e o índice que diferencia se é a primeira matriz ou a segunda matriz;
    - operacaoMatrizes(int linhas, int colunas) → Realiza a soma ou subtração de cada um dos elementos das matrizes, que são acessados por meio de laços aninhados. Além disso, recebe como entrada o número das linhas e das colunas da matriz;
    - imprimirMatriz(int linhas, int colunas, int matriz[linhas][colunas]) → Exibe a matriz formatada na tela, também faz uso de estruturas de repetição aninhadas, e é a última informação repassada ao usuário antes do encerramento da execução do código.

## 📝 Listas de Exercícios 

### Semana 2 - Variáveis, Tipos e Operadores:
- ✅ Problema 1: Calculadora de IMC
- ✅ Problema 2: Conversão de temperatura
- ✅ Problema 3: Cálculo de juros compostos 
- ✅ Problema 4: Operações aritméticas básicas

### Semana 3 - Condicionais:
- ✅ Problema 1: Classificação de IMC 
- ✅ Problema 2: Calculadora de energia elétrica 
- ✅ Problema 3: Sistema de notas 
- ✅ Problema 4: Pedra, papel, tesoura 
- ✅ Problema 5: Calculadora de desconto progressivo 
- ✅ Problema 6: Diagnóstico médico simples 
- ✅ Problema 7: Sistema de equações do 2º grau 
- ✅ Problema 8: Validador de triângulos 

### Semana 4A - Repetições:
- ✅ Problema 1: Dobrar folha 
- ✅ Problema 2: Homem Aranha 
- ✅ Problema 3: Números colegas 
- ✅ Problema 4: Jogo de dardos 

### Semana 4B - Análise e Padrões:
- ✅ Questões 1-4: Análise de código 
- ✅ Questões 5-11: Implementações 

### Semana 5 - Funções:
- ✅ Problema 1: Horários das rondas 
- ✅ Problema 2: Primos triplos 
- ✅ Problema 3: Pousando a sonda espacial 

### Semana 6 - Vetores:
- ✅ Problema 1: MEC - Correção ENEM
- ✅ Problema 2: Álbum de figurinhas 
- ✅ Problema 3: A construção da ponte 
- ✅ Problema 4: Em busca do tesouro perdido 

## 📘 Principais Aprendizados 
- Síntaxe da linguagem C;
- Configuração de ambiente para compilar e executar códigos em C;
- Definição de variáveis, estruturas condicionais e de repetição, funções e manipulação de vetores em C.

## 💻 Ambiente de Desenvolvimento
- **SO**: Windows
- **Compilador**: GCC versão 15.2.0 
- **Editor**: VSCode 