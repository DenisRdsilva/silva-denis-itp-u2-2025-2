#include <stdio.h>

int main() {
    int quantidadeLinhas = 11, quantidadeColunas = 11, qntSolFertilIrrigado = 0, qntSoloFertilNaoIrrigado = 0;

    while (quantidadeLinhas > 10) {
        printf("Digite a quantidade de linhas: "); // Solicita a quantidade de linhas
        scanf("%d", &quantidadeLinhas);

        if (quantidadeLinhas < 10) {
            break;
        } else {
            printf("Valor acima de 10. Tente novamente.\n");
        }
    }

    while (quantidadeColunas > 10) {
        printf("Digite a quantidade de colunas: "); // Solicita a quantidade de colunas
        scanf("%d", &quantidadeColunas);

        if (quantidadeColunas < 10) {
            break;
        } else {
            printf("Valor acima de 10. Tente novamente.\n");
        }
    }

    int campoAgricola[quantidadeLinhas][quantidadeColunas];

    for (int i = 0; i < quantidadeLinhas; i++) { // Coleta os dados do solo do campo agrícola
        for (int j = 0; j < quantidadeColunas; j++) {
            campoAgricola[i][j] = -1;

            while (campoAgricola[i][j] < 0 || campoAgricola[i][j] > 2) {
                printf("Digite o valor para a posição [%d][%d]: ", i+1, j+1);
                scanf("%d", &campoAgricola[i][j]);

                if (campoAgricola[i][j] >= 0 && campoAgricola[i][j] <= 2) {
                    break;
                } else {
                    printf("Valor inválido. Tente novamente.\n");
                }
            }
        }
    }

    for (int i = 0; i < quantidadeLinhas; i++) {
        for (int j = 0; j < quantidadeColunas; j++) {
            if (campoAgricola[i][j] == 1) { // Verifica se o solo é fertil
                int irrigado = 0;

                if (i > 0 && campoAgricola[i-1][j] == 2) { // Norte
                    irrigado = 1;
                }
 
                if (i < quantidadeLinhas-1 && campoAgricola[i+1][j] == 2) { // Sul
                    irrigado = 1;
                }

                if (j > 0 && campoAgricola[i][j-1] == 2) { // Oeste
                    irrigado = 1;
                }

                if (j < quantidadeColunas-1 && campoAgricola[i][j+1] == 2) { // Leste
                    irrigado = 1; 
                }

                if (irrigado)
                    qntSolFertilIrrigado++; // // Incrementa a quantidade de solo fértil irrigado
                else
                    qntSoloFertilNaoIrrigado++; // Incrementa a quantidade de solo fértil não irrigado
            }
        }
    }


    printf("%d %d\n", qntSolFertilIrrigado, qntSoloFertilNaoIrrigado);

    return 0;
}
