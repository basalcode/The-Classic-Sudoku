// screenOperator_PlayScreen.c 컨트롤

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <direct.h>

#include "screenOperator_PlayScreen.h"

#include "getArr9.h"
#include "setMatrix.h"
#include "getMatrix.h"
#include "checkMatrix.h"
#include "setMatrixTextNode.h"
#include "getMatrixTextNode.h"
#include "printMatrixTextNode.h"
#include "getTextNode.h"
#include "printTextNode.h"
#include "buffer_screenText.h"
#include "setBuffer.h"
#include "getBuffer.h"
#include "printBuffer.h"
#include "screenOperator_MainScreen.h"
#include "setDataStructure.h"
#include "screenText_PlayScreen.h"

#include "getGoto.h"
#include "setGoto.h"

#define PLAY_SCREEN_HEIGHT 27
#define PLAY_SCREEN_WIDTH 60

#define SCREEN_HEIGHT 30
#define SCREEN_WIDTH 80

#define MATRIX_HEIGHT 19
#define MATRIX_WIDTH 37
#define MATRIX_MAX 81

#define ASCII_NUMBER 48

#define MOVE_UP(choise) (pos = (choise + pos - 1) % choise)
#define MOVE_DOWN(choise) (pos = (pos + 1) % choise)
#define MOVE_SET (setGoto_setCursor(move[pos][I], move[pos][J]))

#define MOVE_I move[pos][I]
#define MOVE_J move[pos][J]

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

#define LINE_MAX 9

#define I 0
#define J 1

#define LINE_SIZE 9

#include "printMatrix.h"

// 플레이화면 좌표 이동.
int screenOperator_driectionKeyboard_playScreen(int** move, int max, int pos, int keyBoard)
{
	switch (keyBoard)
	{
	case DIRECTION_KEY_UP:
	{
		int nextPos = pos ;
		while(1)
		{
			nextPos = (max + (nextPos - 1)) % max;
			if (pos > nextPos)
			{
				if (move[pos][I] > move[nextPos][I] && move[pos][J] == move[nextPos][J])
				{
					pos = nextPos;
					break;
				}
			}
			else if (pos < nextPos)
			{
				if (move[pos][I] < move[nextPos][I] && move[pos][J] == move[nextPos][J])
				{
					pos = nextPos;
					break;
				}
			}
			else if (nextPos == pos)
			{
				if (pos == 0)
				{
					pos = 10;
				}
				else if (pos == 2)
				{
					pos = 9;
				}
				break;
			}
		}
		break;
	}
	case DIRECTION_KEY_DOWN:
	{
		int nextPos = pos;
		while (1)
		{
			nextPos = (nextPos + 1) % max;
			if (pos < nextPos)
			{
				if (move[pos][I] < move[nextPos][I] && move[pos][J] == move[nextPos][J])
				{
					pos = nextPos;
					break;
				}
			}
			else if (pos > nextPos)
			{
				if (move[pos][I] > move[nextPos][I] && move[pos][J] == move[nextPos][J])
				{
					pos = nextPos;
					break;
				}
			}
			else if (nextPos == pos)
			{
				if (pos == 0)
				{
					pos = 10;
				}
				else if (pos == 2)
				{
					pos = 9;
				}
				break;
			}
		}
		break;
	}
	case DIRECTION_KEY_LEFT:
	{
		int nextPos = pos;
		while (1)
		{
			nextPos = (max + (nextPos - 1)) % max;
			if (pos > nextPos)
			{
				if (move[pos][I] == move[nextPos][I] && move[pos][J] > move[nextPos][J])
				{
					pos = nextPos;
					break;
				}
			}
			else if (pos < nextPos)
			{
				if (move[pos][I] == move[nextPos][I] && move[pos][J] < move[nextPos][J])
				{
					pos = nextPos;
					break;
				}
			}
			else if (nextPos == pos)
			{
				break;
			}
		}
		break;
	}
	case DIRECTION_KEY_RIGHT:
	{
		int nextPos = pos;
		while (1)
		{
			nextPos = (nextPos + 1) % max;
			if (pos < nextPos)
			{
				if (move[pos][I] == move[nextPos][I] && move[pos][J] < move[nextPos][J])
				{
					pos = nextPos;
					break;
				}
			}
			else if (pos > nextPos)
			{
				if (move[pos][I] == move[nextPos][I] && move[pos][J] > move[nextPos][J])
				{
					pos = nextPos;
					break;
				}
			}
			else if (nextPos == pos)
			{
				break;
			}
		}
		break;
	}
	}

	return pos;
}

// 게임 화면 조작.
#define STATE_SCREEN_START_I 21
#define STATE_SCREEN_START_J 2

#define ADD_SCREEN_I 8
#define ADD_SCREEN_J 8

#define EXP_MAX 5000

void screenOperator_PlayScreen(PDATA data)
{
REGAME:
	system("mode con cols=62 lines=28");
	system("cls");

	int checkMatrix = 0;

	/* 문제지 & 답지 생성 */
	int** answerMatrix = getMatrix_allocInitMatrixArr();
	int** questionMatrix = getMatrix_allocInitMatrixArr();

	setMatrix_setAnswerMatrix(answerMatrix, 0, 0);

	setMatrix_setQuestionMatrix(answerMatrix, questionMatrix, data);

	/* 표시지 생성 */ 
	int** writingSheet = getMatrix_copy2DMatrix(questionMatrix); /* questionMatrix와 동일 생성시에는 */

	PSTR_NODE list = getTextNode_allocInitHeader();
	
	setTextNode_addNodeToEnd(list, "[알림] 게임을 시작합니다.       ", LEFT);
	/* 상태창 라인수보다 초과 시, 지워 버리기 ! */
	if (getTextNode_getNodeMax(list) > 5)
	{
		setTextNode_eraseNodeToStart(list);
	}

	/* 답안지 저장 or 저장하지 않음.*/
	if (data->gameData->saveSheet_OnOff == true)
	{
		char directory[300] = { 0, };

		_getcwd(directory, 300);
		strcat(directory, "\\Saves");
		_chdir(directory);

		/* 질문지만 */
		if (data->gameData->saveSheet_saveType == QUESTION)
		{
			char* fileName = malloc(sizeof(char) * 50);
			memset(fileName, 0, sizeof(char) * 50);

			sprintf(fileName, "[Q]save(%d).txt", data->gameData->rate.total[0]);

			FILE* fp = fopen(fileName, "wt");
			if (fp == NULL)
			{
				printf("screenOperator_PlayScreen 함수 애러 : 파일 생성실패!");
			}

			char* blank = "\n";
			char* question = "/* 문제지 */\n";
			fwrite(question, strlen(question), 1, fp);

			PMATRIX_NODE matrix = getMatrixTextNode_allocInitMatrixStruct();
			setMatrixTextNode_setLinkedList(matrix, questionMatrix, data);
								
			PMATRIX_NODE curr = matrix->nextNode;
			while (curr != NULL)
			{
				fwrite(curr->str, strlen(curr->str), 1, fp);
				fwrite(blank, sizeof(char), 1, fp);
				curr = curr->nextNode;
			}

			setMatrixTextNode_freeNodes(matrix);
			free(matrix);

			free(fileName);
			fclose(fp);
		}
		/* 질문지 + 답안지 */
		else
		{
			char* fileName = malloc(sizeof(char) * 50);
			memset(fileName, 0, sizeof(char) * 50);

			sprintf(fileName, "[Q&A]save(%d).txt", data->gameData->rate.total[0]);

			FILE* fp = fopen(fileName, "w");

			if (fp == NULL)
			{
				printf("screenOperator_PlayScreen 함수 애러 : 파일 생성실패!");
			}

			char* blank = "\n";
			char* question = "/* 문제지 (Question Sheet) */\n";
			fwrite(question, strlen(question), 1, fp);

			PMATRIX_NODE aMatrix = getMatrixTextNode_allocInitMatrixStruct();
			setMatrixTextNode_setLinkedList(aMatrix, questionMatrix, data);

			PMATRIX_NODE curr = aMatrix->nextNode;
			while (curr != NULL)
			{
				fwrite(curr->str, strlen(curr->str), 1, fp);
				fwrite(blank, sizeof(char), 1, fp);
				curr = curr->nextNode;
			}

			setMatrixTextNode_freeNodes(aMatrix);
			free(aMatrix);

			char* answer = "\n\n/* 답안지 Answer Sheet */\n";
			fwrite(answer, strlen(answer), 1, fp);

			PMATRIX_NODE qMatrix = getMatrixTextNode_allocInitMatrixStruct();
			setMatrixTextNode_setLinkedList(qMatrix, answerMatrix, data);

			curr = qMatrix->nextNode;

			while (curr != NULL)
			{
				fwrite(curr->str, strlen(curr->str), 1, fp);
				fwrite(blank, sizeof(char), 1, fp);
				curr = curr->nextNode;
			}

			setMatrixTextNode_freeNodes(qMatrix);
			free(qMatrix);

			free(fileName);
			fclose(fp);
		}
		strcat(directory, "\\..");
		_chdir(directory);
	}
	

	/* 시작시 포인트 초기화. */ /* 일단 경험치 차단하고 시작함. */
	
	/* 게임 시작시 경험치가 차감되는걸 고려하여 계산 */
	int penaltyExp = (data->gameData->difficulty_tier + 1) * 5;

	/* 승리시 데이터 정리 */
	// 경험치, 레벨, 티어
	if (data->gameData->rate_exp - penaltyExp < 0)
	{
		/* 경험치 차감시 0보다 경험치가 적으면 0을 넣어줌.*/
		data->gameData->rate_exp = 0;
	}
	else
	{
		/* 경험치 차감시 0보다 적은 상황이 아니면 뺀값을 대입 */
		data->gameData->rate_exp = data->gameData->rate_exp - penaltyExp;
	}
	/* 레벨 구하기. */
	data->gameData->rate_level = data->gameData->rate_exp / (40 + (data->gameData->rate_exp / 40 * 10)) + 1;

	if (data->gameData->rate_level >= 31)
	{
		data->gameData->rate_myTier = 6;
	}
	else
	{
		data->gameData->rate_myTier = (data->gameData->rate_level - 1) / 5;
	}

	// 전체 승률
	data->gameData->rate.total[0] += 1; // 전
	data->gameData->rate.total[2] += 1; // 패
	data->gameData->rate.total[3] = data->gameData->rate.total[1] * 100 / data->gameData->rate.total[0];

	// 각 승률
	switch (data->gameData->difficulty_tier)
	{
	case BRONZE:
	{
		data->gameData->rate.bronze[0] += 1; // 전
		data->gameData->rate.bronze[2] += 1; // 패
		data->gameData->rate.bronze[3] = data->gameData->rate.bronze[1] * 100 / data->gameData->rate.bronze[0];
		break;
	}
	case SILVER:
	{
		data->gameData->rate.silver[0] += 1; // 전
		data->gameData->rate.silver[2] += 1; // 패
		data->gameData->rate.silver[3] = data->gameData->rate.silver[1] * 100 / data->gameData->rate.silver[0];
		break;
	}
	case GOLD:
	{
		data->gameData->rate.gold[0] += 1; // 전
		data->gameData->rate.gold[2] += 1; // 패
		data->gameData->rate.gold[3] = data->gameData->rate.gold[1] * 100 / data->gameData->rate.gold[0];
		break;
	}
	case PLATINUM:
	{
		data->gameData->rate.platinum[0] += 1; // 전
		data->gameData->rate.platinum[2] += 1; // 패
		data->gameData->rate.platinum[3] = data->gameData->rate.platinum[1] * 100 / data->gameData->rate.platinum[0];
		break;
	}
	case DIAMOND:
	{
		data->gameData->rate.diamond[0] += 1; // 전
		data->gameData->rate.diamond[2] += 1; // 패
		data->gameData->rate.diamond[3] = data->gameData->rate.diamond[1] * 100 / data->gameData->rate.diamond[0];
		break;
	}
	case MASTER:
	{
		data->gameData->rate.master[0] += 1; // 전
		data->gameData->rate.master[2] += 1; // 패
		data->gameData->rate.master[3] = data->gameData->rate.master[1] * 100 / data->gameData->rate.master[0];
		break;
	}
	case GRAND_MASTER:
	{
		data->gameData->rate.grandMaster[0] += 1; // 전
		data->gameData->rate.grandMaster[2] += 1; // 패
		data->gameData->rate.grandMaster[3] = data->gameData->rate.grandMaster[1] * 100 / data->gameData->rate.grandMaster[0];
		break;
	}
	}
	setDataStructure_saveStructure(data);
	


	/* 이동가능한 좌표를 구함 */
		// 공개되는 숫자 수
	int tier[7] = { 54, 46, 39, 33, 28, 24, 21 };
	int difficulty = MATRIX_MAX * tier[data->gameData->difficulty_tier] / 100;

		// 움직일 수 있는 공간 수, 그리고 좌표.
	int locationCount = MATRIX_MAX - difficulty;
	int inputLeft = locationCount;
	int** move = getGoto_cursorLocation_playScreen();

	char keyBoard;
	char** buffer;
BACK:
	/* text 정보를 가지고 있는 버퍼 생성 함 */
	buffer = buffer_screenTextToBuffer_PlayScreen(answerMatrix, writingSheet, data);
	int pos = 0;
	/* 키 조작 명령 */
	system("cls");
	printBuffer_char2DBuffer(buffer, PLAY_SCREEN_HEIGHT);

	if (data->gameData->designe_initValueMark_OnOff == true)
	{
		for (int i = 0; i < LINE_SIZE; i++)
		{
			for (int j = 0; j < LINE_SIZE; j++)
			{
				if (questionMatrix[i][j] != 0)
				{
					setGoto_setCursor((i * 2) + 1, (j * 4) + 3);
					printf("'");
				}
			}
		}
	}
	

	while (1)
	{
		MOVE_SET;
		screenText_PlayScreen_StateScreenScript_print(list);
		int i = (move[pos][I] - 1) / 2;
		int j = (move[pos][J] - 2) / 4;

		int* hintArr = getMatrix_getPossibleArr(writingSheet, i, j);
		
		/* 힌트 배열 출력 */
		if (writingSheet[i][j] == 0 && data->gameData->difficulty_hintArr_OnOff == true)
		{
			screenText_PlayScreen_HintScreenScript(hintArr, data, i, j, true);
			MOVE_SET;
		}
		else
		{
			screenText_PlayScreen_HintScreenScript(hintArr, data, i, j, false);
			MOVE_SET;	
		}
		free(hintArr);

		/* 검사하라는 문구 띄우기 */
		if (inputLeft == 0)
		{
			setTextNode_addNodeToEnd(list, "[완료] 정답체크. ENTER 누르세요   ", LEFT);
			/* 상태창 라인수보다 초과 시, 지워 버리기 ! */
			if (getTextNode_getNodeMax(list) > 5)
			{
				setTextNode_eraseNodeToStart(list);
			}
		}

		/* 키보드 입력 값 처리 */
		keyBoard = _getch();
		if (DIRECTION_KEY_COMMON(keyBoard))
		{
			keyBoard = _getch();

			/* Delete 키 */
			if (keyBoard == DELETE_KEY)
			{
				/* 상수 일때*/
				if (questionMatrix[i][j] != 0)
				{
					screenText_PlayScreen_StateScreenScript_Remove(list, true, true, i, j, writingSheet[i][j]);
				}
				else if (writingSheet[i][j] != 0) /* 입력한 값일때 */
				{
					screenText_PlayScreen_StateScreenScript_Remove(list, false, true, i, j, writingSheet[i][j]);
					MOVE_SET;
					printf("%c", ' ');
					writingSheet[i][j] = 0;
					inputLeft++;
				}
				else if (writingSheet[i][j] == 0) /* 아무 숫자도 없을 때*/
				{
					screenText_PlayScreen_StateScreenScript_Remove(list, false, false, i, j, questionMatrix[i][j]);
				}
			}

			/* 방향 키 이동 후 좌표 잡아줌 */
			pos = screenOperator_driectionKeyboard_playScreen(move, MATRIX_MAX, pos, keyBoard);
			MOVE_SET;
		}
		/* 숫자 입력 */
		else if (keyBoard >= ASCII_NUMBER + 1 && keyBoard <= ASCII_NUMBER + 9) // 숫자 키 입력시
		{
			/* 숫자가 있을 때 */
			if (writingSheet[i][j] != 0)
			{
				screenText_PlayScreen_StateScreenScript_Input(list, true, i, j, keyBoard - ASCII_NUMBER);
			}/* 숫자가 없을 때 */
			else if (writingSheet[i][j] == 0)
			{
				bool overlap = false;
				hintArr = getMatrix_getPossibleArr(writingSheet, i, j);
				for (int i = 0; i < getArr9_getArrSize(hintArr); i++)
				{
					/* 겹치면 맞는거임*/
					if (keyBoard - ASCII_NUMBER == hintArr[i])
					{
						overlap = true;
					}

				}

				/* 겹치는 수 발견*/
				if (overlap == false)
				{
					setTextNode_addNodeToEnd(list, "[애러] 겹치는 숫자가 있습니다.  ", LEFT);
					/* 상태창 라인수보다 초과 시, 지워 버리기 ! */
					if (getTextNode_getNodeMax(list) > 5)
					{
						setTextNode_eraseNodeToStart(list);
					}
				}
				else
				{
					screenText_PlayScreen_StateScreenScript_Input(list, false, i, j, keyBoard - ASCII_NUMBER);

					MOVE_SET;
					printf("%d", keyBoard - ASCII_NUMBER);
					writingSheet[i][j] = keyBoard - ASCII_NUMBER;
					inputLeft--;
				}
				free(hintArr);
			}
		}
		/* 지우기 */
		else if (keyBoard == ERASE_KEY)
		{
			/* 상수 일때*/
			if (questionMatrix[i][j] != 0)
			{
				screenText_PlayScreen_StateScreenScript_Remove(list, true, true, i, j, writingSheet[i][j]);
			}
			else if (writingSheet[i][j] != 0) /* 입력한 값일때 */
			{
				screenText_PlayScreen_StateScreenScript_Remove(list, false, true, i, j, writingSheet[i][j]);
				MOVE_SET;
				printf("%c", ' ');
				writingSheet[i][j] = 0;
				inputLeft++;
			}
			else if (writingSheet[i][j] == 0) /* 아무 숫자도 없을 때*/
			{
				screenText_PlayScreen_StateScreenScript_Remove(list, false, false, i, j, questionMatrix[i][j]);
			}
		}
		/* 옵션 */
		else if (keyBoard == OPTION_KEY)
		{
			/* 입력값 stateScreen */
			screenText_PlayScreen_StateScreenScript_ExtraKey(list, OPTION_KEY, checkMatrix);

			/* stateScreen 출력 */
			screenText_PlayScreen_StateScreenScript_print(list);

			/* 입력값 처리 */
			screenText_PlayScreen_OptionScreen(data);

			/* 옵션창 빠져나옴 */
			screenText_PlayScreen_StateScreenScript_ExtraKey_Out(list, 1);

			/* stateScreen 출력 */
			screenText_PlayScreen_StateScreenScript_print(list);

			/* 설정값 바이너리 파일에 저장.*/
			setDataStructure_saveStructure(data);

			goto BACK;
		}
		/* 스도쿠 검사 */
		else if (keyBoard == ENTER_KEY)
		{
			checkMatrix++;
			/* Satate Screen 노드 */
			screenText_PlayScreen_StateScreenScript_ExtraKey(list, ENTER_KEY, checkMatrix);

			/* Satate Screen 출력 */
			screenText_PlayScreen_StateScreenScript_print(list);

			/* 입력값 처리 */
			bool check = checkMatrix_all(writingSheet);
			if (check == true) // 참
			{
				if (screenText_PlayScreen_EnterScreen_Win(data, ADD_SCREEN_I, ADD_SCREEN_J)) // 이김
				{
					goto REGAME;
				}
				else
				{
					return;
				}
			}
			else if (check == false)// 거짓
			{
				if (checkMatrix == 3)
				{
					/* 패배 게임 재시작 */
					if (screenText_PlayScreen_EnterScreen_GameOver(data->gameData->rate_level, ADD_SCREEN_I, ADD_SCREEN_J))
					{
						goto REGAME;
					}
					/* 패배 메인으로 */
					else
					{
						return;
					}
				}
				if (screenText_PlayScreen_EnterScreen_Lost(checkMatrix, data->gameData->rate_level, ADD_SCREEN_I, ADD_SCREEN_J) == false)
				{
					return;
				}
			}

			/* 옵션창 빠져나옴 */
			screenText_PlayScreen_StateScreenScript_ExtraKey_Out(list, 2);

			/* stateScreen 출력 */
			screenText_PlayScreen_StateScreenScript_print(list);
			goto BACK;
		}
		/* 종료 */
		else if (keyBoard == ESCAPE_KEY)
		{
			/* Satate Screen 노드 */
			screenText_PlayScreen_StateScreenScript_ExtraKey(list, ESCAPE_KEY, checkMatrix);

			/* Satate Screen 출력 */
			screenText_PlayScreen_StateScreenScript_print(list);

			/* 탈출 Y / N */
			if (screenText_PlayScreen_EscapeScreen(data->gameData->rate_level, ADD_SCREEN_I, ADD_SCREEN_J) == true)
			{
				return;
			}

			/* 옵션창 빠져나옴 */
			screenText_PlayScreen_StateScreenScript_ExtraKey_Out(list, 3);

			/* stateScreen 출력 */
			screenText_PlayScreen_StateScreenScript_print(list);

			goto BACK;
		}
	}

	/* 할당 해제 */
	setMatrix_freeMatrixArr(answerMatrix);
	setMatrix_freeMatrixArr(questionMatrix);
	setMatrix_freeMatrixArr(writingSheet);
	setGoto_freeCursorLocationArr(move, locationCount);
	setBuffer_freeChar2DBuffer(buffer, PLAY_SCREEN_HEIGHT);

	return;
}

