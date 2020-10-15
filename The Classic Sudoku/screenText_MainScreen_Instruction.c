// instructionScreenText.c 파일은 게임 소개 화면 관련 텍스트가 들어있는 함수 파일.

#include "screenText_MainScreen_Instruction.h"

#include "setTextNode.h"

// 게임 설명 Page 1
void screenText_MainScreen_Instruction_Page1(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, " [ I N S T R U C T I O N ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  1. 게임 역사", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    : 마방진의 일종으로, 9X9 칸에서 진행되는 숫자 퍼즐 게임이다. 18세기  ", LEFT); 
	setTextNode_addNodeToEnd(list, "     스위스의 수학자 레온하르트 오일러가 창안한 라틴방진(Latin Square)에 ", LEFT);
	setTextNode_addNodeToEnd(list, "     기초해 미국의 건축가 하워드 간즈(Howard Garns)가 넘버플레이스(Number", LEFT);
	setTextNode_addNodeToEnd(list, "     Place)라는 이름으로 1979년에 소개했다.   ", LEFT);
	setTextNode_addNodeToEnd(list, "      이후 1984년 일본 니코리사의 잡지 <퍼즐통신 니코리>에서 스도쿠라는  ", LEFT);
	setTextNode_addNodeToEnd(list, "     이름을 붙여 수록하면서 대중화되었다. 명칭은 일본어 숫자는 한 번씩만 ", LEFT);
	setTextNode_addNodeToEnd(list, "     쓸 수 있다에서 유래했다.", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  2. 게임 규칙", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    * 각각의 가로줄(row) 세로줄(column)에 1~9가 중복 없이 하나씩 들어간다.", LEFT);//
	setTextNode_addNodeToEnd(list, "    * 3X3칸(box) 안에는 1~9가 중복 없이 하나씩 들어간다.", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ ESC - 뒤로 ]                    1 / 3                    [ ENTER - 다음 ]", MIDDLE);

	return;
}



// 게임 설명 Page 2
void screenText_MainScreen_Instruction_Page2(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, " [ I N S T R U C T I O N ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  3. 게임 특징", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    : 보통 주어지는 문제에서는 일부분만 숫자가 채워져 있기때문에, 위의 규", LEFT);
	setTextNode_addNodeToEnd(list, "     칙을 바탕으로 나머지 칸들의 숫자를 유추해야 한다. 기차나 비행기에서 ", LEFT);
	setTextNode_addNodeToEnd(list, "     시간 때우기 딱 좋은 퍼즐이다. 신문 자투리로 나오기도 하며, 비슷한 퍼", LEFT);
	setTextNode_addNodeToEnd(list, "     즐들과 함께 잔뜩 모아놓은 소형 책자도 심심치 않게 볼 수 있다. 한국에", LEFT);
	setTextNode_addNodeToEnd(list, "     서의 인지도도 낮은 건 아니지만 아무래도 외국 쪽에서 더 대중화된 듯  ", LEFT);
	setTextNode_addNodeToEnd(list, "     하다.", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  4. 스도쿠 생성 규칙", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    : 스도쿠를 풀 때 뿐만 아니라 만들 때에도 규칙이 존재한다. 위에 언급  ", LEFT);
	setTextNode_addNodeToEnd(list, "      된 니코리 출판사는 스토쿠 문제를 만들 때의 규칙을 두 가지 세웠다.  ", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ ESC - 뒤로 ]                    2 / 3                    [ ENTER - 다음 ]", MIDDLE);

	return;
}



// 게임 설명 Page 3
void screenText_MainScreen_Instruction_Page3(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, " [ I N S T R U C T I O N ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "      * 가능한 정답은 한 개 뿐이다.", LEFT);
	setTextNode_addNodeToEnd(list, "      * 처음 제시되는 숫자들의 개수는 30개 이하여야 한다.", LEFT);
	setTextNode_addNodeToEnd(list, "      * 숫자들이 기입되어 있는 모습이 대칭이 되어야 한다.", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "     물론 어린이용이나 입문자용 스도쿠에는 81칸 중 70칸 이상의 숫자가 제 ", LEFT);
	setTextNode_addNodeToEnd(list, "     시 된 것도 있고, 대칭을 지키지 않은 스도쿠도 많이 있다. 즉 위의 규칙", LEFT);
	setTextNode_addNodeToEnd(list, "     은 고난이도의 스도쿠를 만들기 위해 존재하는 룰이다.", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "< 출처 : 나무위키 - 스도쿠 > ", RIGHT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  5. The Classic Sudoku", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    : < The Classic Sudoku > 에서는 다양한 형태의 스도쿠 생성 방식을 지원하기", LEFT);
	setTextNode_addNodeToEnd(list, "      위해서 다양한 사용자 옵션을 제공 했습니다. 티어(난이도)나 레벨 같은", LEFT);
	setTextNode_addNodeToEnd(list, "      시스템을 사용하여 더욱 고난이도의 게임을 즐길 수 있습니다.", LEFT);
	setTextNode_addNodeToEnd(list, "", RIGHT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ ESC - 뒤로 ]                    3 / 3                                    ", MIDDLE);

	return;
}