#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *misturar(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    char *nova = (char *) malloc(len1 + len2 + 1); // +1 para o '\0'

    int i = 0;     // índice str1
    int j = 0;     // índice str2
    int k = 0;     // índice nova string

    while (i < len1 && j < len2) // Alterna caracteres enquanto ainda houver em ambas
    {
        nova[k++] = str1[i++];
        nova[k++] = str2[j++];
    }

    while (i < len1) // Copia o restante da string maior (se houver)
        nova[k++] = str1[i++];

    while (j < len2)
        nova[k++] = str2[j++];

    nova[k] = '\0'; // Adiciona o finalizador de string

    return nova;
}

int main()
{
    char s1[101];
    char s2[101];

    fgets(s1, 101, stdin); // Lê as strings
    fgets(s2, 101, stdin);

    s1[strcspn(s1, "\n")] = '\0'; // Remove o '\n' se existir
    s2[strcspn(s2, "\n")] = '\0';

    char *resultado = misturar(s1, s2);

    printf("%s\n", resultado);

    free(resultado); // Libera a memória alocada para a string

    return 0;
}
