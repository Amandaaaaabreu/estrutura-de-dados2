#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

// Função para inserir valores na árvore (BST)
no *inserir(no *r, int x) {
    if (r == NULL) {
        no *novo = (no *)malloc(sizeof(no));
        novo->chave = x;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (x < r->chave) {
        r->esq = inserir(r->esq, x);
    } else if (x > r->chave) {
        r->dir = inserir(r->dir, x);
    }
    return r; // se x == r->chave, não insere duplicata
}

// Função que retorna a altura da árvore
int altura(no *r) {
    if (r == NULL) {
        return -1; // altura de árvore vazia é -1
    }
    int h_esq = altura(r->esq);
    int h_dir = altura(r->dir);
    return (h_esq > h_dir ? h_esq : h_dir) + 1;
}

// Função para imprimir a árvore em ordem 
void imprimirInOrder(no *r) {
    if (r != NULL) {
        imprimirInOrder(r->esq);
        printf("%d ", r->chave);
        imprimirInOrder(r->dir);
    }
}

int main() {
    no *raiz = NULL;

    // Inserindo alguns valores de teste
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 18);

    printf("Árvore em ordem (in-order): ");
    imprimirInOrder(raiz);
    printf("\n");

    int h = altura(raiz);
    printf("Altura da árvore: %d\n", h);

    return 0;
}
