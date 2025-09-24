#include <stdio.h>

struct conta{
    int accountNum;
    char lastName [15];
    char name [15];
    float balance;
};
typedef struct conta Account;

int menu();
void textFile(FILE*);
void updateRecord(FILE*);
void newRecord(FILE*);

int main(){
    int op;
    FILE* file = fopen("file.txt", "rb+");
    if(file == NULL){
        printf("\nArquivo não pode ser aberto\n");
    }
    else{
        do{
            op = menu();
            switch(op){
                case 0: fclose(file); break;
                case 1: textFile(file); break;
                case 2: updateRecord(file); break;
                case 3: newRecord(file); break;
            }
        }while(op != 0);
    }
    return 0;
}

int menu(){
    int op;
    printf("\n\nSelecione o que quer fazer:\n0 - Sair do programa\n1 - Imprimir arquivo de texto\n2 - Atualizar registro\n3 - Adicionar registro\n4 - deletar registro\n\n");
    scanf("%d", &op);
    return op;
}

//txt vai se chamar contas.txt

void textFile(FILE* file){
    rewind(file);
    FILE* text = fopen("accounts.txt", "w");
    if(text == NULL){
        printf("\nArquivo não pôde ser aberto\n");
    }
    else{
        fprintf(text, "%-6s %-16s %-16s %-10s\n", "Conta", "Sobrenome", "Nome", "Saldo");
        while(!feof(file)){
            Account a = {0, "", "", 0};
            fread(&a, sizeof(Account), 1, file);
            if(a.accountNum == 0){
                printf("Arquivo vazio");
                break;
            }
            else{
                fprintf(text, "%-6d %-16s %-16s %10.2f\n", a.accountNum, a.lastName, a.name, a.balance);
            }
        }
    }
    fclose(text);
}

void updateRecord(FILE* file){
    int accountNum;
    float transaction;
    Account a;
    printf("\nDigite numero da conta a alterar:");
    scanf("%d", &accountNum);
    printf("\nDigite saldo atualizado da conta:");
    scanf("%f", &transaction);
    fseek(file, (accountNum - 1) * (sizeof(Account)), SEEK_CUR);
    fread(&a, sizeof(Account), 1, file);
    a.balance += transaction;
    printf("%-6d %-16s %-16s %-10.2f", a.accountNum, a.lastName, a.name, a.balance);
    fseek(file, (accountNum - 1) * (sizeof(Account)), SEEK_SET);
    fwrite(&a, sizeof(Account), 1, file);
}

/*void newRecord(FILE* file){
    int accountNum = 0;
    Account a;
    char nome[15], sobreNome[15];
    float saldo;
    printf("\nDigite nome, sobrenome e saldo inicial\n");
    scanf("%s %s %f", a.name, a.lastName, &a.balance);
    rewind(file);
    while(!feof(file)){
        fseek(file, sizeof(Account), SEEK_CUR);
        accountNum++;
    }
    a.accountNum = accountNum;
    fwrite(&a, sizeof(Account), 1, file);
}*/

void newRecord(FILE* file){
    Account a;
    char nome[15], sobreNome[15];
    float saldo;
    printf("\nDigite nome, sobrenome e saldo inicial\n");
    scanf("%s %s %f", a.name, a.lastName, &a.balance);
    fseek(file, sizeof(Account), SEEK_END);
    long fileSize = ftell(file);
    int accountNum = fileSize/sizeof(Account);
    a.accountNum = accountNum;
    fwrite(&a, sizeof(Account), 1, file);
}