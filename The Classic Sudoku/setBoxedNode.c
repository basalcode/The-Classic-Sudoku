// setBoxedNode.c ������ Node���� ������ Ư�������� �ڽ������� ������.

#include <stdio.h>

#include "setBoxedNode.h"

#include "getBoxedNode.h"
#include "setTextNode.h"
#include "getTextNode.h"

#define CONSOL_MAX_X 79

// Linked List�� list���� ����(��� ����) x ����(����� ������ ���� �� str �̻��� ������ ��)�� �ڽ��� �����Ǵ� ��带 ����.
void setBoxedNode_addBoxNode(PSTR_NODE list, int length)
{
	int lengthMax = getTextNode_getStringLengthMax(list);
	if (length == 0 || length < lengthMax) // ���� ��迭 ���� ���� ���� ��������.
	{
		length = lengthMax;
	}
	else if (length > CONSOL_MAX_X) // Console â ������ �������.
	{
		length = CONSOL_MAX_X;
	}

	PSTR_NODE curr = list->nextNode;

	char* topStr = getBoxedNode_TopLine(length);
	char* bottomStr = getBoxedNode_BottomLine(length);

	setTextNode_addNodeToStart(list, topStr, ELSE); // ���� top

	while (curr != NULL)
	{
		curr->str = getBoxedNode_MidLine(curr->str, length, curr->arrange); // ���� middle
		
		curr = curr->nextNode;
	}

	setTextNode_addNodeToEnd(list, bottomStr, ELSE); // ���� bottom

	return;
}

