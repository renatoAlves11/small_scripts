#include <stdio.h>
#include <stdlib.h>
struct node{
    int value;
    struct node * left, * right;
};
typedef struct node node;
typedef struct node* nodePtr;

void insert (nodePtr* p, int x);
void list (nodePtr p);
int search (nodePtr p, int x);
int empty (nodePtr p);
void delete (nodePtr *p, int x);
nodePtr major (nodePtr p);

int main(){
    int x, y, op, searchResult;
    nodePtr root = NULL;
    do{
        printf("O que quer fazer?\n");
        scanf("%d", &op);
    switch(op){
        case 1: 
        printf("\nQual o numero a ser inserido?\n");
        scanf("%d", &x);
        insert(&root, x); break;
        case 2:
        list(root);
        break;
        case 3:
        printf("\nQual elemento quer procurar?\n");
        scanf("%d", &y);
        searchResult = search(root, y);
        if (searchResult==1)
        printf("\nElemento está na lista\n");
        else
        printf("\nElemento não está na lista\n");
    break;
        case 4:
        major(root->left);
    };} while(op!=0);
    return 0;
}

void insert (nodePtr* p, int x){
    if (*p == NULL){
    *p = (nodePtr)malloc(sizeof(node));
    (*p)->left = NULL;
    (*p)->right = NULL;
    (*p)->value = x;}
    else{
        if(x<(*p)->value)
        insert (&((*p)->left), x);
        else
        insert (&((*p)->right), x);
    }

}

void list(nodePtr p){
    if (p!=NULL){
        list (p->left);
        printf("%d\t", p->value);
        list(p->right);
    }
}

int search (nodePtr p, int x){
    int result = 0;
    if((p==NULL))
    printf("\nElemento não está na arvore\n");
    else{
        if(p->value == x){
        printf("\n%d está na árvore\n", x);
        result = 1;
        return result;
        }
        if(x<p->value)
        search(p->left, x);
        if(x>p->value)
        search(p->right, x);
    }
    return result;
}

nodePtr major (nodePtr p){
    if (p->right!=NULL)
    p = major(p->right);
    printf("%d", p->value);
    return p;
}

void delete (nodePtr *p, int x){
    nodePtr aux;
    if (aux!=NULL){
        if(aux->value==x){
            *p = major((*p)->left);
        }
    }
}