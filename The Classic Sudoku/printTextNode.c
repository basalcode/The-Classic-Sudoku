// printTextNode.c ������ Linked List�� Node�� ��ȸ�ϸ鼭 Node�� �����͸� ������ִ� �Լ�����.

#include <stdio.h>

#include "printTextNode.h"
#include "setGoto.h"
#include "getGoto.h"

// Linked List�� ��� �迭���� �������. (2���� ��������)
void printTextNode_printNode(PSTR_NODE list)
{
	PSTR_NODE curr = list->nextNode;

	while (curr != NULL)
	{
		printf("%s\n", curr->str);
		curr = curr->nextNode;
	}

	return;
}

// STATE SCREEN ��� 
#define STATE_SCREEN_START_I 21
#define STATE_SCREEN_START_J 1
void printTextNode_printStateScreen(PSTR_NODE list)
{
	PSTR_NODE curr = list->nextNode;

	int count = 0;
	while (curr != NULL)
	{
		setGoto_setCursor(STATE_SCREEN_START_I + count, STATE_SCREEN_START_J);
		printf("%s\n", curr->str);
		count++;

		curr = curr->nextNode;
	}

	return;
}