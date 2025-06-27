#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 100

typedef struct List {

	int id;
	char *name;
	char *cpf;
	struct List *next;
} List;

void removerQuebraLinha(char *str);
char *cadastrarClienteNome();
char *cadastrarClienteCpf();
int genID();
int getId();
List *insertNode(List *node);
List *removeNode(List *node, int value);
void printList(List *node);
void freeList(List *node);
int getLength(List *node);
void salvarClientes(List *node);
void salvarClientesIndividual(List *node);
#endif
