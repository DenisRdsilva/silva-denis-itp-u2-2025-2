#include <stdio.h>
#include <string.h>

int main()
{
    char placa[8];

    printf("Digite a placa: ");
    scanf("%s", placa);

    // Brasil - LLL-AAAA
    // Mercosul - LLLALAA

    int validarLetra(char letra)
    {
        if (letra >= 'A' && letra <= 'Z')
        {
            return 1;
        }
        return 0;
    }

    int validarNumero(char numero)
    {
        if (numero >= '0' && numero <= '9')
        {
            return 1;
        }
        return 0;
    }

    int validarPlacaBrasileira(char *placa)
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

    int validarPlacaMercosul(char *placa)
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

    if (validarPlacaBrasileira(placa))
    {
        printf("brasileiro");
    }
    else if (validarPlacaMercosul(placa))
    {
        printf("mercosul");
    }
    else
    {
        printf("inválido");
    }

    return 0;
}