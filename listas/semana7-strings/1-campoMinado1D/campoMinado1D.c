#include <stdio.h>
int main() {
    float altura;
    int peso;

    printf("Digite o peso em Kg: ");
    scanf("%d", &peso);

    printf("Digite a altura em m: ");
    scanf("%f", &altura);

    float doublealtura = altura*altura;
    float imc = peso/doublealtura;
    
    printf("resultado é: %.2f", imc);
    return 0;
}