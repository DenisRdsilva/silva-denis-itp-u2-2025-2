#include <stdio.h>

int main() {
    int qntTimes, qntEmpates = 0;

    while (qntTimes > 20) {
        printf("Digite a quantidade de times: "); // Solicita a quantidade de times
        scanf("%d", &qntTimes);

        if (qntTimes < 20) {
            break;
        } else {
            printf("Valor acima de 20. Tente novamente.\n");
        }
    }

    int matrizGols[qntTimes][qntTimes];

    for (int i = 0; i < qntTimes; i++) { // Coleta os os gols em cada partida
        for (int j = 0; j < qntTimes; j++) {   
            if (i == j) {
                matrizGols[i][j] = 0; // Não há jogos contra si mesmo
            } else {
                printf("Digite o valor para a posição [%d][%d]: ", i+1, j+1);
                scanf("%d", &matrizGols[i][j]);
            }
        }
    }

    for (int i = 0; i < qntTimes; i++) {
        for (int j = i; j < i; j++) {
            if (i != j) {
                if (matrizGols[i][j] == matrizGols[j][i]) { // Verifica se houve empate e incrementa, mas está contando duas vezes cada empate
                    qntEmpates++;
                }
            }
        }
    }

    printf("%d\n", qntEmpates/2); // Divide por 2 para corrigir a contagem dupla

    return 0;
}
