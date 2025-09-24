#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node * right;
    struct node * left;
};

typedef struct node * noPtr;
typedef struct node Node;

int menu();
int empty(noPtr);
void insert(noPtr*, int);
void list(noPtr);
noPtr searchMinor(noPtr*);
noPtr findNode(noPtr, int);
void out(noPtr*, int);

int main (){
    int op, num;
    noPtr root = NULL;
    do {
        printf("\nO que você quer fazer?\n");
        op = menu();
        switch(op){
            case 1: 
            printf("\nQue numero deseja inserir?\n");
            scanf("%d", &num);
            insert (&root, num); break;
            case 2: 
            if(empty(root)==1) 
            printf("Árvore vazia\n");
            else{
            printf("\nQual o nó a ser removido?\n");
            scanf("%d", &num);
            out (&root, num); break;}
            case 3: 
            if(empty(root)==1) 
            printf("\nÁrvore vazia\n");
            else
            list(root); break;
            //case 4: search(); break;
        }
    }while (op!=0);
    return 0;
}

int menu (){
    int x;
    printf("\n(0)Encerrar\n(1)Inserir\n(2)outr\n(3)Listar\n(4)Buscar\n");
    scanf("%d", &x);
    return x;
}

int empty (noPtr root){
    if (root == NULL){
        return 1;
    }
    else return 0;
}

noPtr searchMinor (noPtr *root){
    noPtr t = *root;
    if((*root)->left == NULL){
    *root = (*root)->right;
    return t;}
    else{
    return searchMinor(&(*root)->left);
    }
}

void insert(noPtr* root, int num){
    noPtr p = (noPtr)malloc(sizeof(Node));
    p->value = num;
    p->right=NULL;
    p->left=NULL;
    if (*root == NULL){
        *root = p;
    }
    else{
        if (num > (*root)->value){
            insert(&(*root)->right, num);
        }
        if (num < (*root)->value){
            insert(&(*root)->left, num);
        }
    }
}

void list(noPtr root){
    if(root != NULL){
    list(root->left);
    printf("\n%d\t", root->value);
    list(root->right);
    }
}

noPtr findNode (noPtr root, int num){
    noPtr p = NULL;
    if (root == NULL)
    printf("\nelemento não se encontra na lista\n");
    else if (root->value == num)
    return root;
    else{
    if (root->value > num){
        p = findNode(root->right, num);
    }
    else{
    p = findNode(root->left, num);
    }
}
return p;
}

void out(noPtr* root, int num){
    noPtr aux;
    if (*root == NULL){
        printf("Elemento não está na lista");
    }
    else if ((*root)->value == num){
        aux = *root;
        if ((*root)->right == NULL)
        *root = (*root)->left;
    else if ((*root)->left == NULL)
        *root = (*root)->right;
    else{
        aux = searchMinor (&((*root)->right));
        (*root)->value = aux->value;
    }
    free(aux);
    printf("\nO elemento foi removido\n");
    }
    else {
        if ((*root)->value > num)
        out(&((*root)->left), num);
        else
        out(&((*root)->right), num);
    }
}