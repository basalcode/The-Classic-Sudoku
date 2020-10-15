// screenText_MainScreen_Option.c 파일은 게임 옵션관련 텍스트가 모여있는 함수 파일.

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>

#include "screenText_MainScreen_Option.h"

#include "setTextNode.h"
#include "getDataStructure.h"
#include "setDataStructure.h"

// 게임 설정 메인화면
void screenText_MainScreen_Option_Main(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ G A M E _ O P T I O N ]", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  1. 난이도  설정   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    : 레벨에 따른 난이도(티어)를 설정합니다.          ", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  2. 기본 값 설정   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    : 스도쿠에 단서가 되는 기본값의 배치를 설정합니다.", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  3. 문제지  저장   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    : 문제지, 답안지 저장 유무를 설정합니다.          ", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  4. 음악 & 디자인  [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    : 음악 재생목록, 기타 디자인들을 설정합니다.      ", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - 뒤로 ]                                                             ", MIDDLE);

	return;
}

// 난이도 설정 탭 page1
void screenText_MainScreen_Option_Difficulty_Page1(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ D I F F I C U L T Y ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  1. 난이도(티어) 설정", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (1) 브론즈          [ 54%  공개 ]       BRONZE", LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 1 - 5)     [ 43개 단서 ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (2) 실버            [ 46%  공개 ]       SILVER", LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 6 - 10)    [ 37개 단서 ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (3) 골드            [ 39%  공개 ]         GOLD", LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 11 - 15)   [ 31개 단서 ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (4) 플래티넘        [ 33%  공개 ]     PLATINUM", LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 16 - 20)   [ 26개 단서 ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (5) 다이아몬드      [ 28%  공개 ]      DIAMOND", LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 21 - 25)   [ 22개 단서 ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - 뒤로 ]                    1 / 2                      [ [ ] - 다음 ]", MIDDLE);
	
	return;
}

// 난이도 설정 탭 page2
void screenText_MainScreen_Option_Difficulty_Page2(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ D I F F I C U L T Y ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  1. 티어 설정", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (6) 마스터          [ 24%  공개 ]       MASTER",LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 26 - 30)   [ 19개 단서 ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (7) 그랜드 마스터   [ 21%  공개 ] GRAND MASTER", LEFT);
	setTextNode_addNodeToEnd(list, "        (Lv. 31 - 35)   [ 17개 단서 ]          [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  2. 힌트 보기", LEFT);
	setTextNode_addNodeToEnd(list, "    * 힌트는 겹치지 않는 숫자들의 배열을 보여줍니다. (가로, 세로, 3x3)", LEFT);
	setTextNode_addNodeToEnd(list, "    * 게임 플레이 화면 우측 하단에 힌트가 표시됩니다.", MIDDLE);
	setTextNode_addNodeToEnd(list, "    * 힌트 보기 [ OFF ] 설정시, 경험치가 2배로 적용됩니다.", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (1) 힌트 보기 [ O N ]    [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (2) 힌트 보기 [ OFF ]    [ ] ", LEFT);	
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - 뒤로 ]                    2 / 2                                    ", MIDDLE);

	return;
}

// 기본 값 설정. Page 1
void screenText_MainScreen_Option_NumberSetting_Page1(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ N U M B E R _ S E T T I N G ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  * 스도쿠 풀이에 주어지는 기본 값의 배치에 대해 설정합니다.*", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  1. 무작위로 배치      [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  2. 대칭으로 배치      [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    * 대칭에 대한 설명은 다음페이지에 있습니다.", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (1) 완전형 대칭           [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (2) 풍차형 대칭 (기본값)  [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (3) 나비형 대칭           [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (4) 모래시계형 대칭       [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (5) 랜덤 선택             [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - 뒤로 ]                    1 / 2                      [ [ ] - 다음 ]", MIDDLE);

	return;
}

// 초기값 대칭 Type
void screenText_MainScreen_Option_NumberSetting_Page2(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ N U M B E R _ S E T T I N G ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  2. 대칭으로 배치", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  (1) 완전형 대칭                      (2) 풍차형 대칭", LEFT);
	setTextNode_addNodeToEnd(list, "    ㅁ  ㅁ  ㅁ  ㅁ                       ㅁㅁㅁㅁ    ㅁ", LEFT);
	setTextNode_addNodeToEnd(list, "      ㅁ  ㅁ  ㅁ                             ㅁㅁ  ㅁㅁ", LEFT);
	setTextNode_addNodeToEnd(list, "    ㅁ  ㅁ  ㅁ  ㅁ                       ㅁㅁㅁㅁㅁㅁㅁ", LEFT);
	setTextNode_addNodeToEnd(list, "      ㅁ  ㅁ  ㅁ                         ㅁㅁ  ㅁㅁ    ", LEFT);
	setTextNode_addNodeToEnd(list, "    ㅁ  ㅁ  ㅁ  ㅁ                       ㅁ    ㅁㅁㅁㅁ", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  (3) 나비형 대칭 (좌우)           (4) 모래시계형 대칭 (수직)", LEFT);
	setTextNode_addNodeToEnd(list, "    ㅁㅁ      ㅁㅁ                       ㅁㅁㅁㅁㅁㅁㅁ", LEFT);
	setTextNode_addNodeToEnd(list, "    ㅁㅁㅁ  ㅁㅁㅁ                         ㅁㅁㅁㅁㅁ  ", LEFT);
	setTextNode_addNodeToEnd(list, "    ㅁㅁㅁㅁㅁㅁㅁ                           ㅁㅁㅁ    ", LEFT);
	setTextNode_addNodeToEnd(list, "    ㅁㅁㅁ  ㅁㅁㅁ                         ㅁㅁㅁㅁㅁ  ", LEFT);
	setTextNode_addNodeToEnd(list, "    ㅁㅁ      ㅁㅁ                       ㅁㅁㅁㅁㅁㅁㅁ", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - 뒤로 ]                    1 / 2                                    ", MIDDLE);

	return;
}

// 답안지 저장 ON / OFF.
void screenText_MainScreen_Option_SaveSheet(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ S A V E _ S H E E T ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  1. 문제지 저장 [ OFF ]     [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    * 플레이한 문제지를 저장하지 않습니다.", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  2. 문제지 저장 [ O N ]     [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "    * 플레이한 문제지를 저장합니다.", LEFT);
	setTextNode_addNodeToEnd(list, "    * 문제지는 실행파일과 같은 카테고리에 저장됩니다.", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (1) 문제지만 저장       [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (2) 문제지 + 답지 저장  [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - 뒤로 ]                                                             ", MIDDLE);

	return;
}

// 음악 & 디자인 Page 1
void screenText_MainScreen_Option_MusicDesigne_Page1(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ M U S I C  &  D E S I G N E ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  1. 음악 재생", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (1) 음악 재생 [ OFF ]   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    (2) 음악 재생 [ O N ]   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "     * 음악 재생시 시간이 2초정도 소요 될수 있습니다.", LEFT);
	setTextNode_addNodeToEnd(list, "     * 재생 목록은 뒷페이지에 있습니다.", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "        [1] 가요 재생       [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "        [2] 팝송 재생       [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "        [3] BGM  재생       [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "[ ESC - 뒤로 ]                    1 / 5                      [ [ ] - 다음 ]", MIDDLE);

	return;
}

// 음악 & 디자인 Page 2
void screenText_MainScreen_Option_MusicDesigne_Page2(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ M U S I C  &  D E S I G N E ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "  2. 기본 값 ' 표시", LEFT);
	setTextNode_addNodeToEnd(list, "    * 초기에 주어지는 기본 숫자 옆에 작은따옴표(') 표시를 합니다.", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (1) 기본값 ' 표시 [ O N ]   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (2) 기본값 ' 표시 [ OFF ]   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  3. 경계선 디자인", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (1) 기본 값         [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (2) 점 선           [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (3) 모든 선 표시    [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "    (4) 경계선 제거     [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ ESC - 뒤로 ]                    2 / 5                      [ [ ] - 다음 ]", MIDDLE);

	return;
}

// 가요 리스트
void screenText_MainScreen_Option_MusicDesigne_Page3(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ M U S I C  &  D E S I G N E ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    4. Play List", LEFT);
	setTextNode_addNodeToEnd(list, "      (1) 가요 재생 목록", LEFT);
	setTextNode_addNodeToEnd(list, "        [01] 스탠딩 애그 - 무지개", LEFT);
	setTextNode_addNodeToEnd(list, "        [02] 김지수 - dream all day", LEFT);
	setTextNode_addNodeToEnd(list, "        [03] 어쿠루브 - 사랑노래같은 이별노래", LEFT);
	setTextNode_addNodeToEnd(list, "        [04] 40 - 듣는편지", LEFT);
	setTextNode_addNodeToEnd(list, "        [05] 폴킴 - 비", LEFT);
	setTextNode_addNodeToEnd(list, "        [06] 딘 - 넘어와", LEFT);
	setTextNode_addNodeToEnd(list, "        [07] 김예림 - rain", LEFT);
	setTextNode_addNodeToEnd(list, "        [08] 한동근 - 그대라는 사치", LEFT);
	setTextNode_addNodeToEnd(list, "        [09] 백예린 - 가끔", LEFT);
	setTextNode_addNodeToEnd(list, "        [10] 양다일 - 미안해", LEFT);
	setTextNode_addNodeToEnd(list, "        [11] 수란 - Love Story", LEFT);
	setTextNode_addNodeToEnd(list, "        [12] 지코 - 오만과 편견", LEFT);
	setTextNode_addNodeToEnd(list, "        [13] 권진아 - 끝", LEFT);
	setTextNode_addNodeToEnd(list, "        [14] 어반자카파 - 봄을 그리다", LEFT);
	setTextNode_addNodeToEnd(list, "        [15] 언니네 이발소 - 가장 보통의 존재", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ ESC - 뒤로 ]                    3 / 5                    [ ENTER - 다음 ]", MIDDLE);

	return;
}

// 팝송 리스트
void screenText_MainScreen_Option_MusicDesigne_Page4(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ M U S I C  &  D E S I G N E ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    4. Play List", LEFT);
	setTextNode_addNodeToEnd(list, "      (2) 팝송 재생 목록", LEFT);
	setTextNode_addNodeToEnd(list, "        [01] Camila Cabello - Havana", LEFT);
	setTextNode_addNodeToEnd(list, "        [02] Justin Bieber - Love Yourself", LEFT);
	setTextNode_addNodeToEnd(list, "        [03] Sam smith - I'm Not The Only One", LEFT);
	setTextNode_addNodeToEnd(list, "        [04] Ed Sheeran - Shape Of You", LEFT);
	setTextNode_addNodeToEnd(list, "        [05] Mike Perry - The Ocean", LEFT);
	setTextNode_addNodeToEnd(list, "        [06] Clean Bandit - Symphony", LEFT);
	setTextNode_addNodeToEnd(list, "        [07] Sia - Chandelier", LEFT);
	setTextNode_addNodeToEnd(list, "        [08] Pharrell Williams - Happy", LEFT);
	setTextNode_addNodeToEnd(list, "        [09] Sting - Shape Of My Heart", LEFT);
	setTextNode_addNodeToEnd(list, "        [10] Ariana Grande - Dangerous Woman", LEFT);
	setTextNode_addNodeToEnd(list, "        [11] Jeff Bernat - Call You Mine", LEFT);
	setTextNode_addNodeToEnd(list, "        [12] Adele - Hello", LEFT);
	setTextNode_addNodeToEnd(list, "        [13] Calvin Harris - Feels", LEFT);
	setTextNode_addNodeToEnd(list, "        [14] Imagine Dragons - Believer", LEFT);
	setTextNode_addNodeToEnd(list, "        [15] Dua Lipa - New Rules	", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ ESC - 뒤로 ]                    4 / 5                    [ ENTER - 다음 ]", MIDDLE);

	return;
}

// BGM 리스트
void screenText_MainScreen_Option_MusicDesigne_Page5(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, " [ M U S I C  &  D E S I G N E ] ", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "    4. Play List", LEFT);
	setTextNode_addNodeToEnd(list, "      (3) BGM 재생 목록", LEFT);
	setTextNode_addNodeToEnd(list, "        [01] E's Jammy Jams - Jolly Old St Nicholas (Instrumental)", LEFT);
	setTextNode_addNodeToEnd(list, "        [02] Defqwop - Heart Afire", LEFT);
	setTextNode_addNodeToEnd(list, "        [03] Tobu - Higher", LEFT);
	setTextNode_addNodeToEnd(list, "        [04] Zaza - Be Together ", LEFT);
	setTextNode_addNodeToEnd(list, "        [05] Jim Yosef - Firefly", LEFT);
	setTextNode_addNodeToEnd(list, "        [06] Tobu & Marcus Mouya - Running Away", LEFT);
	setTextNode_addNodeToEnd(list, "        [07] Tobu - Roots", LEFT);
	setTextNode_addNodeToEnd(list, "        [08] Dj Okawari - Midnight Train ", LEFT);
	setTextNode_addNodeToEnd(list, "        [09] Elektronomia - Sky High", LEFT);
	setTextNode_addNodeToEnd(list, "        [10] Alan Walker - Fade", LEFT);
	setTextNode_addNodeToEnd(list, "        [11] ", LEFT);
	setTextNode_addNodeToEnd(list, "        [12]", LEFT);
	setTextNode_addNodeToEnd(list, "        [13]", LEFT);
	setTextNode_addNodeToEnd(list, "        [14]", LEFT);
	setTextNode_addNodeToEnd(list, "        [15]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ ESC - 뒤로 ]                    5 / 5                                    ", MIDDLE);

	return;
}

// 경고문 잘못된 티어를 선택했을 경우.
void screenText_MainScreen_Option_WARNING_wrongTier(PSTR_NODE list, PDATA data)
{
	char* tierStr = malloc(sizeof(char) * 100);
	char* levelStr = malloc(sizeof(char) * 100);
	memset(tierStr, 0, sizeof(char) * 100);
	memset(levelStr, 0, sizeof(char) * 100);

	switch (data->gameData->rate_myTier)
	{
	case 0:
	{
		sprintf(tierStr, ": 현재 등급은 [ 브론즈 : BRONZE ] 입니다.");
		sprintf(levelStr, ": 현재 레벨은 [ %2d Level ] 입니다.", data->gameData->rate_level);
		break;
	}
	case 1:
	{
		sprintf(tierStr, ": 현재 등급은 [ 실버 : SILVER ] 입니다.");
		sprintf(levelStr, ": 현재 레벨은 [ %2d Level ] 입니다.", data->gameData->rate_level);
		break;
	}
	case 2:
	{
		sprintf(tierStr, ": 현재 등급은 [ 골드 : GOLD ] 입니다.");
		sprintf(levelStr, ": 현재 레벨은 [ %2d Level ] 입니다.", data->gameData->rate_level);
		break;
	}
	case 3:
	{
		sprintf(tierStr, ": 현재 등급은 [ 플래티넘 : PLATINUM ] 입니다.");
		sprintf(levelStr, ": 현재 레벨은 [ %2d Level ] 입니다.", data->gameData->rate_level);
		break;
	}
	case 4:
	{
		sprintf(tierStr, ": 현재 등급은 [ 다이아몬드 : DIAMOND ] 입니다.");
		sprintf(levelStr, ": 현재 레벨은 [ %2d Level ] 입니다.", data->gameData->rate_level);
		break;
	}
	case 5:
	{
		sprintf(tierStr, ": 현재 등급은 [ 마스터 : MASTER ] 입니다.");
		sprintf(levelStr, ": 현재 레벨은 [ %2d Level ] 입니다.", data->gameData->rate_level);
		break;
	}
	case 6:
	{
		sprintf(tierStr, ": 현재 등급은 [ 그랜드 마스터 : GRAND MASTER ] 입니다.");
		sprintf(levelStr, ": 현재 레벨은 [ %2d Level ] 입니다.", data->gameData->rate_level);
		break;
	}
	}
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, " = = W A R N I N G S", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "* 잘못된 티어를 선택하였습니다. *", MIDDLE);
	setTextNode_addNodeToEnd(list, "* 자신의 등급에 맞는 난이도를 선택해야 합니다. *", MIDDLE);
	setTextNode_addNodeToEnd(list, tierStr, MIDDLE);
	setTextNode_addNodeToEnd(list, levelStr, MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
}
