#include <stdio.h>

int main() {
    char meses[12] = {
        "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    int qntChuva[12];

    for (int i = 0; i < 12; i++) {
        printf("Digite a quantidade de dias de chuva em %s: ", meses[i]);
        scanf("%d", &qntChuva[i]);
    }

    for (int i = 0; i < 12; i++) {
        int maiorQntChuva = -1;
        if (qntChuva[i] > maiorQntChuva) {
            maiorQntChuva = qntChuva[i];
        }
        printf("O maior número de dias de chuva em %s foi: %d\n", meses[i], maiorQntChuva);
    }

    return 0;
}
