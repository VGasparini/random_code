/* Curso C++
 * Vinicius Gasparini
 * Exericio 1
*/

#include <stdio.h>
#include <math.h>
#define MAX_SIZE 2

typedef struct struct_pessoa
{
    char nome[60];
    unsigned long cpf;
    unsigned short idade;
} Pessoa;

char valida_cpf(unsigned long cpf)
{
    // Ref: https://www.calculadorafacil.com.br/computacao/validar-cpf
    unsigned long cpf_copy;
    int i, n;
    unsigned short verificador1 = 0, verificador2 = 0;

    unsigned short zeros = 11 - log10(cpf); // Lidando com zeros a esquerda

    for (i = 1 + zeros, n = 11, cpf_copy = cpf; i <= n - 2; i++)
    {
        unsigned long potencia_10 = pow(10, n - i);
        verificador1 += cpf_copy / potencia_10 * i;
        cpf_copy %= potencia_10;
    }
    verificador1 = (verificador1 % 11) % 10;

    for (i = 0 + zeros, n = 11, cpf_copy = cpf; i <= n - 3; i++)
    {
        unsigned long potencia_10 = pow(10, n - i - 1);
        verificador2 += cpf_copy / potencia_10 * i;
        cpf_copy %= potencia_10;
    }
    verificador2 += verificador1 * 9;
    verificador2 = (verificador2 % 11) % 10;

    if ((cpf % 100 / 10) == verificador1 && cpf % 10 == verificador2)
        return 1;
    return 0;
}

int main()
{
    int i;
    Pessoa pessoas[MAX_SIZE];
    for (i = 0; i < MAX_SIZE; i++)
    {
        char *nome;
        unsigned long cpf;
        unsigned short idade;
        printf("\n--== Pessoa %2d ==--\n", i + 1);
        printf("Digite o nome ->");
        scanf("%s", pessoas[i].nome);
        printf("Digite o CPF ->");
        scanf("%lu", &cpf);
        while (!valida_cpf(cpf))
        {
            printf("CPF invalido! Digite novamente ->");
            scanf("%lu", &cpf);
        }
        printf("Digite a idade ->");
        scanf("%hu", &pessoas[i].idade);
        pessoas[i].cpf = cpf;
    }
    printf("\n================================\n");
    for (i = 0; i < MAX_SIZE; i++)
        printf("\n--== Pessoa %2d ==--\n", i + 1),
            printf("Nome: %s\nCPF: %lu\nIdade: %hu\n", pessoas[i].nome, pessoas[i].cpf, pessoas[i].idade);
    return 0;
}