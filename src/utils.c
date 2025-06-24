#include <stdio.h> // Para usar printf e fgets
#include <string.h> // Para usar strlen
#include <ctype.h> // Para usar isaplha e isspace
#include <time.h> // Para usar srand
#include <stdlib.h> // Para usar malloc
#include "utils.h"

#define TAM_NOME 100

void removerQuebraLinha(char *str) {
	size_t len = strlen(str);
	if (len > 0 && str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}
}

char *cadastrarCliente() {
	char ch[TAM_NOME];
	while (1) {
		printf("\nDigite seu nome utilizando apenas letras:\n");
		fgets(ch, TAM_NOME, stdin);
		removerQuebraLinha(ch);

		size_t len = strlen(ch);
		if (len == 0) {
			printf("❌ Não é permitido nome vazio, por favor digite novamente.\n");
			continue;
		}

		int valido = 1;

		// Verificar todos os caracteres
		for (size_t i = 0; i < len; i++) {
			if (!isalpha(ch[i]) && !isspace(ch[i])) {
				printf("❌ '%c' não é um caractere válido.\n", ch[i]);
				valido = 0;
			}
		}

		if (valido) {
			printf("✅ Cliente '%s' cadastrado com sucesso!\n", ch);
			char *name = malloc(len + 1);
			strcpy(name, ch);
			return name;
		} else {
			printf("Por favor, digite novamente.\n");
		}
	}
}
int genId(){
	srand(time(NULL));
	return (rand() % 9999);
}

List *insertNode (List *node){

	List *new = malloc(sizeof(List));
	new->id = genId();
	new->name = cadastrarCliente();
	new->next = node;
	return new;
}

void printList (List *node){
	while(node != NULL){
		printf("Id :%d Name: %s\n", node->id, node->name);
		node = node->next;
	}
}

void freeList (List *node) {
	while (node != NULL) {
		List *temp = node->next;
		free(node);
		node = temp;
	}
}
