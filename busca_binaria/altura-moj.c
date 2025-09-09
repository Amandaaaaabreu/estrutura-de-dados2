#include <stdio.h>
#include <stdlib.h> 


// Considere uma árvore binária de busca definida por células

// typedef struct no {
//    int chave;
//    struct no *esq, *dir;
// } no;
// Sua tarefa nesse exercício é implementar uma função que retorne a altura de uma árvore binária de busca com raiz r. Para tanto, você deve submeter um arquivo contendo apenas:

// Os #include necessários para execução das instruções utilizadas no seu código.

// A definição da struct no.

// Uma função que retorna a altura 
// h
//  da árvore binária de busca. O protótipo desta função deve ser:

// int altura (no *r);


typedef struct no {
    int chave;
    struct no *esq, *dir; 
} no; 



int altura(no *r) {
    if(r == NULL){
        return 0; //arvore vazia
}

    int he = altura(r->esq);
    int hd = altura(r->dir);


    if(he>hd){
        return he +1;
    }else{
        return hd +1;
    }

}





