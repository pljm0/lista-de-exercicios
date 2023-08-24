#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;
    float altura;
} Pessoa;

int main() {
    Pessoa pessoa;
    
    strcpy(pessoa.nome, "Augusto");
    pessoa.idade = 25;
    pessoa.altura = 1.75;

    printf("Nome: %s\n", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);
    printf("Altura: %.2f\n", pessoa.altura);

    return 0;
}

