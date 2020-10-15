// printMatrixTextNode.c 파일은 matrix용 Linked List의 내용을 출력해주는 함수 파일.

#include <stdio.h>

#include "printMatrixTextNode.h"

#include "setMatrixTextNode.h"

// matrix Linked List에 있는 내용을 출력해주는 함수.
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