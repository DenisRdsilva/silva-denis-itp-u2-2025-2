#include <stdio.h>

int escolherOperacao() { // função que escolhe a operação a ser feita com as matrizes
    int operacao;

    do { // Só prossegue se o usuário escolher uma opção válida
        // printf("Escolha a operação:\n1 - Soma\n2 - Subtração\n");
        printf("Escolha a operação:\n1 - Soma\n2 - Subtração\n3 - Multiplicação\n");
        scanf("%d", &operacao);
    } while (operacao < 1 || operacao > 3);
    // } while (operacao < 1 || operacao > 3);

    return operacao;
}

int inserirLinhasOuColunas(int tipo) { // função que insere o número de linhas ou colunas
    int numero;

    if (tipo) {
        printf("Insira o número de colunas das matrizes: ");
    } else {
        printf("Insira o número de linhas das matrizes: ");
    }

    scanf("%d", &numero);

    return numero;
}

void iniciarOuEncerrar() { // função que reinicia ou encerra o programa  
    int escolha = 0;

    while (escolha != 2 || escolha != 1) {
        if (escolha == 1) {
            main();
            break;
        } else if (escolha == 2) {
            break;
        } else {
            printf("Valor inválido, tente novamente!\n");
        }
        printf("Deseja: 1 - Reiniciar ou 2 - Encerrar?\n");
        scanf("%d", &escolha);
    }
}

int main(){
    int operacao = escolherOperacao();
    int linhas = inserirLinhasOuColunas(0);
    int colunas = inserirLinhasOuColunas(1);

    void criarMatriz(int linhas, int colunas, int matriz[linhas][colunas], int indice) { // função que cria a matriz
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                printf("Insira o elemento %d%d da matriz %d: ", i+1, j+1, indice);
                scanf("%d", &matriz[i][j]);
            }
        }
    }

    void imprimirMatriz(int linhas, int colunas, int matriz[linhas][colunas]) { // função que imprime a matriz
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                printf("%d", matriz[i][j]);
                if (j < colunas - 1) {
                    printf(" ");
                }
                if (j == colunas - 1) {
                    printf("\n");
                }
            }
        }
        reinicarOuEncerrar();
    }

    void operacaoMatrizes(int linhas, int colunas, int matriz1[linhas][colunas], int matriz2[linhas][colunas]) { 
        int resultado[linhas][colunas];

        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                if (operacao == 1) {
                    resultado[i][j] = matriz1[i][j] + matriz2[i][j]; // soma os elementos das matrizes
                } else if (operacao == 2) {
                    resultado[i][j] = matriz1[i][j] - matriz2[i][j]; // subtrai os elementos das matrizes
                } else if (operacao == 3) {
                    resultado[i][j] = 0;
                    for (int k = 0; k < linhas; k++) {
                        resultado[i][j] = resultado[i][j] + matriz1[i][k]*matriz2[k][j];
                    }
                } else if (operacao == 4) {
                    int novaLinha = linhas;
                    int novaColuna = colunas;

                    int novaMatriz[novaLinha][novaColuna];

                    int novoI = 0, novoJ = 0;

                    if (j < colunas) {
                        novoI = i+1;
                        novoJ = j+1;
                    }

                    // for (int k = novaColuna; k > 0; k--) {
                    //     novaMatriz[i][j]; = matriz1[i][k];
                    // }
                    
                        // diagonalPrincipal += matriz1[i][i];
                        // diagonalSecundaria += matriz1[i][linhas - i - 1];

                }
            }
        }
        imprimirMatriz(linhas, colunas, resultado);
    }

    if (operacao != 3) {
        int matriz1[linhas][colunas];
        int matriz2[linhas][colunas];

        criarMatriz(linhas, colunas, matriz1, 1);
        criarMatriz(linhas, colunas, matriz2, 2);

        operacaoMatrizes(linhas, colunas, matriz1, matriz2);
    // } else {
    //     int linhasMatriz1 = linhas;
    //     int colunasMatriz1 = colunas;
    //     int linhasMatriz2 = inserirLinhasOuColunas(0);
    //     int colunasMatriz2 = inserirLinhasOuColunas(1);

    //     int matriz1[linhasMatriz1][colunasMatriz1];
    //     int matriz2[linhasMatriz2][colunasMatriz2];

    //     criarMatriz(linhasMatriz1, colunasMatriz1, matriz1, 1);
    //     criarMatriz(linhasMatriz2, colunasMatriz2, matriz2, 2);

    //     operacaoMatrizes(linhasMatriz1, colunasMatriz2, matriz1, matriz2);
    }
    
    return 0;
}   