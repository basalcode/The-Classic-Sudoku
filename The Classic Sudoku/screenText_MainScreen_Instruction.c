// instructionScreenText.c ������ ���� �Ұ� ȭ�� ���� �ؽ�Ʈ�� ����ִ� �Լ� ����.

#include "screenText_MainScreen_Instruction.h"

#include "setTextNode.h"

// ���� ���� Page 1
void screenText_MainScreen_Instruction_Page1(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, " [ I N S T R U C T I O N ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  1. ���� ����", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    : �������� ��������, 9X9 ĭ���� ����Ǵ� ���� ���� �����̴�. 18����  ", LEFT); 
	setTextNode_addNodeToEnd(list, "     �������� ������ �����ϸ�Ʈ ���Ϸ��� â���� ��ƾ����(Latin Square)�� ", LEFT);
	setTextNode_addNodeToEnd(list, "     ������ �̱��� ���డ �Ͽ��� ����(Howard Garns)�� �ѹ��÷��̽�(Number", LEFT);
	setTextNode_addNodeToEnd(list, "     Place)��� �̸����� 1979�⿡ �Ұ��ߴ�.   ", LEFT);
	setTextNode_addNodeToEnd(list, "      ���� 1984�� �Ϻ� ���ڸ����� ���� <������� ���ڸ�>���� ��������  ", LEFT);
	setTextNode_addNodeToEnd(list, "     �̸��� �ٿ� �����ϸ鼭 ����ȭ�Ǿ���. ��Ī�� �Ϻ��� ���ڴ� �� ������ ", LEFT);
	setTextNode_addNodeToEnd(list, "     �� �� �ִٿ��� �����ߴ�.", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  2. ���� ��Ģ", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    * ������ ������(row) ������(column)�� 1~9�� �ߺ� ���� �ϳ��� ����.", LEFT);//
	setTextNode_addNodeToEnd(list, "    * 3X3ĭ(box) �ȿ��� 1~9�� �ߺ� ���� �ϳ��� ����.", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ ESC - �ڷ� ]                    1 / 3                    [ ENTER - ���� ]", MIDDLE);

	return;
}



// ���� ���� Page 2
void screenText_MainScreen_Instruction_Page2(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, " [ I N S T R U C T I O N ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  3. ���� Ư¡", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    : ���� �־����� ���������� �Ϻκи� ���ڰ� ä���� �ֱ⶧����, ���� ��", LEFT);
	setTextNode_addNodeToEnd(list, "     Ģ�� �������� ������ ĭ���� ���ڸ� �����ؾ� �Ѵ�. ������ ����⿡�� ", LEFT);
	setTextNode_addNodeToEnd(list, "     �ð� ����� �� ���� �����̴�. �Ź� �������� �����⵵ �ϸ�, ����� ��", LEFT);
	setTextNode_addNodeToEnd(list, "     ���� �Բ� �ܶ� ��Ƴ��� ���� å�ڵ� �ɽ�ġ �ʰ� �� �� �ִ�. �ѱ���", LEFT);
	setTextNode_addNodeToEnd(list, "     ���� �������� ���� �� �ƴ����� �ƹ����� �ܱ� �ʿ��� �� ����ȭ�� ��  ", LEFT);
	setTextNode_addNodeToEnd(list, "     �ϴ�.", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  4. ������ ���� ��Ģ", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    : ������ Ǯ �� �Ӹ� �ƴ϶� ���� ������ ��Ģ�� �����Ѵ�. ���� ���  ", LEFT);
	setTextNode_addNodeToEnd(list, "      �� ���ڸ� ���ǻ�� ������ ������ ���� ���� ��Ģ�� �� ���� ������.  ", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ ESC - �ڷ� ]                    2 / 3                    [ ENTER - ���� ]", MIDDLE);

	return;
}



// ���� ���� Page 3
void screenText_MainScreen_Instruction_Page3(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, " [ I N S T R U C T I O N ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "      * ������ ������ �� �� ���̴�.", LEFT);
	setTextNode_addNodeToEnd(list, "      * ó�� ���õǴ� ���ڵ��� ������ 30�� ���Ͽ��� �Ѵ�.", LEFT);
	setTextNode_addNodeToEnd(list, "      * ���ڵ��� ���ԵǾ� �ִ� ����� ��Ī�� �Ǿ�� �Ѵ�.", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "     ���� ��̿��̳� �Թ��ڿ� �������� 81ĭ �� 70ĭ �̻��� ���ڰ� �� ", LEFT);
	setTextNode_addNodeToEnd(list, "     �� �� �͵� �ְ�, ��Ī�� ��Ű�� ���� ������ ���� �ִ�. �� ���� ��Ģ", LEFT);
	setTextNode_addNodeToEnd(list, "     �� ���̵��� ������ ����� ���� �����ϴ� ���̴�.", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "< ��ó : ������Ű - ������ > ", RIGHT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  5. The Classic Sudoku", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    : < The Classic Sudoku > ������ �پ��� ������ ������ ���� ����� �����ϱ�", LEFT);
	setTextNode_addNodeToEnd(list, "      ���ؼ� �پ��� ����� �ɼ��� ���� �߽��ϴ�. Ƽ��(���̵�)�� ���� ����", LEFT);
	setTextNode_addNodeToEnd(list, "      �ý����� ����Ͽ� ���� ���̵��� ������ ��� �� �ֽ��ϴ�.", LEFT);
	setTextNode_addNodeToEnd(list, "", RIGHT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ ESC - �ڷ� ]                    3 / 3                                    ", MIDDLE);

	return;
}