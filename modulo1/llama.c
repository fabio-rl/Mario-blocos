#include <cs50.h>
#include <stdio.h>

// Funções
long inicial(long n_llamas);
long final(long n_llamas, long n_final);
long adicionar(long n_llamas);
long subtrair(long n_llamas);
int anos(long n_llamas, long n_final);

int main(void)
{
    // Entrada do número inicial de llamas
    long n_llamas = get_long("Digite o número inicial de llamas: \n");
    n_llamas = inicial(n_llamas); // Atualiza o número inicial de llamas

    // Entrada do número final de llamas
    long n_final = get_long("Digite o número final de llamas: \n");
    n_final = final(n_llamas, n_final); // Verifica o número final de llamas

    // Calcula o número de anos necessários
    int total_anos = anos(n_llamas, n_final);
    printf("Serão necessários %d anos para atingir o número final de llamas.\n", total_anos);

    return 0;
}

// Função para verificar o número inicial
long inicial(long n_llamas)
{
    while (n_llamas < 9)
    {
        printf("O número %ld é menor que 9. Digite um número maior.\n", n_llamas);
        n_llamas = get_long("Digite o número de llamas: \n");
    }
    return n_llamas; // Retorna o valor atualizado
}

// Função para verificar o número final
long final(long n_llamas, long n_final)
{
    while (n_final < n_llamas)
    {
        printf("O número final %ld é menor que o número inicial %ld. Digite um número maior.\n", n_final, n_llamas);
        n_final = get_long("Digite o número final de llamas: \n");
    }
    return n_final; // Retorna o número final
}

// Função para adicionar llamas
long adicionar(long n_llamas)
{
    return n_llamas + (n_llamas / 3);
}

// Função para subtrair llamas
long subtrair(long n_llamas)
{
    return n_llamas - (n_llamas / 4);
}

// Função para calcular o número de anos necessários
int anos(long n_llamas, long n_final)
{
    int anos = 0; // Contador de anos

    while (n_llamas < n_final) // Continua enquanto o número inicial for menor que o final
    {
        n_llamas = adicionar(n_llamas); // Adiciona llamas
        //n_llamas = subtrair(n_llamas);  // Subtrai llamas
        anos++; // Incrementa o contador de anos
    }

    return anos; // Retorna o número de anos
}
