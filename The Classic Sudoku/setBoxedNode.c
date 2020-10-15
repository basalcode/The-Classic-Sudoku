// setBoxedNode.c 파일은 Node들을 가져와 특정형식의 박스형식을 씌워줌.

#include <stdio.h>

#include "setBoxedNode.h"

#include "getBoxedNode.h"
#include "setTextNode.h"
#include "getTextNode.h"

#define CONSOL_MAX_X 79

// Linked List인 list에서 세로(노드 개수) x 가로(노드의 원소중 가장 긴 str 이상의 임의의 값)의 박스가 생성되는 노드를 삽입.
void setBoxedNode_addBoxNode(PSTR_NODE list, int length)
{
	int lengthMax = getTextNode_getStringLengthMax(list);
	if (length == 0 || length < lengthMax) // 가장 긴배열 보다 낮은 값이 들어왔을때.
	{
		length = lengthMax;
	}
	else if (length > CONSOL_MAX_X) // Console 창 범위를 벗어났을때.
	{
		length = CONSOL_MAX_X;
	}

	PSTR_NODE curr = list->nextNode;

	char* topStr = getBoxedNode_TopLine(length);
	char* bottomStr = getBoxedNode_BottomLine(length);

	setTextNode_addNodeToStart(list, topStr, ELSE); // 상자 top

	while (curr != NULL)
	{
		curr->str = getBoxedNode_MidLine(curr->str, length, curr->arrange); // 상자 middle
		
		curr = curr->nextNode;
	}

	setTextNode_addNodeToEnd(list, bottomStr, ELSE); // 상자 bottom

	return;
}

