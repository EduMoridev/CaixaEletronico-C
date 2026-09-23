#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída, que contém printf e scanf

#define SALDO 1000 // Define a constante SALDO com o valor disponível na conta

int main(void) { // Início da função principal, onde o programa começa a ser executado
    int saque, resto; // Declara as variáveis do valor do saque e do valor que ainda falta distribuir
    int n100, n50, n20, n10, n5; // Declara as variáveis que guardam a quantidade de cada nota

    printf("Saldo disponivel: R$ %d\n", SALDO); // Mostra na tela o saldo disponível
    printf("Digite o valor do saque: "); // Pede ao usuário que digite o valor do saque

    if (scanf("%d", &saque) != 1) { // Lê o valor digitado e verifica se a leitura falhou (ex.: letras)
        printf("Entrada invalida.\n"); // Avisa que o valor digitado não é um número válido
        return 1; // Encerra o programa indicando que houve erro
    } // Fim da verificação da leitura

    if (saque <= 0) { // Verifica se o valor do saque é zero ou negativo
        printf("Valor invalido.\n"); // Avisa que o valor não pode ser sacado
    } else if (saque > SALDO) { // Caso contrário, verifica se o saque é maior que o saldo
        printf("Saldo insuficiente.\n"); // Avisa que não há saldo suficiente
    } else if (saque % 5 != 0) { // Caso contrário, verifica se o valor não é múltiplo de 5
        printf("O valor precisa ser multiplo de 5.\n"); // Avisa que o valor não pode ser pago com as notas
    } else { // Se passou em todas as validações, o saque é realizado
        resto = saque; // Copia o valor do saque para a variável que será reduzida a cada nota

        n100 = resto / 100; // Calcula quantas notas de 100 cabem no valor
        resto = resto % 100; // Guarda o que sobrou depois de usar as notas de 100

        n50 = resto / 50; // Calcula quantas notas de 50 cabem no que sobrou
        resto = resto % 50; // Guarda o que sobrou depois de usar as notas de 50

        n20 = resto / 20; // Calcula quantas notas de 20 cabem no que sobrou
        resto = resto % 20; // Guarda o que sobrou depois de usar as notas de 20

        n10 = resto / 10; // Calcula quantas notas de 10 cabem no que sobrou
        resto = resto % 10; // Guarda o que sobrou depois de usar as notas de 10

        n5 = resto / 5; // Calcula quantas notas de 5 cabem no que sobrou
        resto = resto % 5; // Guarda o que sobrou, que sempre será 0 pois o valor é múltiplo de 5

        printf("\nNotas entregues:\n"); // Mostra o título da lista de notas
        if (n100 > 0) printf("%d nota(s) de R$ 100\n", n100); // Mostra as notas de 100, se houver
        if (n50  > 0) printf("%d nota(s) de R$ 50\n",  n50); // Mostra as notas de 50, se houver
        if (n20  > 0) printf("%d nota(s) de R$ 20\n",  n20); // Mostra as notas de 20, se houver
        if (n10  > 0) printf("%d nota(s) de R$ 10\n",  n10); // Mostra as notas de 10, se houver
        if (n5   > 0) printf("%d nota(s) de R$ 5\n",   n5); // Mostra as notas de 5, se houver

        printf("\nSaldo restante: R$ %d\n", SALDO - saque); // Mostra quanto sobraria do saldo após o saque
    } // Fim do bloco de validações e cálculo

    return 0; // Encerra o programa indicando que tudo ocorreu bem
} // Fim da função principal
