#include <stdio.h>
#include "utils.h"

int main(){
	
	List *node = NULL;
	int opcao;				
	
	do {
	
	printf("\n==============================================");
	printf("\n1. Cadastrar novo cliente\n");
	printf("2. Exebir clientes que estão em memória\n");
	printf("3. Salvar clientes cadastrados em um arquivo\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("==============================================\n");
	scanf("%d", &opcao);	
	getchar();

	switch (opcao){
		case 1:
			node = insertNode(node);
			break;
		case 2:
			printList(node);
			break;
		case 3:
			salvarClientesIndividual(node);
			break;
	}
	} while(opcao != 0);

	freeList(node);
	return 0;
}
