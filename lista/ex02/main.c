#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valorInt;
    float valorFloat;
    char letra;
} Tipo;

int main() {
    Tipo meuTipo;
    
    meuTipo.valorInt = 10;
    meuTipo.valorFloat = 3.14;
    meuTipo.letra = 'A';

    printf("Valor Inteiro: %d\n", meuTipo.valorInt);
    printf("Valor Float: %.2f\n", meuTipo.valorFloat);
    printf("Letra: %c\n", meuTipo.letra);

    return 0;
}

