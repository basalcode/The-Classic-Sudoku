// getTextNode.c 파일은 Linked List의 Node에서 특정 값을 얻어오는 역할을 하는 함수 파일.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getTextNode.h"

// Linked List의 헤더에 동적할당.
PSTR_NODE getTextNode_allocInitHeader()
{
	PSTR_NODE list = malloc(sizeof(STR_NODE));
	memset(list, 0, sizeof(STR_NODE));

	return list;
}

// Linked List의 node 개수를 리턴해주는 함수.
int getTextNode_getNodeMax(PSTR_NODE list)
{
	PSTR_NODE curr = list->nextNode;

	while (curr->nextNode != NULL)
	{
		curr = curr->nextNode;
	}

	return curr->nodeNumber;
}

// Linked List의 node에 있는 문자열중 가장 길이가 긴 문자열을 리턴해줌.
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