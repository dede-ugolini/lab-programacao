#include <stdio.h>
#include "utils.h"

int main(){
	
	List *node = NULL;
	node = insertNode(node);
	printList(node);
	// cadastrarCliente();
	freeList(node);
	return 0;
}
