// screenText_MainScreen.c ������ mainȭ�鿡 ���õ� �ؽ�Ʈ���� �����ϴ� �Լ�����

#include "screenText_MainScreen.h"

#include "setTextNode.h"

void mainScreenText_setScreen(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " == T H E _ C L A S S I C _ S U D O K U ==", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "Made By_ BasalCode    ", RIGHT);
	setTextNode_addNodeToEnd(list, "", RIGHT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "1. ���� ����  [ ]", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "2. ���� ����  [ ]", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "3. ���� ����  [ ]", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "4. ��� Ȯ��  [ ]", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "5. ���� �ı�  [ ]", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "6. ���� ����  [ ]", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - �������� ]  ", RIGHT);
	
	return;
}