#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

//Declara a lista estática
struct lista
{
    int qtd;
    struct Contato ct[MAX];
};

//Limpa o buffer do teclado
void clean_stdin()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Cria a lista estática
Lista* cria_lista()
{
    Lista *li;
    li = (Lista *)malloc(sizeof(Lista));
    if (li != NULL)
        li->qtd = 0;
    return li;
}

//Libera a lista estática
void libera_lista(Lista *li)
{
    free(li);
}

//Checa se a lista está cheia
int lista_cheia(Lista *li)
{
    if (li == NULL)
        return -1;
    return (li->qtd == MAX); //Retorna 1 se verdadeiro e 0 se falso
}

//Checa se a lista está vazia
int lista_vazia(Lista *li)
{
    if (li == NULL)
        return -1;
    return (li->qtd == 0); //Retorna 1 se verdadeiro e 0 se falso
}

//Insere no final da lista
int insere_lista(Lista *li, struct Contato contato)
{
    if (li == NULL)
        return -1;
    if (lista_cheia(li)) //Checa se a lista está cheia
        return 0;
    
    li->ct[li->qtd] = contato;
    li->qtd++;
    return 1;
}

//Remove da lista de acordo com o nome
int remove_lista(Lista *li, char name[])
{
    int k, i = 0;
    if (li == NULL)
        return -1;
    if (lista_vazia(li)) //Checa se a lista está vazia
        return 0;
    //Realiza uma busca ao elemento que tem nome correspondente ao parâmetro
    //strcmp -> Compara strings
    while ((i < li->qtd) && (strcmp(li->ct[i].nome, name)))
        i++;

    if (i == li->qtd) //Nome não encontrado na base de dados
        return 2;
    //Move os elementos à direita do excluído 1 casa à esquerda
    for (k = i; k < li->qtd - 1; k++)
        li->ct[k] = li->ct[k + 1];
    
    li->qtd--;
    return 1;
}

//Pega as informações de contato e o insere na lista
void insereContato(Lista *li)
{
    system("cls");
    char choice = 's';
    struct Contato contato;
    int x;

    while((choice == 'S') || (choice == 's')){
        system("cls");
        printf("\n"); 
        printf("||--------------------------------------------------------------|| \n");
        printf("||------------------- Cadastro de Contatos ---------------------|| \n");
        printf("||--------------------------------------------------------------|| \n\n"); 
        printf("Insira o nome do contato: \n");
        clean_stdin();
        scanf("%[^\n]", contato.nome);
        printf("Insira o telefone do contato: \n");
        clean_stdin();
        scanf("%[^\n]", contato.telefone);
        printf("Insira o celular do contato: \n");
        clean_stdin();
        scanf("%[^\n]", contato.celular);
        printf("Insira o e-mail do contato: \n");
        clean_stdin();
        scanf("%[^\n]", contato.email);
        
        x = insere_lista(li,contato);
        if(x==1)
            printf("\n\nContato cadastrado com sucesso!");
        else if(x==0)
            printf("\n\nLista cheia!");
        else
            printf("\n\nErro ao cadastrar o contato!");

        printf("\n\nCadastrar um novo contato? S/N\n");
        clean_stdin();
        scanf("%c", &choice);
    }
}

//Exclui um contato da lista pelo nome
void excluiContato(Lista *li)
{
    system("cls");
    char choice = 's';
    char exclui[35];
    int x;

    while((choice == 'S') || (choice == 's')){
        system("cls");
        printf("\n");
        printf("||--------------------------------------------------------------|| \n");
        printf("||------------------- Exclusao de Contatos ---------------------|| \n");
        printf("||--------------------------------------------------------------|| \n\n");
        printf("Insira o nome do contato a ser excluido: \n");
        clean_stdin();
        scanf("%[^\n]", exclui);
        
        x = remove_lista(li, exclui);
        if(x==1)
            printf("\n\nContato excluido com sucesso!");
        else if(x==2)
            printf("\n\nNome nao encontrado na base de dados!");
        else if(x==0)
            printf("\n\nLista vazia!");
        else
            printf("\n\nErro ao excluir o contato!");

        printf("\n\nExcluir outro contato? S/N\n");
        clean_stdin();
        scanf("%c", &choice);
    }
}

//Exibe todos os contatos
void exibirContatos(Lista *li)
{
    system("cls");
    int i;

    if(lista_vazia(li)){
        printf("\n"); 
        printf("||--------------------------------------------------------------||\n");
        printf("||------------------- Lista de Contatos ------------------------||\n");
        printf("||--------------------------------------------------------------||\n\n");
        puts("LISTA VAZIA!");
    }
    else{
        printf("\n"); 
        printf("||--------------------------------------------------------------||\n");
        printf("||------------------- Lista de Contatos ------------------------||\n");
        printf("||--------------------------------------------------------------||\n\n");
        for(i=0; i<li->qtd; i++){
            printf("Nome: %s\n", li->ct[i].nome);
            printf("Telefone: %s\n", li->ct[i].telefone);
            printf("Celular: %s\n", li->ct[i].celular);
            printf("E-mail: %s\n\n", li->ct[i].email);
        }
    }

    clean_stdin();
    getchar();
}

//Altera telefone,celular e e-mail de um contato
void alterarContato(Lista *li){
    system("cls");
    char choice = 's';
    char altera[35];
    int i;

    while((choice == 'S') || (choice == 's')){
        system("cls");
        i = 0;
        printf("\n");
        printf("||--------------------------------------------------------------|| \n");
        printf("||------------------- Alteracao de Contatos --------------------|| \n");
        printf("||--------------------------------------------------------------|| \n\n");
        printf("Insira o nome do contato a ser alterado: \n");
        clean_stdin();
        scanf("%[^\n]", altera);
        //Realiza uma busca ao elemento que tem nome correspondente ao parâmetro
        while ((i < li->qtd) && (strcmp(li->ct[i].nome, altera)))
            i++;
        if (i == li->qtd) //Elemento não encontrado na base de dados
            printf("\n\nNome nao encontrado na base de dados!");
        else{
            //Altera os dados do contato
            printf("\nNOME DO CONTATO: %s\n\n", li->ct[i].nome);
            printf("Insira o novo telefone: \n");
            clean_stdin();
            scanf("%[^\n]", li->ct[i].telefone);
            printf("Insira o novo celular: \n");
            clean_stdin();
            scanf("%[^\n]", li->ct[i].celular);
            printf("Insira o novo e-mail: \n");
            clean_stdin();
            scanf("%[^\n]", li->ct[i].email);
            printf("\n\nContato alterado com sucesso!");
        }

        printf("\n\nAlterar outro contato? S/N\n");
        clean_stdin();
        scanf("%c", &choice);
    }
}

//Pesquisa um contato por nome e imprime na tela
void pesquisarContato(Lista *li){
    system("cls");
    char choice = 's';
    char pesquisa[35];
    int i;

    while((choice == 'S') || (choice == 's')){
        system("cls");
        i = 0;
        printf("\n");
        printf("||--------------------------------------------------------------|| \n");
        printf("||--------------------- Pesquisar Contatos ---------------------|| \n");
        printf("||--------------------------------------------------------------|| \n\n");
        printf("Insira o nome do contato a ser pesquisado: \n");
        clean_stdin();
        scanf("%[^\n]", pesquisa);
        system("cls");
        //Realiza uma busca ao elemento que tem nome correspondente ao parâmetro
        while ((i < li->qtd) && (strcmp(li->ct[i].nome, pesquisa)))
            i++;
        if (i == li->qtd) //Elemento não encontrado na base de dados
            printf("\n\nNome nao encontrado na base de dados!");
        else{
            //Imprime os dados do contato
            printf("Nome: %s\n", li->ct[i].nome);
            printf("Telefone: %s\n", li->ct[i].telefone);
            printf("Celular: %s\n", li->ct[i].celular);
            printf("E-mail: %s\n\n", li->ct[i].email);
        }

        printf("\n\nPesquisar outro contato? S/N\n");
        clean_stdin();
        scanf("%c", &choice);
    }
}

//Exibe o estado da agenda
void estadoAgenda(Lista *li){
    system("cls");
    printf("\n");
    printf("||--------------------------------------------------------------|| \n");
    printf("||--------------------- Status da Agenda -----------------------|| \n");
    printf("||--------------------------------------------------------------|| \n\n");
    printf("Limite de cadastros: %d\n", MAX);
    printf("Contatos cadastrados: %d\n", li->qtd);

    clean_stdin();
    getchar();
}