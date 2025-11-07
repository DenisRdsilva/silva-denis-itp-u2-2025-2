#include <stdio.h>
#include <string.h>

int main() {
    char meses[12][20] = {
        "Janeiro", "Fevereiro", "Março", "Abril",
        "Maio", "Junho", "Julho", "Agosto",
        "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    int chuva[12];

    for (int i = 0; i < 12; i++) {
        scanf("%d", &chuva[i]);
    }

    for (int i = 0; i < 12 - 1; i++) {
        for (int j = 0; j < 12 - i - 1; j++) {
            if (chuva[j] < chuva[j + 1]) {
                int temp = chuva[j];
                chuva[j] = chuva[j + 1];
                chuva[j + 1] = temp;

                char tempMes[20];
                strcpy(tempMes, meses[j]);
                strcpy(meses[j], meses[j + 1]);
                strcpy(meses[j + 1], tempMes);
            }
        }
    }

    for (int i = 0; i < 12; i++) {
        printf("%s %d\n", meses[i], chuva[i]);
    }

    return 0;
}
