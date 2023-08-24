#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char cargo[100];
    float salario;
    int diaAdmissao;
    int mesAdmissao;
    int anoAdmissao;
} Funcionario;

void darAumentoSalario(Funcionario* funcionario, float aumento) {
    funcionario->salario += aumento;
    printf("Aumento de salario aplicado. Novo salario: %.2f\n", funcionario->salario);
}

int calcularTempoNaEmpresa(const Funcionario* funcionario, int diaAtual, int mesAtual, int anoAtual) {
    int anos = anoAtual - funcionario->anoAdmissao;
    int meses = mesAtual - funcionario->mesAdmissao;
    
    if (meses < 0) {
        anos--;
        meses += 12;
    }
    
    return anos;
}

int main() {
    Funcionario funcionario;
    
    printf("Digite o nome do funcionario: ");
    scanf("%s", funcionario.nome);
    
    printf("Digite o cargo do funcionario: ");
    scanf("%s", funcionario.cargo);
    
    printf("Digite o salario do funcionario: ");
    scanf("%f", &funcionario.salario);
    
    printf("Digite a data de admissao (dia mes ano): ");
    scanf("%d %d %d", &funcionario.diaAdmissao, &funcionario.mesAdmissao, &funcionario.anoAdmissao);

    int diaAtual, mesAtual, anoAtual;
    printf("Digite a data atual (dia mes ano): ");
    scanf("%d %d %d", &diaAtual, &mesAtual, &anoAtual);

    int opcao;
    do {
        printf("1 - Dar aumento de salario\n");
        printf("2 - Calcular tempo na empresa\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            float aumento;
            printf("Digite o valor do aumento: ");
            scanf("%f", &aumento);
            darAumentoSalario(&funcionario, aumento);
        } else if (opcao == 2) {
            int tempo = calcularTempoNaEmpresa(&funcionario, diaAtual, mesAtual, anoAtual);
            printf("Tempo na empresa: %d anos\n", tempo);
        }
    } while (opcao != 3);

    return 0;
}


