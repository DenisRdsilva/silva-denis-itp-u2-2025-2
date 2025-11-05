#include <stdio.h>

int main() {
    int qntNumerosSorteados;
    int qntNumerosAposta;
    int qntAcertos = 0;

    printf("Digite a quantidade de números sorteados: "); //pede a quantidade de números que serão sorteados
    scanf("%d", &qntNumerosSorteados);

    printf("Digite a quantidade de números apostados: "); //pede a quantidade de números que serão apostados
    scanf("%d", &qntNumerosAposta);

    int numerosAposta[qntNumerosAposta]; 
    int numerosSorteados[qntNumerosSorteados];

    for (int i = 0; i < qntNumerosSorteados; i++) { //pede os números sorteados
        printf("Digite o número sorteado %d: ", i + 1);
        scanf("%d", &numerosSorteados[i]);
    }

    for (int i = 0; i < qntNumerosAposta; i++) { //pede os números apostados
        printf("Digite o número apostado %d: ", i + 1);
        scanf("%d", &numerosAposta[i]);
    }

    for (int i = 0; i < qntNumerosAposta; i++) {
        for (int j = 0; j < qntNumerosSorteados; j++) {
            if (numerosAposta[i] == numerosSorteados[j]) {
                qntAcertos++; //aumenta sempre que um valor apostado estiver certo
            }
        }
    }

    printf("%d", qntAcertos); //imprime a quantidade de acertos
    return 0;
}
