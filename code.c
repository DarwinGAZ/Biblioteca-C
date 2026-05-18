#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int codigo;
    char titulo[100];
    int ano;
    int quantidade;
} Livro;

Livro biblioteca[MAX];
int total = 0;

void carregarLivros() {

    FILE *arq;

    arq = fopen("livros.txt", "r");

    if(arq == NULL) {
        printf("Arquivo nao encontrado!\n");
        return;
    }

    while(fscanf(arq, "%d %s %d %d",
           &biblioteca[total].codigo,
           biblioteca[total].titulo,
           &biblioteca[total].ano,
           &biblioteca[total].quantidade) == 4) {

        total++;
    }

    fclose(arq);
}

void listarLivros() {



    printf("\n===== LISTA DE LIVROS =====\n");

    for(int i = 0; i < total; i++) {

        printf("\nCodigo: %d", biblioteca[i].codigo);
        printf("\nTitulo: %s", biblioteca[i].titulo);
        printf("\nAno: %d", biblioteca[i].ano);
        printf("\nQuantidade: %d\n", biblioteca[i].quantidade);
    }
}

void adicionarLivro() {

    if(total >= MAX) {
        printf("Limite de livros atingido!\n");
        return;
    }

    printf("\nCodigo: ");
    scanf("%d", &biblioteca[total].codigo); 

    for (int i = 0; i <total; i++) {
        
        while (biblioteca[total].codigo == biblioteca[i].codigo) {
    
            printf("Esse codigo ja existe em outro livro, digite outro: ");
            scanf("%d", &biblioteca[total].codigo);

        }
    }

    

    printf("Titulo: ");
    scanf("%s", biblioteca[total].titulo);

    printf("Ano: ");
    scanf("%d", &biblioteca[total].ano);

    printf("Quantidade: ");
    scanf("%d", &biblioteca[total].quantidade);

    total++;

    printf("Livro adicionado com sucesso!\n");
}

void buscarLivro() {

    int codigo;


    printf("\nDigite o codigo do livro: ");
    scanf("%d", &codigo);

    for(int i = 0; i < total; i++) {

        if(biblioteca[i].codigo == codigo) {

            printf("\n===== LIVRO ENCONTRADO =====\n");

            printf("Codigo: %d\n", biblioteca[i].codigo);
            printf("Titulo: %s\n", biblioteca[i].titulo);
            printf("Ano: %d\n", biblioteca[i].ano);
            printf("Quantidade: %d\n", biblioteca[i].quantidade);

            return;
        }
    }

    printf("Livro nao encontrado!\n");
}

void ordenarPorAno() {

    Livro temp;

    for(int i = 0; i < total - 1; i++) {

        for(int j = i + 1; j < total; j++) {

            if(biblioteca[i].ano > biblioteca[j].ano) {

                temp = biblioteca[i];
                biblioteca[i] = biblioteca[j];
                biblioteca[j] = temp;
            }
        }
    }

    printf("Livros ordenados por ano!\n");
}

int main() {

    int opcao;

    carregarLivros();

    do {

        printf("\n===== SISTEMA DE LIVROS =====\n");

        printf("1 - Adicionar livro\n");
        printf("2 - Listar livros\n");
        printf("3 - Buscar livro\n");
        printf("4 - Ordenar por ano\n");
        printf("0 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                adicionarLivro();
                break;

            case 2:
                listarLivros();
                break;

            case 3:
                buscarLivro();
                break;

            case 4:
                ordenarPorAno();
                break;

            case 0:
                printf("Encerrando sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}