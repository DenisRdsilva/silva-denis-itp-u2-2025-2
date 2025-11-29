#include <stdio.h>
#include <string.h>

int main() {
    char meses[12][20] = { // Armazena o nome dos meses
        "Janeiro", "Fevereiro", "Março", "Abril",
        "Maio", "Junho", "Julho", "Agosto",
        "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    int chuva[12];

    for (int i = 0; i < 12; i++) { // Recebe os 12 inteiros referentes a quantidade de chuva mensal
        scanf("%d", &chuva[i]);
    }

    for (int i = 0; i < 12 - 1; i++) { // Usando Bubble Sort para ordenar do maior para o menor
        for (int j = 0; j < 12 - i - 1; j++) {

            if (chuva[j] < chuva[j + 1]) { // Troca se o valor atual for menor que o próximo
                int temp = chuva[j];
                chuva[j] = chuva[j + 1];
                chuva[j + 1] = temp;
 
                char tempMes[20]; //Troca os meses correspondentes
                strcpy(tempMes, meses[j]);
                strcpy(meses[j], meses[j + 1]);
                strcpy(meses[j + 1], tempMes);
            }
        }
    }

    for (int i = 0; i < 12; i++) { // Exibe o ranking final
        printf("%s %d\n", meses[i], chuva[i]);
    }

    return 0;
}
