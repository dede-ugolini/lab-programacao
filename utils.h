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

void removerQuebraLinha(char *str);
void cadastrarCliente();
#endif