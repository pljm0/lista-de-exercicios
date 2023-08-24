#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    float preco;
    int quantidadeEstoque;
} Produto;

void comprarProduto(Produto* produto, int quantidade) {
    if (quantidade <= produto->quantidadeEstoque) {
        float totalCompra = quantidade * produto->preco;
        produto->quantidadeEstoque -= quantidade;
        printf("Compra realizada com sucesso. Total da compra: %.2f\n", totalCompra);
    } else {
        printf("Estoque insuficiente.\n");
    }
}

int main() {
    Produto produto;
    
    printf("Digite o nome do produto: ");
    scanf("%s", produto.nome);
    
    printf("Digite o preco do produto: ");
    scanf("%f", &produto.preco);
    
    printf("Digite a quantidade em estoque do produto: ");
    scanf("%d", &produto.quantidadeEstoque);
    
    int opcao;
    do {
        printf("1 - Comprar produto\n");
        printf("2 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int quantidade;
            printf("Digite a quantidade a comprar: ");
            scanf("%d", &quantidade);
            comprarProduto(&produto, quantidade);
        }
    } while (opcao != 2);

    return 0;
}

