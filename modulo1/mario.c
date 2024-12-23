#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;

    // Solicita ao usuario uma altura entre 1 e 8
    do
    {
        n = get_int("Altura do triangulo: ");
    }
    while (n < 1 || n > 8);

    // Loop para cada linha
    for (int i = 0; i < n; i++)
    {
        // Imprime o espaços
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        // Imprime os blocos #
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
                //primeira piramide concluida

        printf("  "); //espaço entre piramides

        for (int j=0;j<=i;j++)
            {printf("@");}

        printf("\n");
      }

    }

