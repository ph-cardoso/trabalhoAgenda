#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

int main()
{
    int n, i = 0;
    Agenda agenda[MAX];

    do
    {
        //MENU
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
                i = inserirContato(agenda, i);
            break;
            case 2:

            break;
            case 3:

            break;
            case 4:

            break;
            case 5:
                exibirContatos(agenda);
            break;
            case 6:

            break;
            case 0:
            break;
            default:
                printf("Opcao invalida! Insira novamente...");
                getchar();
                system("cls");
        }
    } while(n != 0);

    return 0;
}