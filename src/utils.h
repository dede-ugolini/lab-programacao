#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 100

typedef struct {
	char nome[TAM_NOME];
	/*char cpf[TAM_CPF];
	char endereco[TAM_ENDERECO];
	char telefone[TAM_TELEFONE];
	int idade; */
} Cliente;

typedef struct List {

	int id;
	char *name;
	struct List *next;
} List;

void removerQuebraLinha(char *str);
char *cadastrarCliente();
int genID();
List *insertNode(List *node);
void printList(List *node);
void freeList(List *node);
int getLength(List *node);
void salvarClientes(List *node, int length);
void salvarClientesIndivual(List *node);
#endif
