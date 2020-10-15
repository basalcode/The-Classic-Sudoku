// setTextNode.c 파일은 문자열 Linked List의 Node에 str배열을 설정 해주는 함수 파일.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "setTextNode.h"

#include "getString.h"

// node와 node에 들어갈 문자열을 Linked List의 끝에 추가 해주는 함수.
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

// node와 node에 들어갈 문자열을 Linked List의 시작점에 추가해주는 함수.
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

// Linked List의 첫번째 노드를 삭제해주는 함수.
void setTextNode_eraseNodeToStart(PSTR_NODE list)
{
	PSTR_NODE curr = list->nextNode->nextNode;

	free(list->nextNode);

	list->nextNode = curr;

	return;
}

// 동적 할당된 Linked List를 순회하면서 할당해제 해주는 함수.
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