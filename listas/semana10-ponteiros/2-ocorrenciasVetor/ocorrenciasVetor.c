#include <stdio.h>
#include <stdlib.h>

int *buscaNoVetor(int *v, int n, int valor, int *maior, int *qtd)
{
    int count = 0;

    // Conta quantas vezes o valor aparece
    for (int i = 0; i < n; i++)
    {
        if (v[i] == valor)
            count++;
    }

    if (count == 0) // Retorna Null s enão encontrar nada
    {
        *qtd = 0;  // Nenhuma ocorrência
        return NULL;
    }

    *qtd = count; // Guarda no ponteiro qtd o número de ocorrências

    int *indices = (int *) malloc(count * sizeof(int)); // Aloca dinamicamente um vetor para os índices encontrados


    
    int k = 0; // Copia os índices pro novo vetor
    for (int i = 0; i < n; i++)
    {
        if (v[i] == valor)
        {
            indices[k] = i;
            k++;
        }
    }

    return indices;
}

int main()
{
    int n;

    scanf("%d", &n); // Lê a quantidade de elementos

    int *v = (int *) malloc(n * sizeof(int)); // Alocação dinâmica do vetor

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int valor;
    scanf("%d", &valor);

    int qtd;     // Quantidade de ocorrências
    int *maior;  // Será ignorado

    int *indices = buscaNoVetor(v, n, valor, maior, &qtd); // Chama função para buscar índices

    if (indices == NULL)
    {
        printf("Nenhuma ocorrencia\n");
    }
    else
    {
        printf("%d\n", qtd);

        for (int i = 0; i < qtd; i++)
        {
            printf("%d ", indices[i]);
        }
        printf("\n");

        free(indices); // Libera a memória alocada para os índices
    }

    free(v); // Libera a memória alocada para o vetor
    return 0;
}
