// setMatrixTextNode.c 파일은 Node들을 이용해서 Linked List를 만들어주는 역할을 하는 함수 파일.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "setMatrixTextNode.h"

#include "getMatrixTextNode.h"
#include "setDataStructure.h"

#define LINE_SIZE 9

// matrix의 node를 이용해 Linked List를 셋팅해주는 함수. ( 박스처리 )
void setMatrixTextNode_setLinkedList(PMATRIX_NODE list, int** matrix, PDATA data)
{
	char* str;

	str = getMatrixTextNode_topNode(data);
	setMatrixTextNode_addNodeToEnd(list, str);
	for (int i = 0; i < LINE_SIZE; i++)
	{
		str = getMatrixTextNode_arrToString(matrix[i], data);
		setMatrixTextNode_addNodeToEnd(list, str);

		BorL blankOrLine = BLANK; // 해당 줄이 선이 들어갈 줄인지 아닌지를 판단해주는 enum.
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

// node를 LinkedList 맨 뒤에 연결해주는 함수.
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

// node를 LinkedList 맨 앞에 연결해주는 함수.
void setMatrixTextNode_addNodeToStart(PMATRIX_NODE list, char* str)
{
	PMATRIX_NODE curr = malloc(sizeof(MATRIX_NODE));
	memset(curr, 0, sizeof(MATRIX_NODE));

	curr->nextNode = list->nextNode;
	list->nextNode = curr;

	curr->str = str;

	return;
}

// matrix용 Linked List를 순회하면서 메모리 할당해제 해주는 함수.
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