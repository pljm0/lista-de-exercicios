#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float valorDolar;
    float valorEuro;
} Moeda;

void converterDolarParaEuro(const Moeda* moeda, float valorDolar) {
    float valorEuro = valorDolar * moeda->valorDolar / moeda->valorEuro;
    printf("%.2f dolares equivalem a %.2f euros.\n", valorDolar, valorEuro);
}

void converterEuroParaDolar(const Moeda* moeda, float valorEuro) {
    float valorDolar = valorEuro * moeda->valorEuro / moeda->valorDolar;
    printf("%.2f euros equivalem a %.2f dolares.\n", valorEuro, valorDolar);
}

int main() {
    Moeda moeda;
    
    printf("Digite o valor atual de 1 dolar em reais: ");
    scanf("%f", &moeda.valorDolar);

    printf("Digite o valor atual de 1 euro em reais: ");
    scanf("%f", &moeda.valorEuro);
    
    int opcao;
    do {
        printf("1 - Converter dolar para euro\n");
        printf("2 - Converter euro para dolar\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            float valorDolar;
            printf("Digite o valor em dolares: ");
            scanf("%f", &valorDolar);
            converterDolarParaEuro(&moeda, valorDolar);
        } else if (opcao == 2) {
            float valorEuro;
            printf("Digite o valor em euros: ");
            scanf("%f", &valorEuro);
            converterEuroParaDolar(&moeda, valorEuro);
        }
    } while (opcao != 3);

    return 0;
}

