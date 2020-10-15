// screenText_MainScreen_Review.c 파일은 리뷰관련 텍스트 함수 파일.

#include "screenText_MainScreen_Review.h"

#include "setTextNode.h"

/*

*/
// 리뷰 페이지 1
void screenText_MainScreen_Review_Page1(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ M A K I N G _ R E V I E W ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "= The Classic Sudoku =", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "C언어를 이용해 만든 콘솔 기반의 스도쿠 게임입니다.", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "= 특징 =", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "* ASCII 코드 GUI 구현 *", MIDDLE);
	setTextNode_addNodeToEnd(list, "* 각종 게임 옵션 지원 *", MIDDLE);
	setTextNode_addNodeToEnd(list, "* 음악 플레이어 기능 *", MIDDLE);
	setTextNode_addNodeToEnd(list, "* 전적 관리, Level, 등급 시스템 *", MIDDLE);
	setTextNode_addNodeToEnd(list, "* binary 저장 시스템 *", MIDDLE);
	setTextNode_addNodeToEnd(list, "* 문제지/답안지 txt 파일로 출력 *", MIDDLE);
	setTextNode_addNodeToEnd(list, "* 각종 자료구조 구현 *", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - 뒤로 ]                    1 / 1                                    ", MIDDLE);
	return;
}