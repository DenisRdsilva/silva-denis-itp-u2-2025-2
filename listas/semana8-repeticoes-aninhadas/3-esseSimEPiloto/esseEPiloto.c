#include <stdio.h>
#include <string.h>

int main() {
    int quantidadePilotos = 21;

    while (quantidadePilotos > 20) {
        printf("Digite a quantidade de pilotos: "); // Solicita a quantidade de pilotos
        scanf("%d", &quantidadePilotos);
        if (quantidadePilotos < 20) {
            break;
        } else {
            printf("Valor acima de 20. Tente novamente.\n");
        }
    }

    int ordemPartida[quantidadePilotos];
    int ordemChegada[quantidadePilotos];
    int maiorDiferenca = 0;
    int houveEmpate = 0;

    for (int i = 0; i < quantidadePilotos; i++) { // Coleta a ordem de partida
        printf("Digite a posição de partida do piloto %d: ", i+1);
        scanf("%d", &ordemPartida[i]);
    }

    for (int i = 0; i < quantidadePilotos; i++) { // Coleta a ordem de chegada
        printf("Digite a posição de chegada do piloto %d: ", i+1);
        scanf("%d", &ordemChegada[i]);
    }

    for (int i = 0; i < quantidadePilotos; i++) { // Compara as posições para encontrar a maior diferença
        for (int j = 0; j < quantidadePilotos; j++) {
            if (ordemPartida[i] == ordemChegada[j]) {
                if (i > j) {
                    if (i - j + 1 > maiorDiferenca) {
                        maiorDiferenca = i - j + 1;
                    } else if (i - j + 1 == maiorDiferenca) { // Verifica se há empate
                        houveEmpate = 1;
                        printf("empate");
                        break;
                    }
                }
            }
        }
    }

    if (!houveEmpate) { // Se não houve empate, imprime a maior diferença
        printf("%d\n", maiorDiferenca);
    }

    return 0;
}
