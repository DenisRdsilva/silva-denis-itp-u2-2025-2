#include <stdio.h>
#include <string.h> 

int main() {
    char palavra[20];
    int indice = 0;

    char elemento[20];
    printf("Digite x ou .: ");
    scanf("%s", elemento);

    for (int i = 0; i < strlen(elemento) && indice < sizeof(palavra) - 1; i++) {
        if (elemento[i] == 'x' || elemento[i] == '.') {
            palavra[indice] = elemento[i];
            indice++;
        }
    } // Preenche o array com 'x' e '.'

    palavra[indice] = '\0'; // Finaliza a string

    int checarIndice(int ind) {
        if (palavra[ind] == 'x') {
            return 1; // Achou uma bomba
        }
        return 0; // Indice válido
    }

    printf("Digite o indice: ");
    scanf("%d", &indice);

    if (checarIndice(indice)) {
        printf("bum!");
    } else {
        int total = checarIndice(indice - 1);
        total += checarIndice(indice + 1);
        printf("%d\n", total);
    }

    return 0;
}