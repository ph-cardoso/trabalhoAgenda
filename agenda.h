#define MAX 100 //Limite de contatos da Agenda

struct Contato
{
    char nome[35];
    char telefone[15];
    char celular[15];
    char email[40];
};

typedef struct lista Lista;

void clean_stdin();                                                      //Limpa o buffer do teclado

//Manipulação da lista estática
Lista* cria_lista();                                                     //Cria a lista estática
void libera_lista(Lista *li);                                            //Libera a lista estática
int lista_cheia(Lista *li);                                              //Checa se a lista está cheia
int lista_vazia(Lista *li);                                              //Checa se a lista está vazia
int insere_lista(Lista *li, struct Contato contato);                     //Insere no final da lista
int remove_lista(Lista *li, char name[]);                                //Remove da lista de acordo com o nome


//Operações da Agenda MENU
void insereContato(Lista *li);                                           //Insere contatos na lista
void excluiContato(Lista *li);                                           //Exclui um contato na lista
void exibirContatos(Lista *li);                                          //Exibe todos os contatos
void alterarContato(Lista *li);                                          //Altera telefone,celular e e-mail de um contato
void pesquisarContato(Lista *li);                                        //Pesquisa um contato por nome
void estadoAgenda(Lista *li);                                            //Exibe o estado da agenda