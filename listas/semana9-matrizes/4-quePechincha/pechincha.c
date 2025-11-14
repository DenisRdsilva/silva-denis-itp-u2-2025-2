#include <stdio.h>

int main() {
    int qntCidades, precoMenor = 0;

    while (qntCidades > 10) {
        printf("Digite a quantidade de times: "); // Solicita a quantidade de times
        scanf("%d", &qntCidades);

        if (qntCidades < 10) {
            break;
        } else {
            printf("Valor acima de 10. Tente novamente.\n");
        }
    }

    int matrizCidades[qntCidades][qntCidades];

    for (int i = 0; i < qntCidades; i++) { 
        for (int j = 0; j < qntCidades; j++) {   
            if (i == j) {
                matrizCidades[i][j] = 0; 
            } else {
                printf("Digite o valor para a posição [%d][%d]: ", i+1, j+1);
                scanf("%d", &matrizCidades[i][j]);
            }
        }
    }

    // for (int i = 0; i < qntTimes; i++) {
    //     for (int j = i; j < i; j++) {
    //         if (i != j) {
    //             if (matrizCidades[i][j] == matrizCidades[j][i]) { // Verifica se houve empate e incrementa, mas está contando duas vezes cada empate
    //                 qntEmpates++;
    //             }
    //         }
    //     }
    // }

    // printf("%d\n", qntEmpates/2); // Divide por 2 para corrigir a contagem dupla

    return 0;
}
