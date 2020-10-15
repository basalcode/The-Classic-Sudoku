// setTextNode.c ������ ���ڿ� Linked List�� Node�� str�迭�� ���� ���ִ� �Լ� ����.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "setTextNode.h"

#include "getString.h"

// node�� node�� �� ���ڿ��� Linked List�� ���� �߰� ���ִ� �Լ�.
void setTextNode_addNodeToEnd(PSTR_NODE list, char* str, ARRANGEMENT arrange)
{
	PSTR_NODE curr = list;

	int nodeNumber = 1;
	while (curr->nextNode != NULL)
	{
		curr = curr->nextNode;
		nodeNumber++;
	}

	curr->nextNode = malloc(sizeof(STR_NODE));
	memset(curr->nextNode, 0, sizeof(STR_NODE));

	curr = curr->nextNode;

	curr->str = getString_mallocString(str);
	curr->strLnegth = strlen(str);
	curr->arrange = arrange;
	curr->nodeNumber = nodeNumber;

	return;
}

// node�� node�� �� ���ڿ��� Linked List�� �������� �߰����ִ� �Լ�.
void setTextNode_addNodeToStart(PSTR_NODE list, char* str, ARRANGEMENT arrange)
{
	PSTR_NODE curr = malloc(sizeof(STR_NODE));
	memset(curr, 0, sizeof(STR_NODE));

	curr->nextNode = list->nextNode;
	list->nextNode = curr;

	curr->str = getString_mallocString(str);
	curr->strLnegth = strlen(str);
	curr->arrange = arrange;
	
	int nodeNumber = 1;
	while (curr != NULL)
	{
		curr->nodeNumber = nodeNumber;
		nodeNumber;
		curr = curr->nextNode;
	}
	
	return;
}

// Linked List�� ù��° ��带 �������ִ� �Լ�.
void setTextNode_eraseNodeToStart(PSTR_NODE list)
{
	PSTR_NODE curr = list->nextNode->nextNode;

	free(list->nextNode);

	list->nextNode = curr;

	return;
}

// ���� �Ҵ�� Linked List�� ��ȸ�ϸ鼭 �Ҵ����� ���ִ� �Լ�.
void setTextNode_freeNodes(PSTR_NODE list)
{
	PSTR_NODE curr = list->nextNode;
	PSTR_NODE next;

	while (curr != NULL)
	{
		next = curr->nextNode;

		free(curr->str);
		free(curr);
		curr = next;
	}	
	return;
}