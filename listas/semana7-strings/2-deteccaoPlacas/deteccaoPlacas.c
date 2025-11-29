#include <stdio.h>
#include <string.h>

int main()
{
    char placa[8];

    printf("Digite a placa: ");
    scanf("%s", placa);

    // Brasil - LLL-AAAA
    // Mercosul - LLLALAA

    int validarLetra(char letra) // Verifica se a letra é maiúscula
    {
        if (letra >= 'A' && letra <= 'Z')
        {
            return 1;
        }
        return 0;
    }

    int validarNumero(char numero) // Verifica se o caractere é um número
    {
        if (numero >= '0' && numero <= '9')
        {
            return 1;
        }
        return 0;
    }

    int validarPlacaBrasileira() // Valida se a placa está no formato brasileiro
    {
        for (int i = 0; i < 3; i++)
        {
            if (!validarLetra(placa[i]))
            {
                return 0;
            }
        }

        if (placa[3] != '-')
        {
            return 0;
        }

        for (int i = 4; i < 7; i++)
        {
            if (!validarNumero(placa[i]))
            {
                return 0;
            }
        }

        return 1;
    }

    int validarPlacaMercosul() //Valida se a placa está no formato mercosul
    {
        for (int i = 0; i < 3; i++)
        {
            if (!validarLetra(placa[i]))
            {
                return 0;
            }
        }

        if (!validarNumero(placa[3]) && !validarLetra(placa[4]))
        {
            return 0;
        }

        for (int i = 5; i < 7; i++)
        {
            if (!validarNumero(placa[i]))
            {
                return 0;
            }
        }

        return 1;
    }

    if (validarPlacaBrasileira()) //Imprime o tipo de placa, ou se é inválida
    {
        printf("brasileiro");
    }
    else if (validarPlacaMercosul())
    {
        printf("mercosul");
    }
    else
    {
        printf("inválido");
    }

    return 0;
}