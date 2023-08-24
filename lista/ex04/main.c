#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char telefone[20];
} Contato;

void adicionarContato(Contato agenda[], int *totalContatos) {
    if (*totalContatos < 100) {
        printf("Digite o nome: ");
        scanf("%s", agenda[*totalContatos].nome);
        printf("Digite o telefone: ");
        scanf("%s", agenda[*totalContatos].telefone);
        (*totalContatos)++;
        printf("Contato adicionado!\n");
    } else {
        printf("A agenda esta cheia.\n");
    }
}

void listarContatos(const Contato agenda[], int totalContatos) {
    printf("Lista de contatos:\n");
    int i;
    for (i = 0; i < totalContatos; i++) {
        printf("Nome: %s, Telefone: %s\n", agenda[i].nome, agenda[i].telefone);
    }
}

void buscarContato(const Contato agenda[], int totalContatos, const char nomeBusca[]) {
    int encontrado = 0;
    int i;
    for (i = 0; i < totalContatos; i++) {
        int j = 0;
        while (agenda[i].nome[j] != '\0' && nomeBusca[j] != '\0' && agenda[i].nome[j] == nomeBusca[j]) {
            j++;
        }
        if (agenda[i].nome[j] == '\0' && nomeBusca[j] == '\0') {
            printf("Nome: %s, Telefone: %s\n", agenda[i].nome, agenda[i].telefone);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Contato nao encontrado.\n");
    }
}

int main() {
    Contato agenda[100];
    int totalContatos = 0;
    int opcao;

    do {
        printf("1 - Adicionar contato\n");
        printf("2 - Listar contatos\n");
        printf("3 - Buscar contato\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            adicionarContato(agenda, &totalContatos);
        } else if (opcao == 2) {
            listarContatos(agenda, totalContatos);
        } else if (opcao == 3) {
            char nomeBusca[100];
            printf("Digite o nome a ser buscado: ");
            scanf("%s", nomeBusca);
            buscarContato(agenda, totalContatos, nomeBusca);
        }
    } while (opcao != 4);

    return 0;
}


