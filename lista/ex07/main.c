#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nomeTitular[100];
    char numeroConta[20];
    float saldo;
} ContaBancaria;

void depositar(ContaBancaria* conta, float valor) {
    conta->saldo += valor;
    printf("Deposito realizado com sucesso. Saldo atual: %.2f\n", conta->saldo);
}

void sacar(ContaBancaria* conta, float valor) {
    if (valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque realizado com sucesso. Saldo atual: %.2f\n", conta->saldo);
    } else {
        printf("Saldo insuficiente para saque.\n");
    }
}

void verificarSaldo(const ContaBancaria* conta) {
    printf("Saldo atual: %.2f\n", conta->saldo);
}

int main() {
    ContaBancaria conta;
    
    printf("Digite o nome do titular da conta: ");
    scanf("%s", conta.nomeTitular);
    
    printf("Digite o numero da conta: ");
    scanf("%s", conta.numeroConta);
    
    conta.saldo = 0.0;
    
    int opcao;
    do {
        printf("1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Verificar saldo\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            float valor;
            printf("Digite o valor a depositar: ");
            scanf("%f", &valor);
            depositar(&conta, valor);
        } else if (opcao == 2) {
            float valor;
            printf("Digite o valor a sacar: ");
            scanf("%f", &valor);
            sacar(&conta, valor);
        } else if (opcao == 3) {
            verificarSaldo(&conta);
        }
    } while (opcao != 4);

    return 0;
}

