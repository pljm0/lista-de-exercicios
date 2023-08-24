#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titulo[100];
    char autor[100];
    int anoPublicacao;
} Livro;

void adicionarLivro(Livro livros[], int *totalLivros) {
    if (*totalLivros < 100) {
        printf("Digite o titulo: ");
        scanf("%s", livros[*totalLivros].titulo);
        printf("Digite o autor: ");
        scanf("%s", livros[*totalLivros].autor);
        printf("Digite o ano de publicacao: ");
        scanf("%d", &livros[*totalLivros].anoPublicacao);
        (*totalLivros)++;
        printf("Livro adicionado!\n");
    } else {
        printf("A lista de livros está cheia.\n");
    }
}

void listarLivros(const Livro livros[], int totalLivros) {
    printf("Lista de livros:\n");
    int i;
    for (i = 0; i < totalLivros; i++) {
        printf("Titulo: %s, Autor: %s, Ano de Publicacao: %d\n", livros[i].titulo, livros[i].autor, livros[i].anoPublicacao);
    }
}

void buscarLivroPorAutor(const Livro livros[], int totalLivros, const char autorBusca[]) {
    printf("Livros do autor %s:\n", autorBusca);
    int i;
    for (i = 0; i < totalLivros; i++) {
        if (strcmp(livros[i].autor, autorBusca) == 0) {
            printf("Titulo: %s, Ano de Publicacao: %d\n", livros[i].titulo, livros[i].anoPublicacao);
        }
    }
}

int main() {
    Livro livros[100];
    int totalLivros = 0;
    int opcao;

    do {
        printf("1 - Adicionar livro\n");
        printf("2 - Listar livros\n");
        printf("3 - Buscar livro por autor\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            adicionarLivro(livros, &totalLivros);
        } else if (opcao == 2) {
            listarLivros(livros, totalLivros);
        } else if (opcao == 3) {
            char autorBusca[100];
            printf("Digite o nome do autor a ser buscado: ");
            scanf("%s", autorBusca);
            buscarLivroPorAutor(livros, totalLivros, autorBusca);
        }
    } while (opcao != 4);

    return 0;
}

