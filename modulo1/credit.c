#include <cs50.h>
#include <stdio.h>
#include <math.h>

// Declarações das funções
int num_digitos(long num_card);
int dois_primeiros(long num_card, int num_digit_total);
int multipliacar(long num_card);
int somar(long num_card);
void validar(int resultado_final, int dois_primeiros_digitos, int num_digit_total);

int main(void)
{
    // Entrada do número do cartão
    long num_card = get_long("Digite o numero do seu cartão de credito sem traços: ");

    // Calcula o número total de dígitos
    int num_digit_total = num_digitos(num_card);
    //printf("Número de dígitos: %d\n", num_digit_total); // Debug

    // Calcula os dois primeiros dígitos
    int dois_primeiros_digitos = dois_primeiros(num_card, num_digit_total);
    //printf("Dois primeiros dígitos: %d\n", dois_primeiros_digitos); // Debug

    // Calcula a soma das multiplicações alternadas
    int multiplicacao = multipliacar(num_card);
    //printf("Soma das multiplicações: %d\n", multiplicacao); // Debug

    // Soma os dígitos não multiplicados
    int soma = somar(num_card);
    //printf("Soma dos dígitos não multiplicados: %d\n", soma); // Debug

    // Exibe resultado final do algoritmo de Luhn
    int resultado_final = multiplicacao + soma;
    validar(resultado_final, dois_primeiros_digitos, num_digit_total);

    return 0;
}

       //Funções

int num_digitos(long num_card)
{
    int num_digitos = 0;
    while (num_card > 0)
    {
        num_card /= 10;
        num_digitos++;
    }
    return num_digitos;
}

        //dois primeiros

int dois_primeiros(long num_card, int num_digit_total)
{
    int dois_primeiros = num_card / pow(10, num_digit_total - 2);
    return dois_primeiros;
}

        //multiplicar

int multipliacar(long num_card)
{
    int multiplicacao = 0;
    while (num_card > 0)
    {
        num_card /= 10;
        int operacao = (num_card % 10) * 2;
        if (operacao > 9)
        {
            operacao = (operacao % 10) + (operacao / 10);
        }
        multiplicacao += operacao;
        num_card /= 10;
    }
    return multiplicacao;
}

        //somar

int somar(long num_card)
{
    int soma = 0;
    while (num_card > 0)
    {
        soma += num_card % 10;
        num_card /= 100;
    }
    return soma;
}

        //Validar

void validar(int resultado_final, int dois_primeiros_digitos, int num_digit_total)
{
    if (resultado_final % 10 == 0)
    {

        if ((dois_primeiros_digitos == 34 || dois_primeiros_digitos == 37) && (num_digit_total == 15))
        {
        if ((dois_primeiros_digitos == 34 || dois_primeiros_digitos == 37) && (num_digit_total == 15))
        {
            printf("VALID\n AMEX\n");
        }
        else if ((dois_primeiros_digitos >= 51 && dois_primeiros_digitos <= 55) && (num_digit_total == 16))
        {
            printf("VALID\n Master Card\n");
        }
        else if ((dois_primeiros_digitos >= 40 && dois_primeiros_digitos <= 49) && (num_digit_total >= 13 && num_digit_total <= 16))
        {
            printf("VALID\n VISA\n");
        }
        else if (resultado_final % 10 == 0)
        {
            printf("VALID, but not VISA, Mastercard or AMEX\n");
        }
        else
        {
            printf("INVALIDO\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
}
