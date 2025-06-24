#include <stdio.h>
#include "utils.h"

int main(){
	
	List *node = NULL;
	node = insertNode(node);
	printList(node);
	salvarClientes(node, getLength(node));
	freeList(node);
	return 0;
}
