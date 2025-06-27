#include <stdio.h>
#include "utils.h"

int main(){
	
	List *node = NULL;
	int opcao;				
	
	do {
	
	printf("\n==============================================");
	printf("\n1. Cadastrar novo cliente\n");
	printf("2. Exibir clientes que estão em memória\n");
	printf("3. Salvar clientes cadastrados em um arquivo\n");
	printf("4. Remover Cliente pelo id\n");
	printf("5.\n");
	printf("6.\n");
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
		case 4:
			node = removeNode(node,getId());
			break;
	}
	} while(opcao != 0);

	freeList(node);
	return 0;
}
