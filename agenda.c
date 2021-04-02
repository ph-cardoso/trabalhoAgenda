#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

int cont = 0;

typedef struct
{
    char nome[35];
    char telefone[15];
    char celular[15];
    char email[40];
    //int index;
} Agenda;

void clean_stdin()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//TODO: Validação de S/N maiúscula ou minúscula e validação de caractere inválido
int inserirContato(Agenda ag[], int i)
{
    system("cls");
    char choice = 'S';

    while(choice == 'S' || choice == 's'){
        printf("Insira o nome do contato: \n");
        clean_stdin();
        scanf("%[^\n]", ag[i].nome);
        //fgets(ag[i].nome, 35, stdin);
        printf("Insira o telefone do contato: \n");
        clean_stdin();
        scanf("%[^\n]", ag[i].telefone);
        //fgets(ag[i].telefone, 15, stdin);
        printf("Insira o celular do contato: \n");
        clean_stdin();
        scanf("%[^\n]", ag[i].celular);
        //fgets(ag[i].celular, 15, stdin);
        printf("Insira o e-mail do contato: \n");
        clean_stdin();
        scanf("%[^\n]", ag[i].email);
        //fgets(ag[i].email, 40, stdin);
        
        cont++;
        i++;

        printf("\n\nCadastrar um novo contato? S/N");
        clean_stdin();
        scanf("%c", &choice);
    }
    return i;
}

//TODO: Alterar a variável global 'cont'
void exibirContatos(Agenda ag[])
{
    system("cls");
    int i = 0;
    printf("SEUS CONTATOS\n\n\n");
    while(i<cont){
        printf("Nome: %s\n", ag[i].nome);
        printf("Telefone: %s\n", ag[i].telefone);
        printf("Celular: %s\n", ag[i].celular);
        printf("E-mail: %s\n\n", ag[i].email);
        i++;
    }
    
    clean_stdin();
    getchar();
}