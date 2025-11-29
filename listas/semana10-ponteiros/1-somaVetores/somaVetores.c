#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor1, *vetor2;
    int user1, user2;

    scanf("%d", &user1); //Lê os tamanhos dos vetores
    scanf("%d", &user2);

    if (user1 != user2) { //Encerra o programa se os tamanhos forem diferentes
        printf("dimensoes incompatíveis");
        return 0;
    }

    vetor1 = (int *)malloc(user1 * sizeof(int)); // Alocação dos vetores
    vetor2 = (int *)malloc(user2 * sizeof(int));

    for (int i = 0; i < user1; i++) { // Leitura dos valores dos vetores
        scanf("%d", &vetor1[i]);
    }

    for (int i = 0; i < user2; i++) {
        scanf("%d", &vetor2[i]);
    }

    for (int i = 0; i < user1; i++) { // Imprime a soma
        printf("%d ", vetor1[i] + vetor2[i]);
    }

    free(vetor1); // Libera a memória alocada
    free(vetor2);

    return 0;
}
