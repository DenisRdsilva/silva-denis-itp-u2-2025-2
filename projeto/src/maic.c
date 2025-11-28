#include <stdio.h>

int escolherOperacao()
{ // função que escolhe a operação a ser feita com as matrizes
    int operacao;

    do
    { // Só prossegue se o usuário escolher uma opção válida
        printf("Escolha a operação:\n1 - Soma\n2 - Subtração\n3 - Multiplicação\n4 - Determinante\n");
        scanf("%d", &operacao);
    } while (operacao < 1 || operacao > 4);

    return operacao;
}

int inserirLinhasOuColunas(int tipo)
{ // função que insere o número de linhas ou colunas
    int numero;

    if (tipo)
    {
        printf("Insira o número de colunas das matrizes: ");
    }
    else
    {
        printf("Insira o número de linhas das matrizes: ");
    }

    scanf("%d", &numero);

    return numero;
}

int main()
{
    int operacao = escolherOperacao();
    int linhas = inserirLinhasOuColunas(0);
    int colunas = inserirLinhasOuColunas(1);

    void reiniciarOuEncerrar()
    {
        int escolha;

        do
        {
            printf("Deseja: 1 - Reiniciar ou 2 - Encerrar?\n");
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

    void imprimirMatriz(int linhas, int colunas, int matriz[linhas][colunas])
    { // função que imprime a matriz
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                printf("%d", matriz[i][j]);
                if (j < colunas - 1)
                {
                    printf(" ");
                }
                if (j == colunas - 1)
                {
                    printf("\n");
                }
            }
        }
    }

    void operacaoMatrizes(int linhas, int colunas, int matriz1[linhas][colunas], int matriz2[linhas][colunas])
    {
        int resultado[linhas][colunas];

        if (operacao == 1)
        {
            for (int i = 0; i < linhas; i++)
            {
                for (int j = 0; j < colunas; j++)
                {
                    resultado[i][j] = matriz1[i][j] + matriz2[i][j]; // soma os elementos das matrizes
                }
            }
        }
        else if (operacao == 2)
        {
            for (int i = 0; i < linhas; i++)
            {
                for (int j = 0; j < colunas; j++)
                {
                    resultado[i][j] = matriz1[i][j] - matriz2[i][j]; // subtrai os elementos das matrizes
                }
            }
        }
        else if (operacao == 3)
        {
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
        imprimirMatriz(linhas, colunas, resultado);
    }

    void criarSubmatriz(int tamanho, int matriz[tamanho][tamanho], int sub[tamanho - 1][tamanho - 1],
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

    int determinante(int tamanho, int matriz[tamanho][tamanho]) // função para calcular o determinante da matriz segundo o Teorema de Laplace, buscando sempre reduzir a ordem até o formato 2x2
    {
        if (tamanho == 1) // determinante de matriz 1x1 (elemento único)
            return matriz[0][0];

        if (tamanho == 2) // determinante de matriz 2x2
            return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];

        int det = 0; // para qualquer matriz de ordem maior que 2
        int sub[tamanho - 1][tamanho - 1];
        for (int j = 0; j < tamanho; j++)
        {
            criarSubmatriz(tamanho, matriz, sub, 0, j); // cria a submatriz a partir da matriz principal, onde está fixada a primeira linha, e as colunas vão sendo iteradas

            // printf("coluna removida: %d -> submatriz criada: %dx%d:\n", j + 1, tamanho - 1, tamanho - 1); //para debug
            imprimirMatriz(tamanho - 1, tamanho - 1, sub);

            int subDet = determinante(tamanho - 1, sub); /* determinante da submatriz que tem ordem tamanho-1 */
            int sinal = (j % 2 == 0) ? 1 : -1;

            det += sinal * matriz[0][j] * subDet; // multiplica o elemento da linha removida com o cofator e o determinante da submatriz
        }

        return det;
    }

    int matriz1[linhas][colunas];
    criarMatriz(linhas, colunas, matriz1, 1);

    if (operacao != 4) // se a operação não for determinante
    {
        int matriz2[linhas][colunas];
        criarMatriz(linhas, colunas, matriz2, 2);

        operacaoMatrizes(linhas, colunas, matriz1, matriz2);
    }
    else
    {
        int det = determinante(linhas, matriz1);
        printf("Determinante: %d\n", det);
    }

    reiniciarOuEncerrar();

    return 0;
}
