#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char matricula[20];
    float notas[3];
} Estudante;

float calcularMedia(const Estudante* estudante) {
    return (estudante->notas[0] + estudante->notas[1] + estudante->notas[2]) / 3;
}

int estaAprovado(const Estudante* estudante) {
    float media = calcularMedia(estudante);
    return media >= 7.0 ? 1 : 0;
}

int main() {
    Estudante aluno;
    
    printf("Digite o nome do estudante: ");
    scanf("%s", aluno.nome);
    
    printf("Digite a matricula do estudante: ");
    scanf("%s", aluno.matricula);
    
    printf("Digite as notas das tres disciplinas: ");
    scanf("%f %f %f", &aluno.notas[0], &aluno.notas[1], &aluno.notas[2]);
    
    printf("Media das notas: %.2f\n", calcularMedia(&aluno));
    
    if (estaAprovado(&aluno)) {
        printf("O aluno esta aprovado.\n");
    } else {
        printf("O aluno nao esta aprovado.\n");
    }

    return 0;
}

