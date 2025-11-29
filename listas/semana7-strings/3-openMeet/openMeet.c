#include <stdio.h>

int ehNumero(char c)
{
    return c >= '0' && c <= '9';
}

int ehLetra(char c)
{
    return (c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z');
}

int ehData(char texto[], int pos)
{
    return ehNumero(texto[pos]) &&
           ehNumero(texto[pos + 1]) &&
           texto[pos + 2] == '/' &&
           ehNumero(texto[pos + 3]) &&
           ehNumero(texto[pos + 4]);
}

void copiarNome(char texto[], int inicio, char nome[])
{
    int j = 0;

    while (ehLetra(texto[inicio]))
    {
        nome[j] = texto[inicio];
        j++;
        inicio++;
    }

    nome[j] = '\0';
}

int nomesIguais(char a[], char b[])
{
    int i = 0;
    while (a[i] != '\0' || b[i] != '\0')
    {
        if (a[i] != b[i])
            return 0;
        i++;
    }
    return 1;
}

int main()
{
    // char aluno[20] = "Alberto";
    // char frequencia[200] =
    //     "02/04 Mateus Priscila Alberto 04/04 Alberto 08/04 Priscila Alberto";

    char aluno[20];
    char frequencia[200];

    printf("Digite o nome do aluno: ");
    scanf("%s", aluno);

    printf("Digite a data (DD/MM) e os alunos presentes nesse dia: ");
    scanf("%s", frequencia);

    int faltas = 0;    // Contador de faltas
    int presente = 0;  // bool para presença do aluno na data
    int achouData = 0; // bool para se for encontrado ao menos uma data

    for (int i = 0; frequencia[i] != '\0'; i++)
    {

        if (ehData(frequencia, i))
        { // Identifica data no formato DD/MM dentro da string

            if (achouData && !presente)
            {
                faltas++;
            }

            achouData = 1;
            presente = 0;

            i += 4; // Salta "DD/MM"
            continue;
        }

        if (ehLetra(frequencia[i]))
        {
            char nome[20];
            copiarNome(frequencia, i, nome);

            if (nomesIguais(nome, aluno))
            { // Verifica se o nome encontrado é o do aluno procurado
                presente = 1;
            }

            int j = 0; // Avança até o fim do nome
            while (nome[j] != '\0')
                j++;
            i += (j - 1);
        }
    }

    if (achouData && !presente)
    { // Verifica se o aluno faltou na última data
        faltas++;
    }

    printf("Faltas: %d\n", faltas);

    return 0;
}
