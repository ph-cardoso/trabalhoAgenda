#include <stdio.h>
#include <stdlib.h>
#include "agenda.c"

int main()
{
    int n;
    Lista *li = cria_lista();

    do
    {
        //MENU
        system("cls");
        printf("MENU\n\n");
        printf("1. Inserir Contato\n");
        printf("2. Excluir Contato\n");
        printf("3. Alterar Contato\n");
        printf("4. Pesquisar Contato\n");
        printf("5. Exibir Contatos\n");
        printf("6. Estado da Agenda\n");
        printf("0. Sair\n\n");

        printf("Opcao: ");
        //clean_stdin();
        scanf("%d", &n);

        switch (n)
        {
            case 1:
                insereContato(li);
            break;
            case 2:
                excluiContato(li);
            break;
            case 3:
                alterarContato(li);
            break;
            case 4:
                pesquisarContato(li);
            break;
            case 5:
                exibirContatos(li);
            break;
            case 6:
                estadoAgenda(li);
            break;
            case 0:
            break;
            default:
                printf("Opcao invalida! Insira novamente...");
                getchar();
        }
    } while(n != 0);
    
    libera_lista(li);
    return 0;
}