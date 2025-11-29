#include <stdio.h>

int main() {
    int M, x;

    scanf("%d", &M);

    int matriz[100][100]; // Matriz de usuários cadastrados

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    scanf("%d", &x);

    int sugestoes[100];
    int count = 0;

    for (int i = 0; i < M; i++) { // Verifica possíveis sugestões de amizade

        if (i == x) continue; // Não sugere se for ele mesmo

        if (matriz[x][i] == 1) continue; // Não sugere se já são amigos

        int amigoEmComum = 0; // Conta se há amigo em comum com x

        for (int j = 0; j < M; j++) {
            if (matriz[x][j] == 1 && matriz[i][j] == 1) {
                amigoEmComum = 1;
                break;
            }
        }

        if (amigoEmComum) {
            sugestoes[count] = i;
            count++;
        }
    }

    for (int i = 0; i < count - 1; i++) { // Ordena as sugestões em ordem crescente (bubble sort simples)
        for (int j = 0; j < count - i - 1; j++) {
            if (sugestoes[j] > sugestoes[j + 1]) {
                int temp = sugestoes[j];
                sugestoes[j] = sugestoes[j + 1];
                sugestoes[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++) { // Imprime as sugestões
        printf("%d ", sugestoes[i]);
    }

    return 0;
}
