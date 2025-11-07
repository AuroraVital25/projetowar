#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

// --- Constantes Globais ---
#define MAX_LIVROS 50
#define TAM_STRING 100

// --- Definição da Estrutura (Struct) ---
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

// --- Função para limpar o buffer de entrada ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Livro biblioteca[MAX_LIVROS];
    int qtdLivros = 0;

    printf("==== Sistema de Cadastro de Livros ====\n\n");

    printf("Quantos livros deseja cadastrar? ");
    scanf("%d", &qtdLivros);
    limparBufferEntrada(); // Limpa o buffer do scanf

    if (qtdLivros > MAX_LIVROS) {
        printf("Limite máximo de %d livros excedido!\n", MAX_LIVROS);
        return 1;
    }

    // --- Cadastro dos Livros ---
    for (int i = 0; i < qtdLivros; i++) {
        printf("\n--- Cadastro do Livro %d ---\n", i + 1);

        printf("Nome: ");
        fgets(biblioteca[i].nome, TAM_STRING, stdin);
        biblioteca[i].nome[strcspn(biblioteca[i].nome, "\n")] = '\0';

        printf("Autor: ");
        fgets(biblioteca[i].autor, TAM_STRING, stdin);
        biblioteca[i].autor[strcspn(biblioteca[i].autor, "\n")] = '\0';

        printf("Editora: ");
        fgets(biblioteca[i].editora, TAM_STRING, stdin);
        biblioteca[i].editora[strcspn(biblioteca[i].editora, "\n")] = '\0';

        printf("Edição: ");
        scanf("%d", &biblioteca[i].edicao);
        limparBufferEntrada();
    }

    // --- Exibição dos Livros Cadastrados ---
    printf("\n===== Livros Cadastrados =====\n");
    for (int i = 0; i < qtdLivros; i++) {
        printf("\nLivro %d:\n", i + 1);
        printf("Nome: %s\n", biblioteca[i].nome);
        printf("Autor: %s\n", biblioteca[i].autor);
        printf("Editora: %s\n", biblioteca[i].editora);
        printf("Edição: %d\n", biblioteca[i].edicao);
    }

    printf("\nCadastro concluído com sucesso!\n");

    return 0;
}
