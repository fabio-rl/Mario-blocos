#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void){

    float n;
    int cents;
    int coins = 0;

        do
    {
        n = get_float("Quanto eu te devo? ");
    }
    while (n < 0);

    // Converte o valor para centavos, arredondando
    cents = round(n * 100);

    // Calcula o número mínimo de moedas
    while (cents > 0)
    {
        if (cents >= 25) // Moedas de 25 centavos
        {
            cents -= 25;
            coins++;
        }
        else if (cents >= 10) // Moedas de 10 centavos
        {
            cents -= 10;
            coins++;
        }
        else if (cents >= 5) // Moedas de 5 centavos
        {
            cents -= 5;
            coins++;
        }
        else // Moedas de 1 centavo
        {
            cents -= 1;
            coins++;
        }
    }

    // Imprime o número total de moedas
    printf("Vou te pagar com: %d\n", coins);
}
