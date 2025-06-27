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

char *cadastrarClienteNome() {
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

char *cadastrarClienteCpf(){
	char cpf[14];
	while (1) {
		printf("\nDigite seu CPF utilizando apenas números\n");
		fgets(cpf, sizeof(cpf), stdin);
		removerQuebraLinha(cpf);
		size_t len = strlen(cpf);
		if (len == 0) {
			printf("❌ Não é permitido CPF vazio, por favor digite novamente.\n");
			continue;
		}

		int valido = 1;

		// Verificar todos os caracteres
		for (size_t i = 0; i < len; i++) {
			if(!isdigit(cpf[i])) {
				printf("❌ '%c' não é um numero válido.\n", cpf[i]);
				valido = 0;
			}
		}

		if (valido) {
			printf("✅ CPF '%s' cadastrado com sucesso!\n", cpf);
			char *CPF = malloc(len + 1);
			strcpy(CPF, cpf);
			return CPF;
		} else {
			printf("Por favor, digite novamente.\n");
		}
	}
}
int genId(){
	srand(time(NULL));
	return (rand() % 9999);
}

int getId(){
	int id;
	printf("Digite o número do id\n");
	scanf("%d", &id);
	return id;
}

List *insertNode (List *node){

	List *new = malloc(sizeof(List));
	new->id = genId();
	new->name = cadastrarClienteNome();
	new->cpf = cadastrarClienteCpf();
	new->next = node;
	return new;
}

void printList (List *node){
	while(node != NULL){
		printf("Id :%d Name: %s Cpf: %s\n", node->id, node->name, node->cpf);
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
int getLength(List *node){
	int len = 0;
	while (node != NULL){
		len++;
		node = node->next;
	}
	return len;
}

List *removeNode(List *node, int value){
  if (node == NULL){
    return NULL;
  }
  // Caso especial onde o valor procurado for o primeiro
  if (node->id == value){
    List *temp = node->next;
    free(node);
    return temp;
  }
  List *current = node;
  while(current->next != NULL){
    if(current->next->id == value){
      List *temp = current->next;
      current->next = current->next->next;
      free(temp);
			printf("Cliente removido com sucesso!\n");
      return node;
    }
    current = current->next;
  }
  return node; //Valor nao encontrado
}
void salvarClientes(List *node){
	FILE *file = fopen("clientes.txt", "w");
	if (file == NULL){
		printf("Erro ao abrir o arquivo\n");
		return;
	}
	while (node != NULL) {
		fprintf(file, "Id %d Name: %s CPF:%s\n",
			node->id, node->name, node->cpf);
		node = node->next;	
	}
	fclose(file);
	printf("Clientes salvos com sucesso\n");
}

void salvarClientesIndividual(List *node) {
	FILE *file = fopen("clientes.txt", "a+");
	if (file == NULL) {
		printf("Erro ao abrir o arquivo\n");
		return;
	}
	while (node != NULL){
		fprintf(file, "Id: %d | Nome: %s | CPF: %s\n", node->id, node->name, node->cpf);
		node = node->next;
	}
	fclose(file);
	printf("✅ Cliente salvo com sucesso\n");
}

