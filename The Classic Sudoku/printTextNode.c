// printTextNode.c 파일은 Linked List의 Node를 선회하면서 Node의 데이터를 출력해주는 함수파일.

#include <stdio.h>

#include "printTextNode.h"
#include "setGoto.h"
#include "getGoto.h"

// Linked List에 담긴 배열들을 출력해줌. (2차원 형식으로)
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

// STATE SCREEN 출력 
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