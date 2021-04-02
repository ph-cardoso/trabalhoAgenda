#ifndef AGENDA_H
#define AGENDA_H
#include "agenda.c"
#define MAX 100

typedef struct Agenda;

void clean_stdin();
int inserirContato(Agenda ag[], int i);
void excluirContato();
void alterarContato();
void pesquisarContato();
void exibirContatos(Agenda ag[]);
void estadoAgenda();

#endif