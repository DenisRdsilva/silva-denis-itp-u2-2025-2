#include <stdio.h>

// Legenda de comentários:
//* Indica que a função existia, mas foi modificada *
//**  Indica que a função é nova **

int escolherOperacao()
{ // função que escolhe a operação a ser feita com as matrizes
    int operacao;

    do //* Foram adicionadas as opções de Multiplicação, determinante e Inversa
    { // Só prossegue se o usuário escolher uma opção válida
        printf("Escolha a operação:\n1 - Soma\n2 - Subtração\n3 - Multiplicação\n4 - Determinante\n5 - Inversa\n");
        scanf("%d", &operacao);
    } while (operacao < 1 || operacao > 5);
    

    return operacao;
}

int inserirLinhasOuColunas(int tipo)
{ // função que insere o número de linhas ou colunas
    int numero;

    if (tipo == 0)
    {
        printf("Insira o número de linha(s) das matriz(es): ");
    }
    else if (tipo == 1)
    {
        printf("Insira o número de coluna(s) das matriz(es): ");
    }
    else if (tipo == 2) //* Adicionado para as operações que precisam de matrizes quadradas *
    {
        printf("Insira o tamanho da matriz: ");
    }

    scanf("%d", &numero);

    return numero;
}

typedef enum
{
    tipoINT,
    tipoFLOAT
} TipoMatriz;

int main()
{
    int operacao = escolherOperacao(); // Armazena o número da operação escolhida
    int linhas, colunas;

    if (operacao > 2) //* As operações com número maior que 2 só operam com matrizes quadradas *
    {
        linhas = inserirLinhasOuColunas(2);
        colunas = linhas;
    }
    else
    {
        linhas = inserirLinhasOuColunas(0);
        colunas = inserirLinhasOuColunas(1);
    }

    void reiniciarOuEncerrar() //** Criada função para perguntar ao usuário se ele quer recomeçar ou encerrar o programa **
    {
        int escolha;

        do
        {
            printf("Deseja:\n1 - Reiniciar\n2 - Encerrar?\n");
            scanf("%d", &escolha);

            if (escolha == 1)
            {
                main(); // reinicia o programa
                return; // após reiniciar, encerra o loop
            }
            else if (escolha == 2)
            {
                return; // encerra o programa
            }
            else
            {
                printf("Valor inválido, tente novamente!\n");
            }

        } while (escolha != 1 && escolha != 2);
    }

    void criarMatriz(int linhas, int colunas, int matriz[linhas][colunas], int indice)
    { // função que cria a matriz
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                printf("Insira o elemento %d%d da matriz %d: ", i + 1, j + 1, indice);
                scanf("%d", &matriz[i][j]);
            }
        }
    }

    void imprimirMatriz(int linhas, int colunas, void *matriz, TipoMatriz tipo) //* Função que imprime a matriz, e foi adaptada para receber um ponteiro genérico e aceitar tanto matrizes do tipo int e do tipo float *
    {
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                if (tipo == tipoINT)
                {
                    int *matrizInt = (int *)matriz;
                    printf("%d", matrizInt[i * colunas + j]);
                }
                else if (tipo == tipoFLOAT)
                {
                    float *matrizFloat = (float *)matriz;
                    printf("%.2f", matrizFloat[i * colunas + j]);
                }

                if (j < colunas - 1)
                    printf(" ");
            }
            printf("\n");
        }
    }

    void operacaoComDuasMatrizes(int linhas, int colunas, int matriz1[linhas][colunas], int matriz2[linhas][colunas]) //* Função modificada que agora engloba apenas as operações que envolvem duas matrizes *
    {
        int resultado[linhas][colunas];

        if (operacao == 1) // soma
        {
            for (int i = 0; i < linhas; i++)
            {
                for (int j = 0; j < colunas; j++)
                {
                    resultado[i][j] = matriz1[i][j] + matriz2[i][j]; // soma os elementos das matrizes
                }
            }
        }
        else if (operacao == 2) // subtração
        {
            for (int i = 0; i < linhas; i++)
            {
                for (int j = 0; j < colunas; j++)
                {
                    resultado[i][j] = matriz1[i][j] - matriz2[i][j]; // subtrai os elementos das matrizes
                }
            }
        }
        else if (operacao == 3) // multiplicação 
        { //** Adicionado trecho com 3 loops alinhados para fazer a multiplicação das matrizes *
            for (int i = 0; i < linhas; i++)
            {
                for (int j = 0; j < colunas; j++)
                {
                    resultado[i][j] = 0;
                    for (int k = 0; k < linhas; k++)
                    {
                        resultado[i][j] = resultado[i][j] + matriz1[i][k] * matriz2[k][j];
                    }
                }
            }
        }
        imprimirMatriz(linhas, colunas, resultado, tipoINT);
    }

    void criarSubMatriz(int tamanho, int matriz[tamanho][tamanho], int sub[tamanho - 1][tamanho - 1], //** Função nova usada para criar as submatrizes usadas no cálculo do determinante e da inversa *
                        int linhaRemover, int colunaRemover) // função para criar as submatrizes usadas para o cálculo do determinante
    {
        int linhasSubMatriz = 0, colunasSubMatriz = 0;
        for (int i = 0; i < tamanho; i++)
        {
            if (i == linhaRemover) // remove a linha fixada na submatriz, que será sempre a primeira
                continue;
            colunasSubMatriz = 0;
            for (int j = 0; j < tamanho; j++)
            {
                if (j == colunaRemover) // remove a coluna fixada na submatriz, que será cada uma das colunas por vez
                    continue;
                sub[linhasSubMatriz][colunasSubMatriz] = matriz[i][j];
                colunasSubMatriz++;
            }
            linhasSubMatriz++;
        }
    }

    int determinante(int tamanho, int matriz[tamanho][tamanho]) //**  Função para calcular o determinante da matriz segundo o Teorema de Laplace, buscando sempre reduzir a ordem até o formato 2x2 **
    {
        if (tamanho == 1) // determinante de matriz 1x1 (elemento único)
            return matriz[0][0];

        if (tamanho == 2) // determinante de matriz 2x2
            return ((matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]));

        int det = 0; // para qualquer matriz de ordem maior que 2
        int sub[tamanho - 1][tamanho - 1];

        for (int j = 0; j < tamanho; j++)
        {
            criarSubMatriz(tamanho, matriz, sub, 0, j); // cria a submatriz a partir da matriz principal, onde está fixada a primeira linha, e as colunas vão sendo iteradas

            int subDet = determinante(tamanho - 1, sub); /* determinante da submatriz que tem ordem tamanho-1 */
            int sinal = (j % 2 == 0) ? 1 : -1;

            det += sinal * matriz[0][j] * subDet; // multiplica o elemento da linha removida com o cofator e o determinante da submatriz
        }

        return det;
    }

    int inversa(int tamanho, int matriz[tamanho][tamanho]) //** Função para calcular a inversa da matriz usando a matriz de cofatores, matriz adjunta e o determinante, retorna 0 se o determinante for 0, encerrando a função **
    {
        int det = determinante(tamanho, matriz);
        if (det == 0)
        {
            printf("Determinante é zero, logo a matriz não tem inversa.\n");
            return 0;
        }
        else
        {
            int cofatores[tamanho][tamanho]; // matriz de cofatores
            int adjunta[tamanho][tamanho]; // matriz adjunta que é a transposta da matriz de cofatores
            float inversa[tamanho][tamanho]; // matriz inversa que é a adjunta dividida pelo determinante
            int sub[tamanho - 1][tamanho - 1];

            for (int i = 0; i < tamanho; i++)
            {
                for (int j = 0; j < tamanho; j++)
                {
                    criarSubMatriz(tamanho, matriz, sub, i, j); // cria a submatriz a partir da matriz principal, onde está fixada a primeira linha, e as colunas vão sendo iteradas

                    int subDet = determinante(tamanho - 1, sub); // determinante da submatriz que tem ordem tamanho-1
                    int sinal = ((i + j) % 2 == 0) ? 1 : -1;

                    cofatores[i][j] = sinal * subDet;    // calcula a matriz de cofatores
                    adjunta[j][i] = cofatores[i][j];     // a adjunta é a transposta da matriz de cofatores
                    inversa[j][i] = adjunta[j][i] / det; // calcula a inversa dividindo cada elemento da adjunta pelo determinante
                }
            }
            imprimirMatriz(tamanho, tamanho, inversa, tipoFLOAT);
        }
    }

    int matriz1[linhas][colunas];
    criarMatriz(linhas, colunas, matriz1, 1);

    if (operacao < 4) //* Condicional foi modificada para tratar as novas operações *
    {
        int matriz2[linhas][colunas];
        criarMatriz(linhas, colunas, matriz2, 2);

        operacaoComDuasMatrizes(linhas, colunas, matriz1, matriz2);
    }
    else if (operacao == 5) //* se a operação for inversa *
    {
        inversa(linhas, matriz1);
    }
    else if (operacao == 4) //* se a operação for determinante *
    {
        int det = determinante(linhas, matriz1); // armazena o valor do determinante
        printf("Determinante: %d\n", det);
    }

    reiniciarOuEncerrar();

    return 0;
}
