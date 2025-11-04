#include <stdio.h>
#include <string.h>

int validarNumero(char c) {
    return c >= '0' && c <= '9';
}

int validarLetra(char c) {
    return (c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z');
}

int validarData(char *data) {
    return validarNumero(data[0]) &&
           validarNumero(data[1]) &&
           data[2] == '/' &&
           validarNumero(data[3]) &&
           validarNumero(data[4]);
}

void extrairNome(const char *src, char *dest) {
    int i = 0;
    while (validarLetra(src[i])) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main() {
    char aluno[20] = "Alberto";
    char frequencia[200] =
        "02/04 Mateus Priscila Alberto 04/04 Alberto 08/04 Priscila Alberto";

    // char aluno[20];
    // char frequencia[200];

    // printf("Digite o nome do aluno: ");
    // scanf("%s", aluno);

    // printf("Digite a data (DD/MM) e os alunos presentes nesse dia: ");
    // scanf("%s", frequencia);

    int faltas = 0;
    int alunoPresente = 0;
    int encontrouPrimeiraData = 0;
    int len = strlen(frequencia);

    for (int i = 0; i < len; i++) {
        if (validarData(&frequencia[i])) {
            if (encontrouPrimeiraData && alunoPresente == 0) {
                faltas++;
            }

            alunoPresente = 0;
            encontrouPrimeiraData = 1;

            i += 4;
            continue;
        }

        if (validarLetra(frequencia[i])) {
            char nome[20];
            extrairNome(&frequencia[i], nome);

            if (strcmp(nome, aluno) == 0) {
                alunoPresente = 1;
            }

            i += strlen(nome) - 1;
        }
    }

    if (encontrouPrimeiraData && alunoPresente == 0) {
        faltas++;
    }

    printf("Faltas: %d\n", faltas);
    return 0;
}
