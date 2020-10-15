// printMatrixTextNode.c ������ matrix�� Linked List�� ������ ������ִ� �Լ� ����.

#include <stdio.h>

#include "printMatrixTextNode.h"

#include "setMatrixTextNode.h"

// matrix Linked List�� �ִ� ������ ������ִ� �Լ�.
void printMatrixTextNode_printNode(PMATRIX_NODE list)
{
	PMATRIX_NODE curr = list->nextNode;

	while (curr != NULL)
	{
		printf("%s\n", curr->str);
		curr = curr->nextNode;
	}

	return;
}