// screenText_PlayScreen.c 파일은 게임 실행화면 관련된 텍스트 파일 함수.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment (lib, "winmm.lib")

#include "screenText_PlayScreen.h"

#include "setTextNode.h"
#include "getTextNode.h"
#include "setBoxedNode.h"
#include "getBoxedNode.h"
#include "setDataStructure.h"
#include "setMatrix.h"
#include "getMatrix.h"
#include "setMatrixTextNode.h"
#include "getMatrixTextNode.h"
#include "screenOperator_Main_OptionScreen.h"
#include "screenOperator_PlayScreen.h"

#include "printMatrix.h"
#include "printBuffer.h"
#include "setBuffer.h"
#include "getGoto.h"
#include "setGoto.h"
#include <Windows.h>

#define DIRECTION_KEY_COMMON(key) (key == 0 || key == 0xE0 || key == -32)
#define DIRECTION_KEY_UP 72
#define DIRECTION_KEY_DOWN 80
#define DIRECTION_KEY_LEFT 75
#define DIRECTION_KEY_RIGHT 77

#define ENTER_KEY 13
#define ERASE_KEY 8
#define DELETE_KEY 83
#define OPTION_KEY 111
#define ESCAPE_KEY 27

#define Y_KEY 121 
#define N_KEY 110

#define I 0
#define J 1
#define MOVE_SET (setGoto_setCursor(move[pos][I], move[pos][J]))

// 매트릭스 생성후 Linked List로 생성해주는 함수.
void screenText_PlayScreen_Matrix(int** answerMatrix, int** questionMatrix, PMATRIX_NODE list, PDATA data)
{
	/* Linked List 화 */ /* 박스처리 물론 되어있음.*/
	setMatrixTextNode_setLinkedList(list, questionMatrix, data);

	return;
}

// 컨트롤 안내서
void screenText_PlayScreen_ControlScreen(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, " [ C O N T R O L _ ]", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  * 이동 하기", LEFT);
	setTextNode_addNodeToEnd(list, "        [↑]", LEFT);
	setTextNode_addNodeToEnd(list, "   [←] [↓] [→] ", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  * 숫자 입력", LEFT);
	setTextNode_addNodeToEnd(list, "   [ 1 ] ~ [ 9 ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  * 숫자 제거", LEFT);
	setTextNode_addNodeToEnd(list, "   [ ←Backspace ]", LEFT);
	setTextNode_addNodeToEnd(list, "   [ Delete ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  * 옵션창 - [ O ]", LEFT);
	setTextNode_addNodeToEnd(list, "  * 검사 - [ ENTER ]", LEFT);
	setTextNode_addNodeToEnd(list, "  * 종료 - [ ESC ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);

	return;
}

// 상태창
void screenText_PlayScreen_StateScreen(PSTR_NODE list, PDATA data)
{
	setTextNode_addNodeToEnd(list, " [ C L A S S I C _ S U D O K U _ ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);	
	setTextNode_addNodeToEnd(list, "", LEFT);

	return;
}

// 상태창 내용
#define ASCII_NUMBER 48
#define MATRIX_WIDTH 37

#define STATE_SCREEN_START_I 21
#define STATE_SCREEN_START_J 2

/* 상태창의 내용출력 함수. */
void screenText_PlayScreen_StateScreenScript_print(PSTR_NODE list)
{

	PSTR_NODE curr = list->nextNode;
	int count = 0;
	while (curr != NULL)
	{
		setGoto_setCursor(STATE_SCREEN_START_I + count, STATE_SCREEN_START_J);
		printf("%s\n", curr->str);
		count++;

		curr = curr->nextNode;
	}
	
	return;
}

/* 1~9까지의 숫자 입력을 상태창으로 보낸 후 출력 */
void screenText_PlayScreen_StateScreenScript_Input(PSTR_NODE list, bool numberExist, int i, int j, int matrix)
{
	char* str = malloc(sizeof(char) * MATRIX_WIDTH + 1);
	memset(str, 0, sizeof(char) * MATRIX_WIDTH + 1);

	/* 숫자가 있는 곳에 입력 불가*/
	if (numberExist)
	{
		sprintf(str, "[뭐야] (%d %d) 숫자 이미 있잖아  ", i, j); 
	}
	else /* 숫자가 없는 곳에 입력 성공 */
	{
		sprintf(str, "[입력] (%d %d) <--- %d 입력 성공 ", i, j, matrix);
	}

	setTextNode_addNodeToEnd(list, str, LEFT);

	/* 상태창 라인수보다 초과 시, 지워 버리기 ! */
	if (getTextNode_getNodeMax(list) > 5)
	{
		setTextNode_eraseNodeToStart(list);
	}

	/* 할당 해제 */
	free(str);

	return;
}

/* 숫자 지우는 입력 상태창으로 보낸 후 출력.*/
void screenText_PlayScreen_StateScreenScript_Remove(PSTR_NODE list, bool initNumber, bool numberExist, int i, int j, int matrix)
{
	char* str = malloc(sizeof(char) * MATRIX_WIDTH + 1);
	memset(str, 0, sizeof(char) * MATRIX_WIDTH + 1);

	/* 해당 좌표가 초깃값일 경우.*/ /* 지우면 못지운다고 리턴*/
	if (initNumber)
	{
		sprintf(str, "[안돼] (%d %d) 초기값 숫자 못지워", i, j);
	}
	else /* 초기값 아님 */
	{
		/* 초기값이 아닌데 숫자가 있을 경우 */
		if (numberExist)
		{
			sprintf(str, "[제거] (%d %d) ---> %d 제거 성공 ", i, j, matrix);
		}
		else /* 초기값이 아닌데 숫자가 없을 경우 */
		{

			sprintf(str, "[디져] (%d %d) 없는데 어떻게 지워", i, j);
		}

	}

	setTextNode_addNodeToEnd(list, str, LEFT);

	/* 상태창 라인수보다 초과 시, 지워 버리기 ! */
	if (getTextNode_getNodeMax(list) > 5)
	{
		setTextNode_eraseNodeToStart(list);
	}

	/* 할당 해제 */
	free(str);

	return;
}

/* 기타 입력이 들어왔을때 */
void screenText_PlayScreen_StateScreenScript_ExtraKey(PSTR_NODE list, int keyBoard, int max)
{
	char* str = malloc(sizeof(char) * MATRIX_WIDTH + 1);
	memset(str, 0, sizeof(char) * MATRIX_WIDTH + 1);


	if (keyBoard == ENTER_)
	{
		sprintf(str, "[검사] 스도쿠 정답 확인 %d / 3 ", max);
	}
	else if (keyBoard == OPTION_)
	{
		sprintf(str, "[옵션] 옵션창을 선택 했습니다.   ");
	}
	else if (keyBoard == ESCAPE_)
	{
		sprintf(str, "[종료] 종료창을 선택 했습니다.   ");
	}
	
	setTextNode_addNodeToEnd(list, str, LEFT);

	/* 상태창 라인수보다 초과 시, 지워 버리기 ! */
	if (getTextNode_getNodeMax(list) > 5)
	{
		setTextNode_eraseNodeToStart(list);
	}

	/* 할당 해제 */
	free(str);

	return;
}

/* 기타 입력 탈출시 */
void screenText_PlayScreen_StateScreenScript_ExtraKey_Out(PSTR_NODE list, int index)
{
	char* str = malloc(sizeof(char) * MATRIX_WIDTH + 1);
	memset(str, 0, sizeof(char) * MATRIX_WIDTH + 1);

	switch(index)
	{
	case 1:
	{
		sprintf(str, "[옵션] 설정 내용을 저장했습니다.");
		break;
	}
	case 2:
	{
		sprintf(str, "[검사] 검사를 통과하지못했습니다.");
		break;
	}
	case 3:
	{
		sprintf(str, "[종료] 게임으로 다시 복귀합니다.");
		break;
	}
	}
	

	setTextNode_addNodeToEnd(list, str, LEFT);

	/* 상태창 라인수보다 초과 시, 지워 버리기 ! */
	if (getTextNode_getNodeMax(list) > 5)
	{
		setTextNode_eraseNodeToStart(list);
	}

	/* 할당 해제 */
	free(str);
}

// 힌트 배열
void screenText_PlayScreen_HintsScreen(PSTR_NODE list, PDATA data)
{
	setTextNode_addNodeToEnd(list, "[ H I N T S _ ]", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);

	return;
}

// 힌트 배열 내용
#define HINT_HIGHT 5
#define HINT_WIDTH 7
void screenText_PlayScreen_HintScreenScript(int* hintArr, PDATA data, int i, int j, bool generate)
{
	char** buffer = malloc(sizeof(char*) * HINT_HIGHT);
	for (int i = 0; i < HINT_HIGHT; i++)
	{
		buffer[i] = malloc(sizeof(char) * HINT_WIDTH + 1);
		memset(buffer[i], 0, sizeof(char) * HINT_WIDTH + 1);
		memset(buffer[i], ' ', sizeof(char) * HINT_WIDTH);
	}

	int count = 0;

	/* 숫자 입력 ON*/
	if (generate)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				/* 배열의 숫자와 좌표가 일치 할때 */
				if ((i * 3) + j == hintArr[count] - 1)
				{
					buffer[i * 2][j * 3] = ASCII_NUMBER + hintArr[count++];
				}
				else
				{
					buffer[i * 2][j * 3] = '-';
				}
			}
		}
	}
	else /* 숫자 입력 OFF*/
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				buffer[i * 2][j * 3] = '-';
			}
		}
	}
	

	int gotoCount = 0;
	for (int i = 0; i < HINT_HIGHT; i++)
	{
		setGoto_setCursor(21 + gotoCount++, 45);
		printf("%s", buffer[i]);
	}

	setBuffer_freeChar2DBuffer(buffer, HINT_HIGHT);

	return;
}


/* 여기서부터는 띄우는 창. */
/* 옵션 - O */

#define TEMP_I 6
#define TEMP_J 9

#define OPTION_MOVE_MAX 11
/* 옵션스크린에 관련된 함수. 출력, 값 정리 등 */
void screenText_PlayScreen_OptionScreen(PDATA data)
{
	/* Linked List 제작 */
	PSTR_NODE list = getTextNode_allocInitHeader();

	setTextNode_addNodeToEnd(list, "< O P T I O N >", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, " * 기본값 ' 표시       * 음악", LEFT);
	setTextNode_addNodeToEnd(list, "   ON [ ]  OFF [ ]       ON [ ]  OFF [ ]  ", LEFT);
	setTextNode_addNodeToEnd(list, "                        ", LEFT);
	setTextNode_addNodeToEnd(list, " * 경계선 디자인       * 음악 선택", LEFT);
	setTextNode_addNodeToEnd(list, "   기본값      [ ]       가요 재생   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "   점  선      [ ]       팝송 재생   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "   모든선 표시 [ ]       BGM  재생   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "   경계선 제거 [ ]        [ESC] - 창닫기  ", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);

	setBoxedNode_addBoxNode(list, 0);

	/* 출력 */
	PSTR_NODE curr;

	/* 조작 */ /* 시작 위치도 알려줘야함 */
	int** move = getGoto_cursorLocation_Node(list, OPTION_MOVE_MAX, TEMP_I - 1, TEMP_J + 1);
	int pos = 0;
	int flag;

BACK:
	/* 커서의 원래 위치 기억 */
	flag = pos;
	MOVE_SET;

	curr = list->nextNode;

	/* 화면 출력 */
	int count = 0;
	while (curr != NULL)
	{
		setGoto_setCursor(TEMP_I + count++, TEMP_J);
		printf("%s", curr->str);
		
		curr = curr->nextNode;
	}

	/* Data 읽어와서 V 표시 해주는 작업 */
	// 표시 ON / OFF
	if (data->gameData->designe_initValueMark_OnOff == true)
	{
		pos = 0;
	}
	else
	{
		pos = 1;
	}
	MOVE_SET;
	printf("V");

	// 음악 ON / OFF
	if (data->gameData->music_OnOff == true)
	{
		pos = 2;
	}
	else
	{
		pos = 3;
	}
	MOVE_SET;
	printf("V");
	

	// 경계선 디자인
	switch (data->gameData->designe_boundaryType)
	{
	case DEFAULT:
	{
		pos = 4;
		break;
	}
	case DOTED_LINE:
	{
		pos = 6;
		break;
	}
	case EVERY_LINE:
	{
		pos = 8;
		break;
	}
	case REMOVE_LINE:
	{
		pos = 10;
		break;
	}
	}
	MOVE_SET;
	printf("V");

	// 음악 TYPE
	switch (data->gameData->music_playList)
	{
	case K_POP:
	{
		pos = 5;
		break;
	}
	case POP_SONG:
	{
		pos = 7;
		break;
	}
	case BGM:
	{
		pos = 9;
		break;
	}
	}
	MOVE_SET;
	printf("V");

	pos = flag;
	int keyBoard;
	while (1)
	{
		MOVE_SET;
		keyBoard = _getch();
		/* 방향키 조작 */
		if (DIRECTION_KEY_COMMON(keyBoard))
		{
			keyBoard = _getch();
			pos = screenOperator_driectionKeyboard_playScreen(move, OPTION_MOVE_MAX, pos, keyBoard);
		}
		/* 엔터를 눌렀을때. */
		else if (keyBoard == ENTER_KEY)
		{
			switch (pos)
			{
			/* 기본값 ON / OFF */
			case 0:
			{
				data->gameData->designe_initValueMark_OnOff = true;
				goto BACK;
			}
			case 1:
			{
				data->gameData->designe_initValueMark_OnOff = false;
				goto BACK;
			}
			/* 음악 ON / OFF */
			case 2: // ON
			{
				/* 이미 켜져있을때는 키는입력이 소용없으니까 꺼져있는경우 이입력이 들어오면, 음악재생해줌 선곡된걸로.*/
				if (data->gameData->music_OnOff == false)
				{
					char* directory = screenOperator_MainScreen_Option_Music(data);
					PlaySound(TEXT(directory), NULL, SND_ASYNC | SND_LOOP);
					data->gameData->music_OnOff = true;
					free(directory);
				}
				goto BACK;
			}
			case 3: // OFF
			{
				/* 마찬가지로 켜져있을때만 꺼줌.*/
				if (data->gameData->music_OnOff == true)
				{
					PlaySound(NULL, NULL, 0);
					data->gameData->music_OnOff = false;
				}

				goto BACK;
			}
			/* 경계선 디자인 - 기본값 */
			case 4:
			{
				data->gameData->designe_boundaryType = DEFAULT;
				goto BACK;
			}
			case 6:
			{
				data->gameData->designe_boundaryType = DOTED_LINE;
				goto BACK;
			}
			case 8:
			{
				data->gameData->designe_boundaryType = EVERY_LINE;
				goto BACK;
			}
			case 10:
			{
				data->gameData->designe_boundaryType = REMOVE_LINE;
				goto BACK;
			}
			/* 음악 선택 */
			// 지금 선곡된것과 다른 선곡이 들어 올경우에만 작동함.
			case 5:
			{
				if (data->gameData->music_playList != K_POP)
				{
					data->gameData->music_playList = K_POP;
					if (data->gameData->music_OnOff == true) // 소리켜져있으면,
					{
						PlaySound(NULL, NULL, 0); // 꺼준후,
						char* directory = screenOperator_MainScreen_Option_Music(data);
						PlaySound(TEXT(directory), NULL, SND_ASYNC | SND_LOOP);
						free(directory);
					}
				}
				goto BACK;
			}
			case 7:
			{
				if (data->gameData->music_playList != POP_SONG)
				{
					data->gameData->music_playList = POP_SONG;
					if (data->gameData->music_OnOff == true) // 소리켜져있으면,
					{
						PlaySound(NULL, NULL, 0); // 꺼준후,
						char* directory = screenOperator_MainScreen_Option_Music(data);
						PlaySound(TEXT(directory), NULL, SND_ASYNC | SND_LOOP);
						free(directory);
					}
				}
				goto BACK;
			}
			case 9:
			{
				if (data->gameData->music_playList != BGM)
				{
					data->gameData->music_playList = BGM;
					if (data->gameData->music_OnOff == true) // 소리켜져있으면,
					{
						PlaySound(NULL, NULL, 0); // 꺼준후,
						char* directory = screenOperator_MainScreen_Option_Music(data);
						PlaySound(TEXT(directory), NULL, SND_ASYNC | SND_LOOP);
						free(directory);
					}
				}
				goto BACK;
			}
			}
		}
		/* ESC 키를 눌렀을때. */
		else if (keyBoard == ESCAPE_KEY)
		{
			return;
		}
	}

	/* 할당 해제 */
	setTextNode_freeNodes(list);
	setGoto_freeCursorLocationArr(move, OPTION_MOVE_MAX);
	free(list);

	return;
}

/* 키보드 값을 받아서 커서를 이동 시켜주는 함수.*/
int screenText_PlayScreen_OptionScreen_move(int** move,int moveMax, int pos, int keyBoard)
{
	switch (keyBoard)
	{
	case (DIRECTION_KEY_UP):
	{
		int next = 0;
		while (1)
		{
			next = (moveMax + (next - 1)) % moveMax;
			if (pos > next)
			{
				if (move[pos][I] > move[next][I] && move[pos][J] == move[next][J])
				{
					pos = next;
					break;
				}
			}
			else if (pos < next)
			{
				if (move[pos][I] < move[next][I] && move[pos][J] == move[next][J])
				{
					pos = next;
					break;
				}
			}
			else if (pos == next)
				break;
		}
		break;
	}
	case (DIRECTION_KEY_DOWN):
	{
		int next = 0;
		while (1)
		{
			next = (next + 1) % moveMax;
			if (pos < next)
			{
				if (move[pos][I] < move[next][I] && move[pos][J] == move[next][J])
				{
					pos = next;
					break;
				}
			}
			else if (pos > next)
			{
				if (move[pos][I] > move[next][I] && move[pos][J] == move[next][J])
				{
					pos = next;
					break;
				}
			}
			else if (pos == next)
				break;
		}
		break;
	}
	case (DIRECTION_KEY_LEFT):
	{
		int next = 0;
		while (1)
		{
			next = (moveMax + (next - 1)) % moveMax;
			if (pos > next)
			{
				if (move[pos][I] == move[next][I] && move[pos][J] > move[next][J])
				{
					pos = next;
					break;
				}
			}
			else if (pos < next)
			{
				if (move[pos][I] == move[next][I] && move[pos][J] < move[next][J])
				{
					pos = next;
					break;
				}
			}
			else if (pos == next)
				break;
		}
		break;
	}
	case (DIRECTION_KEY_RIGHT):
	{
		int next = 0;
		while (1)
		{
			next = (next + 1) % moveMax;
			if (pos < next)
			{
				if (move[pos][I] == move[next][I] && move[pos][J] < move[next][J])
				{
					pos = next;
					break;
				}
			}
			else if (pos > next)
			{
				if (move[pos][I] == move[next][I] && move[pos][J] > move[next][J])
				{
					pos = next;
					break;
				}
			}
			else if (pos == next)
				break;
		}
		break;
	}
	}

	return pos;
}

#define STR_SIZE 46
/* 검사 - 엔터후 경고 문 */
// 승리 true - 재시작 false - main 화면
bool screenText_PlayScreen_EnterScreen_Win(PDATA data, int start_i, int start_j)
{
	bool ret;
	
	PSTR_NODE list = getTextNode_allocInitHeader();

	char* str = malloc(sizeof(char) * STR_SIZE);
	memset(str, 0, sizeof(char) * STR_SIZE);
	char* str2 = malloc(sizeof(char) * STR_SIZE);
	memset(str2, 0, sizeof(char) * STR_SIZE);

	/* 게임 시작시 경험치가 차감되는걸 고려하여 계산 */
	int exp;

	if (data->gameData->rate_exp == 0)
	{
		// 경험치가 0일때.
		exp = (data->gameData->difficulty_tier + 1) * 5 * 2;
	}
	else
	{
		// 아닐때
		exp = (data->gameData->difficulty_tier + 1) * 5 * 3;
	}

	int displayExp = (data->gameData->difficulty_tier + 1) * 5 * 2;

	/* 승리시 데이터 정리 */
	// 경험치, 레벨, 티어
	if (data->gameData->difficulty_hintArr_OnOff == false)
	{
		exp *= 2; // 힌트 off시 경험치 200% 증가
	}

	/* 경험치 추가 */
	data->gameData->rate_exp += exp;
	/* 레벨 계산 */
	data->gameData->rate_level = data->gameData->rate_exp / ( 40 + (data->gameData->rate_exp / 40 * 10)) + 1;

	if (data->gameData->rate_level >= 31)
	{
		data->gameData->rate_myTier = 6;
	}
	else
	{
		data->gameData->rate_myTier = (data->gameData->rate_level - 1) / 5;
	}

	// 전체 승률
	data->gameData->rate.total[1] += 1; // 승
	data->gameData->rate.total[2] -= 1; // 패
	data->gameData->rate.total[3] = data->gameData->rate.total[1] * 100 / data->gameData->rate.total[0];

	// 각 승률
	switch (data->gameData->difficulty_tier)
	{
	case BRONZE:
	{
		data->gameData->rate.bronze[1] += 1; // 승
		data->gameData->rate.bronze[2] -= 1; // 패
		data->gameData->rate.bronze[3] = data->gameData->rate.bronze[1] * 100 / data->gameData->rate.bronze[0];
		break;
	}
	case SILVER:
	{
		data->gameData->rate.silver[1] += 1; // 승
		data->gameData->rate.silver[2] -= 1; // 패
		data->gameData->rate.silver[3] = data->gameData->rate.silver[1] * 100 / data->gameData->rate.silver[0];
		break;
	}
	case GOLD:
	{
		data->gameData->rate.gold[1] += 1; // 승
		data->gameData->rate.gold[2] -= 1; // 패
		data->gameData->rate.gold[3] = data->gameData->rate.gold[1] * 100 / data->gameData->rate.gold[0];
		break;
	}
	case PLATINUM:
	{
		data->gameData->rate.platinum[1] += 1; // 승
		data->gameData->rate.platinum[2] -= 1; // 패
		data->gameData->rate.platinum[3] = data->gameData->rate.platinum[1] * 100 / data->gameData->rate.platinum[0];
		break;
	}
	case DIAMOND:
	{
		data->gameData->rate.diamond[1] += 1; // 승
		data->gameData->rate.diamond[2] -= 1; // 패
		data->gameData->rate.diamond[3] = data->gameData->rate.diamond[1] * 100 / data->gameData->rate.diamond[0];
		break;
	}
	case MASTER:
	{
		data->gameData->rate.master[1] += 1; // 승
		data->gameData->rate.master[2] -= 1; // 패
		data->gameData->rate.master[3] = data->gameData->rate.master[1] * 100 / data->gameData->rate.master[0];
		break;
	}
	case GRAND_MASTER:
	{
		data->gameData->rate.grandMaster[1] += 1; // 승
		data->gameData->rate.grandMaster[2] -= 1; // 패
		data->gameData->rate.grandMaster[3] = data->gameData->rate.grandMaster[1] * 100 / data->gameData->rate.grandMaster[0];
		break;
	}
	}

	setDataStructure_saveStructure(data);

	/* 배열 사용 */
	
	setTextNode_addNodeToEnd(list, "< Y O U _ W I N >", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);

	switch (data->gameData->rate_myTier)
	{
	case BRONZE:
	{
		sprintf(str, " * 브론즈 [ BRONZE ] 클리어");
		break;
	}
	case SILVER:
	{
		sprintf(str, " * 실버 [ SILVER ] 클리어");

		break;
	}
	case GOLD:
	{
		sprintf(str, " * 골드 [ GOLD ] 클리어");

		break;
	}
	case PLATINUM:
	{
		sprintf(str, " * 플래티넘 [ PLATINUM ] 클리어");

		break;
	}
	case DIAMOND:
	{
		sprintf(str, " * 다이아몬드 [ DIAMOND ] 클리어");

		break;
	}
	case MASTER:
	{
		sprintf(str, " * 마스터 [ MASTER ] 클리어");

		break;
	}
	case GRAND_MASTER:
	{
		sprintf(str, " * 그랜드 마스터 [ GRAND MASTER ] 클리어");

		break;
	}
	}
	setTextNode_addNodeToEnd(list, str, LEFT);
	memset(str, 0, sizeof(char) * STR_SIZE);

	
	if (data->gameData->difficulty_hintArr_OnOff == true)
	{
		sprintf(str, "[ 보상으로 + %2d Exp를 얻습니다. (힌트ON) ]", displayExp);
	}
	else
	{
		sprintf(str, "[ 보상으로 + %2d Exp를 얻습니다. (힌트OFF) ]", displayExp);
	}
	
	setTextNode_addNodeToEnd(list, str, MIDDLE);
	memset(str, 0, sizeof(char) * STR_SIZE);

	switch(data->gameData->rate_myTier)
	{
	case BRONZE:
	{
		sprintf(str, "* 현재 티어 : 브론즈 [ BROANZE ]");
		sprintf(str2, "[ Level - %2d ]  [ Exp - %4d ]", data->gameData->rate_level, data->gameData->rate_exp);
		break;
	}
	case SILVER:
	{
		sprintf(str, "* 현재 티어 : 실버 [ SILVER ]");
		sprintf(str2, "[ Level - %2d ]  [ Exp - %4d ]", data->gameData->rate_level, data->gameData->rate_exp);
		break;
	}
	case GOLD:
	{
		sprintf(str, "* 현재 티어 : 골드 [ GOLD ]");
		sprintf(str2, "[ Level - %2d ]  [ Exp - %4d ]", data->gameData->rate_level, data->gameData->rate_exp);

		break;
	}
	case PLATINUM:
	{
		sprintf(str2, "* 현재 티어 : 플래티넘 [ PLATINUM ]");
		sprintf(str2, "[ Level - %2d ]  [ Exp - %4d ]", data->gameData->rate_level, data->gameData->rate_exp);

		break;
	}
	case DIAMOND:
	{
		sprintf(str, "* 현재 티어 : 다이아몬드 [ DIAMOND ]");
		sprintf(str2, "[ Level - %2d ]  [ Exp - %4d ]", data->gameData->rate_level, data->gameData->rate_exp);

		break;
	}
	case MASTER:
	{
		sprintf(str, "* 현재 티어 : 마스터 [ MASTER ]");
		sprintf(str2, "[ Level - %2d ]  [ Exp - %4d ]", data->gameData->rate_level, data->gameData->rate_exp);
		break;
	}
	case GRAND_MASTER:
	{
		sprintf(str, "* 현재 티어 : 그랜드 마스터 [ GRAND MASTER ]");
		sprintf(str2, "[ Level - %2d ]  [ Exp - %4d ]", data->gameData->rate_level, data->gameData->rate_exp);
		break;
	}
	}
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, str, MIDDLE);

	setTextNode_addNodeToEnd(list, str2, MIDDLE);
	setTextNode_addNodeToEnd(list, "[ Y ] - 새로운 게임  [ N ] - 메인화면", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);

	setBoxedNode_addBoxNode(list, STR_SIZE- 1);

	/* 출력 */
	PSTR_NODE curr = list->nextNode;

	int count = 0;
	while (curr != NULL)
	{	
		setGoto_setCursor(start_i + count++, start_j);
		printf("%s", curr->str);

		curr = curr->nextNode;
	}

	/* 조작 */
	int keyBoard;
	while (1)
	{
		keyBoard = _getch();
		if (keyBoard == Y_KEY || keyBoard == ENTER_KEY)
		{
			ret = true;
			break;
		}
		else if (keyBoard == N_KEY || keyBoard == ESCAPE_KEY)
		{
			ret = false;
			break;
		}
		
	}

	/* 할당 해제 */
	setTextNode_freeNodes(list);
	free(list);
	free(str);

	return ret;
}

// 3회 누적시 패배. true - 진행 false - 패배
bool screenText_PlayScreen_EnterScreen_Lost(int max, int level, int start_i, int start_j)
{
	bool ret;
	
	PSTR_NODE list = getTextNode_allocInitHeader();

	int penalty = (level / 5 + 1) * 5;

	char* str = malloc(sizeof(char) * STR_SIZE);
	memset(str, 0, sizeof(char) * STR_SIZE);

	setTextNode_addNodeToEnd(list, "< WARNING >", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, " * 올바른 스도쿠 배열이 아닙니다.", MIDDLE);

	sprintf(str, "  [ 남은 검사횟수 : %d / 3 ]", max);
	setTextNode_addNodeToEnd(list, str, MIDDLE);
	memset(str, 0, sizeof(char) * STR_SIZE);

	setTextNode_addNodeToEnd(list, "* 다시 시도 하시겠습니까 ?", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  [ Y ] - 예  [ N ] - 아니오  ", MIDDLE);

	sprintf(str, " (중도 포기시, - %2d Exp 패널티)", penalty);
	setTextNode_addNodeToEnd(list, str, MIDDLE);
	memset(str, 0, sizeof(char) * STR_SIZE);

	setBoxedNode_addBoxNode(list, STR_SIZE - 1);

	/* 출력 */
	PSTR_NODE curr = list->nextNode;

	int count = 0;
	while (curr != NULL)
	{
		setGoto_setCursor(start_i + count++, start_j);
		printf("%s", curr->str);

		curr = curr->nextNode;
	}

	/* 조작 */
	int keyBoard;
	while (1)
	{
		keyBoard = _getch();
		if (keyBoard == Y_KEY || keyBoard == ENTER_KEY)
		{
			ret = true;
			break;
		}
		else if (keyBoard == N_KEY || keyBoard == ESCAPE_KEY)
		{
			ret = false;
			break;
		}
	}

	/* 할당 해제 */
	setTextNode_freeNodes(list);
	free(list);
	free(str);

	return ret;
}

/* 패배 화면 */ //true - 재시작 false - 메인으로 
bool screenText_PlayScreen_EnterScreen_GameOver(int level, int start_i, int start_j)
{
	bool ret;

	PSTR_NODE list = getTextNode_allocInitHeader();

	int penalty = (level / 5 + 1) * 5;

	char* str = malloc(sizeof(char) * STR_SIZE);
	memset(str, 0, sizeof(char) * STR_SIZE);

	setTextNode_addNodeToEnd(list, "< G A M E _ O V E R >", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	sprintf(str, "* 게임에서 졌습니다. (-% 2d Exp)", penalty);
	setTextNode_addNodeToEnd(list, str, MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "* 다시 시작 하시겠습니까 ?", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ Y ] - 예  [ N ] - 아니오", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);

	setBoxedNode_addBoxNode(list, STR_SIZE - 1);

	/* 출력 */
	PSTR_NODE curr = list->nextNode;

	int count = 0;
	while (curr != NULL)
	{
		setGoto_setCursor(start_i + count++, start_j);
		printf("%s", curr->str);

		curr = curr->nextNode;
	}

	/* 조작 */
	int keyBoard;
	while (1)
	{
		keyBoard = _getch();
		if (keyBoard == Y_KEY || keyBoard == ENTER_KEY)
		{
			ret = true;
			break;
		}
		else if (keyBoard == N_KEY || keyBoard == ESCAPE_KEY)
		{
			ret = false;
			break;
		}
	}

	/* 할당 해제 */
	setTextNode_freeNodes(list);
	free(list);
	free(str);

	return ret;
}

/* 나가기 - esc */ // ture - 게임 종료 false 계속
bool screenText_PlayScreen_EscapeScreen(int level, int start_i, int start_j)
{
	bool ret;

	PSTR_NODE list = getTextNode_allocInitHeader();

	int penalty = (level / 5 + 1) * 5;

	char* str = malloc(sizeof(char) * STR_SIZE);
	memset(str, 0, sizeof(char) * STR_SIZE);

	setTextNode_addNodeToEnd(list, "< EXIT >", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "* 정말 게임을 종료하시겠습니까 ?", MIDDLE);
	sprintf(str, "( 종료시, -%2d Exp 가 차감됩니다. )", penalty);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ Y ] - 예  [ N ] - 아니오", MIDDLE);
	setTextNode_addNodeToEnd(list, str, MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);

	setBoxedNode_addBoxNode(list, STR_SIZE - 1);

	/* 출력 */
	PSTR_NODE curr = list->nextNode;

	int count = 0;
	while (curr != NULL)
	{
		setGoto_setCursor(start_i + count++, start_j);
		printf("%s", curr->str);

		curr = curr->nextNode;
	}

	/* 조작 */
	int keyBoard;
	while (1)
	{
		keyBoard = _getch();
		if (keyBoard == Y_KEY || keyBoard == ENTER_KEY)
		{
			ret = true;
			break;
		}
		else if (keyBoard == N_KEY || keyBoard == ESCAPE_KEY)
		{
			ret = false;
			break;
		}
	}

	/* 할당 해제 */
	setTextNode_freeNodes(list);
	free(list);
	free(str);

	return ret;
}