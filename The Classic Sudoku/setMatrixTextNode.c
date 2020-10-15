// setMatrixTextNode.c ������ Node���� �̿��ؼ� Linked List�� ������ִ� ������ �ϴ� �Լ� ����.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "setMatrixTextNode.h"

#include "getMatrixTextNode.h"
#include "setDataStructure.h"

#define LINE_SIZE 9

// matrix�� node�� �̿��� Linked List�� �������ִ� �Լ�. ( �ڽ�ó�� )
void setMatrixTextNode_setLinkedList(PMATRIX_NODE list, int** matrix, PDATA data)
{
	char* str;

	str = getMatrixTextNode_topNode(data);
	setMatrixTextNode_addNodeToEnd(list, str);
	for (int i = 0; i < LINE_SIZE; i++)
	{
		str = getMatrixTextNode_arrToString(matrix[i], data);
		setMatrixTextNode_addNodeToEnd(list, str);

		BorL blankOrLine = BLANK; // �ش� ���� ���� �� ������ �ƴ����� �Ǵ����ִ� enum.
		if (i % 3 == 2)
			blankOrLine = LINE;

		if (i == 8)
			break;
		
		str = getMatrixTextNode_middleNode(blankOrLine, data);
		setMatrixTextNode_addNodeToEnd(list, str);
	}
	str = getMatrixTextNode_bottomNode(data);
	setMatrixTextNode_addNodeToEnd(list, str);

	return;
}

// node�� LinkedList �� �ڿ� �������ִ� �Լ�.
void setMatrixTextNode_addNodeToEnd(PMATRIX_NODE list, char* str)
{
	PMATRIX_NODE curr = list;

	while (curr->nextNode != NULL)
	{
		curr = curr->nextNode;
	}

	curr->nextNode = malloc(sizeof(MATRIX_NODE));
	memset(curr->nextNode, 0, sizeof(MATRIX_NODE));

	curr = curr->nextNode;

	curr->str = str;

	return;
}

// node�� LinkedList �� �տ� �������ִ� �Լ�.
void setMatrixTextNode_addNodeToStart(PMATRIX_NODE list, char* str)
{
	PMATRIX_NODE curr = malloc(sizeof(MATRIX_NODE));
	memset(curr, 0, sizeof(MATRIX_NODE));

	curr->nextNode = list->nextNode;
	list->nextNode = curr;

	curr->str = str;

	return;
}

// matrix�� Linked List�� ��ȸ�ϸ鼭 �޸� �Ҵ����� ���ִ� �Լ�.
void setMatrixTextNode_freeNodes(PMATRIX_NODE list)
{
	PMATRIX_NODE curr = list->nextNode;
	PMATRIX_NODE next;

	while (curr != NULL)
	{
		next = curr->nextNode;

		free(curr->str);
		free(curr);
		curr = next;
	}
	return;
}