// screenText_MainScreen_Review.c ������ ������� �ؽ�Ʈ �Լ� ����.

#include "screenText_MainScreen_Review.h"

#include "setTextNode.h"

/*

*/
// ���� ������ 1
void screenText_MainScreen_Review_Page1(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ M A K I N G _ R E V I E W ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "= The Classic Sudoku =", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "C�� �̿��� ���� �ܼ� ����� ������ �����Դϴ�.", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "= Ư¡ =", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "* ASCII �ڵ� GUI ���� *", MIDDLE);
	setTextNode_addNodeToEnd(list, "* ���� ���� �ɼ� ���� *", MIDDLE);
	setTextNode_addNodeToEnd(list, "* ���� �÷��̾� ��� *", MIDDLE);
	setTextNode_addNodeToEnd(list, "* ���� ����, Level, ��� �ý��� *", MIDDLE);
	setTextNode_addNodeToEnd(list, "* binary ���� �ý��� *", MIDDLE);
	setTextNode_addNodeToEnd(list, "* ������/����� txt ���Ϸ� ��� *", MIDDLE);
	setTextNode_addNodeToEnd(list, "* ���� �ڷᱸ�� ���� *", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - �ڷ� ]                    1 / 1                                    ", MIDDLE);
	return;
}