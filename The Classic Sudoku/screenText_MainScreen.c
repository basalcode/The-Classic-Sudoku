// screenText_MainScreen.c 파일은 main화면에 관련된 텍스트들을 저장하는 함수파일

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
	setTextNode_addNodeToEnd(list, "1. 게임 시작  [ ]", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "2. 게임 설명  [ ]", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "3. 게임 설정  [ ]", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "4. 기록 확인  [ ]", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "5. 제작 후기  [ ]", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "6. 게임 종료  [ ]", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - 게임종료 ]  ", RIGHT);
	
	return;
}