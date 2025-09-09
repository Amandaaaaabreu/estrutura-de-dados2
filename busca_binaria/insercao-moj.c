#include <stdio.h> 
#include<stdlib.h> 


// Considere uma árvore binária de busca definida por células

// typedef struct no {
//    int chave;
//    struct no *esq, *dir;
// } no;
// Sua tarefa nesse exercício é implementar a operação de inserção na numa árvore binária de busca com raiz r. Para tanto, você deve submeter um arquivo contendo apenas:

// Os #include necessários para execução das instruções utilizadas no seu código.

// A definição da struct no.

// Uma função que insere o valor 
// x
//  na árvore binária de busca. O protótipo desta função deve ser:

// no *inserir (no *r, int x);
// Sua função de inserção deve garantir que chaves repetidas não sejam inseridas na árvore.


typedef struct no {
    int chave; 
    struct no *esq, *dir; 
}no; 


no *inserir(no *r, int x){   //caso baase - arvore vazia
    if(r == NULL){
        no *novo = (no *)malloc(sizeof(no));
        novo->chave = x; 
        novo->esq = novo->dir = NULL; 
        return novo; 
    }

    if(x < r->chave){  //decidindo onde inserir o valor 
        r->esq = inserir(r->esq, x); 
    } else if (x > r->chave){
        r->dir = inserir (r->dir, x);
    }

    return r; 

}