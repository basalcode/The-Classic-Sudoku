// getTextNode.c ������ Linked List�� Node���� Ư�� ���� ������ ������ �ϴ� �Լ� ����.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getTextNode.h"

// Linked List�� ����� �����Ҵ�.
PSTR_NODE getTextNode_allocInitHeader()
{
	PSTR_NODE list = malloc(sizeof(STR_NODE));
	memset(list, 0, sizeof(STR_NODE));

	return list;
}

// Linked List�� node ������ �������ִ� �Լ�.
int getTextNode_getNodeMax(PSTR_NODE list)
{
	PSTR_NODE curr = list->nextNode;

	while (curr->nextNode != NULL)
	{
		curr = curr->nextNode;
	}

	return curr->nodeNumber;
}

// Linked List�� node�� �ִ� ���ڿ��� ���� ���̰� �� ���ڿ��� ��������.
int getTextNode_getStringLengthMax(PSTR_NODE list)
{
	PSTR_NODE curr = list->nextNode;

	int lengthMax = 0;
	while (curr != NULL)
	{
		if (lengthMax < curr->strLnegth)
			lengthMax = curr->strLnegth;

		curr = curr->nextNode;
	}

	return lengthMax;
}