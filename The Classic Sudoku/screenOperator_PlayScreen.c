// screenOperator_PlayScreen.c ��Ʈ��

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

// �÷���ȭ�� ��ǥ �̵�.
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

// ���� ȭ�� ����.
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

	/* ������ & ���� ���� */
	int** answerMatrix = getMatrix_allocInitMatrixArr();
	int** questionMatrix = getMatrix_allocInitMatrixArr();

	setMatrix_setAnswerMatrix(answerMatrix, 0, 0);

	setMatrix_setQuestionMatrix(answerMatrix, questionMatrix, data);

	/* ǥ���� ���� */ 
	int** writingSheet = getMatrix_copy2DMatrix(questionMatrix); /* questionMatrix�� ���� �����ÿ��� */

	PSTR_NODE list = getTextNode_allocInitHeader();
	
	setTextNode_addNodeToEnd(list, "[�˸�] ������ �����մϴ�.       ", LEFT);
	/* ����â ���μ����� �ʰ� ��, ���� ������ ! */
	if (getTextNode_getNodeMax(list) > 5)
	{
		setTextNode_eraseNodeToStart(list);
	}

	/* ����� ���� or �������� ����.*/
	if (data->gameData->saveSheet_OnOff == true)
	{
		char directory[300] = { 0, };

		_getcwd(directory, 300);
		strcat(directory, "\\Saves");
		_chdir(directory);

		/* �������� */
		if (data->gameData->saveSheet_saveType == QUESTION)
		{
			char* fileName = malloc(sizeof(char) * 50);
			memset(fileName, 0, sizeof(char) * 50);

			sprintf(fileName, "[Q]save(%d).txt", data->gameData->rate.total[0]);

			FILE* fp = fopen(fileName, "wt");
			if (fp == NULL)
			{
				printf("screenOperator_PlayScreen �Լ� �ַ� : ���� ��������!");
			}

			char* blank = "\n";
			char* question = "/* ������ */\n";
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
		/* ������ + ����� */
		else
		{
			char* fileName = malloc(sizeof(char) * 50);
			memset(fileName, 0, sizeof(char) * 50);

			sprintf(fileName, "[Q&A]save(%d).txt", data->gameData->rate.total[0]);

			FILE* fp = fopen(fileName, "w");

			if (fp == NULL)
			{
				printf("screenOperator_PlayScreen �Լ� �ַ� : ���� ��������!");
			}

			char* blank = "\n";
			char* question = "/* ������ (Question Sheet) */\n";
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

			char* answer = "\n\n/* ����� Answer Sheet */\n";
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
	

	/* ���۽� ����Ʈ �ʱ�ȭ. */ /* �ϴ� ����ġ �����ϰ� ������. */
	
	/* ���� ���۽� ����ġ�� �����Ǵ°� ����Ͽ� ��� */
	int penaltyExp = (data->gameData->difficulty_tier + 1) * 5;

	/* �¸��� ������ ���� */
	// ����ġ, ����, Ƽ��
	if (data->gameData->rate_exp - penaltyExp < 0)
	{
		/* ����ġ ������ 0���� ����ġ�� ������ 0�� �־���.*/
		data->gameData->rate_exp = 0;
	}
	else
	{
		/* ����ġ ������ 0���� ���� ��Ȳ�� �ƴϸ� ������ ���� */
		data->gameData->rate_exp = data->gameData->rate_exp - penaltyExp;
	}
	/* ���� ���ϱ�. */
	data->gameData->rate_level = data->gameData->rate_exp / (40 + (data->gameData->rate_exp / 40 * 10)) + 1;

	if (data->gameData->rate_level >= 31)
	{
		data->gameData->rate_myTier = 6;
	}
	else
	{
		data->gameData->rate_myTier = (data->gameData->rate_level - 1) / 5;
	}

	// ��ü �·�
	data->gameData->rate.total[0] += 1; // ��
	data->gameData->rate.total[2] += 1; // ��
	data->gameData->rate.total[3] = data->gameData->rate.total[1] * 100 / data->gameData->rate.total[0];

	// �� �·�
	switch (data->gameData->difficulty_tier)
	{
	case BRONZE:
	{
		data->gameData->rate.bronze[0] += 1; // ��
		data->gameData->rate.bronze[2] += 1; // ��
		data->gameData->rate.bronze[3] = data->gameData->rate.bronze[1] * 100 / data->gameData->rate.bronze[0];
		break;
	}
	case SILVER:
	{
		data->gameData->rate.silver[0] += 1; // ��
		data->gameData->rate.silver[2] += 1; // ��
		data->gameData->rate.silver[3] = data->gameData->rate.silver[1] * 100 / data->gameData->rate.silver[0];
		break;
	}
	case GOLD:
	{
		data->gameData->rate.gold[0] += 1; // ��
		data->gameData->rate.gold[2] += 1; // ��
		data->gameData->rate.gold[3] = data->gameData->rate.gold[1] * 100 / data->gameData->rate.gold[0];
		break;
	}
	case PLATINUM:
	{
		data->gameData->rate.platinum[0] += 1; // ��
		data->gameData->rate.platinum[2] += 1; // ��
		data->gameData->rate.platinum[3] = data->gameData->rate.platinum[1] * 100 / data->gameData->rate.platinum[0];
		break;
	}
	case DIAMOND:
	{
		data->gameData->rate.diamond[0] += 1; // ��
		data->gameData->rate.diamond[2] += 1; // ��
		data->gameData->rate.diamond[3] = data->gameData->rate.diamond[1] * 100 / data->gameData->rate.diamond[0];
		break;
	}
	case MASTER:
	{
		data->gameData->rate.master[0] += 1; // ��
		data->gameData->rate.master[2] += 1; // ��
		data->gameData->rate.master[3] = data->gameData->rate.master[1] * 100 / data->gameData->rate.master[0];
		break;
	}
	case GRAND_MASTER:
	{
		data->gameData->rate.grandMaster[0] += 1; // ��
		data->gameData->rate.grandMaster[2] += 1; // ��
		data->gameData->rate.grandMaster[3] = data->gameData->rate.grandMaster[1] * 100 / data->gameData->rate.grandMaster[0];
		break;
	}
	}
	setDataStructure_saveStructure(data);
	


	/* �̵������� ��ǥ�� ���� */
		// �����Ǵ� ���� ��
	int tier[7] = { 54, 46, 39, 33, 28, 24, 21 };
	int difficulty = MATRIX_MAX * tier[data->gameData->difficulty_tier] / 100;

		// ������ �� �ִ� ���� ��, �׸��� ��ǥ.
	int locationCount = MATRIX_MAX - difficulty;
	int inputLeft = locationCount;
	int** move = getGoto_cursorLocation_playScreen();

	char keyBoard;
	char** buffer;
BACK:
	/* text ������ ������ �ִ� ���� ���� �� */
	buffer = buffer_screenTextToBuffer_PlayScreen(answerMatrix, writingSheet, data);
	int pos = 0;
	/* Ű ���� ��� */
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
		
		/* ��Ʈ �迭 ��� */
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

		/* �˻��϶�� ���� ���� */
		if (inputLeft == 0)
		{
			setTextNode_addNodeToEnd(list, "[�Ϸ�] ����üũ. ENTER ��������   ", LEFT);
			/* ����â ���μ����� �ʰ� ��, ���� ������ ! */
			if (getTextNode_getNodeMax(list) > 5)
			{
				setTextNode_eraseNodeToStart(list);
			}
		}

		/* Ű���� �Է� �� ó�� */
		keyBoard = _getch();
		if (DIRECTION_KEY_COMMON(keyBoard))
		{
			keyBoard = _getch();

			/* Delete Ű */
			if (keyBoard == DELETE_KEY)
			{
				/* ��� �϶�*/
				if (questionMatrix[i][j] != 0)
				{
					screenText_PlayScreen_StateScreenScript_Remove(list, true, true, i, j, writingSheet[i][j]);
				}
				else if (writingSheet[i][j] != 0) /* �Է��� ���϶� */
				{
					screenText_PlayScreen_StateScreenScript_Remove(list, false, true, i, j, writingSheet[i][j]);
					MOVE_SET;
					printf("%c", ' ');
					writingSheet[i][j] = 0;
					inputLeft++;
				}
				else if (writingSheet[i][j] == 0) /* �ƹ� ���ڵ� ���� ��*/
				{
					screenText_PlayScreen_StateScreenScript_Remove(list, false, false, i, j, questionMatrix[i][j]);
				}
			}

			/* ���� Ű �̵� �� ��ǥ ����� */
			pos = screenOperator_driectionKeyboard_playScreen(move, MATRIX_MAX, pos, keyBoard);
			MOVE_SET;
		}
		/* ���� �Է� */
		else if (keyBoard >= ASCII_NUMBER + 1 && keyBoard <= ASCII_NUMBER + 9) // ���� Ű �Է½�
		{
			/* ���ڰ� ���� �� */
			if (writingSheet[i][j] != 0)
			{
				screenText_PlayScreen_StateScreenScript_Input(list, true, i, j, keyBoard - ASCII_NUMBER);
			}/* ���ڰ� ���� �� */
			else if (writingSheet[i][j] == 0)
			{
				bool overlap = false;
				hintArr = getMatrix_getPossibleArr(writingSheet, i, j);
				for (int i = 0; i < getArr9_getArrSize(hintArr); i++)
				{
					/* ��ġ�� �´°���*/
					if (keyBoard - ASCII_NUMBER == hintArr[i])
					{
						overlap = true;
					}

				}

				/* ��ġ�� �� �߰�*/
				if (overlap == false)
				{
					setTextNode_addNodeToEnd(list, "[�ַ�] ��ġ�� ���ڰ� �ֽ��ϴ�.  ", LEFT);
					/* ����â ���μ����� �ʰ� ��, ���� ������ ! */
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
		/* ����� */
		else if (keyBoard == ERASE_KEY)
		{
			/* ��� �϶�*/
			if (questionMatrix[i][j] != 0)
			{
				screenText_PlayScreen_StateScreenScript_Remove(list, true, true, i, j, writingSheet[i][j]);
			}
			else if (writingSheet[i][j] != 0) /* �Է��� ���϶� */
			{
				screenText_PlayScreen_StateScreenScript_Remove(list, false, true, i, j, writingSheet[i][j]);
				MOVE_SET;
				printf("%c", ' ');
				writingSheet[i][j] = 0;
				inputLeft++;
			}
			else if (writingSheet[i][j] == 0) /* �ƹ� ���ڵ� ���� ��*/
			{
				screenText_PlayScreen_StateScreenScript_Remove(list, false, false, i, j, questionMatrix[i][j]);
			}
		}
		/* �ɼ� */
		else if (keyBoard == OPTION_KEY)
		{
			/* �Է°� stateScreen */
			screenText_PlayScreen_StateScreenScript_ExtraKey(list, OPTION_KEY, checkMatrix);

			/* stateScreen ��� */
			screenText_PlayScreen_StateScreenScript_print(list);

			/* �Է°� ó�� */
			screenText_PlayScreen_OptionScreen(data);

			/* �ɼ�â �������� */
			screenText_PlayScreen_StateScreenScript_ExtraKey_Out(list, 1);

			/* stateScreen ��� */
			screenText_PlayScreen_StateScreenScript_print(list);

			/* ������ ���̳ʸ� ���Ͽ� ����.*/
			setDataStructure_saveStructure(data);

			goto BACK;
		}
		/* ������ �˻� */
		else if (keyBoard == ENTER_KEY)
		{
			checkMatrix++;
			/* Satate Screen ��� */
			screenText_PlayScreen_StateScreenScript_ExtraKey(list, ENTER_KEY, checkMatrix);

			/* Satate Screen ��� */
			screenText_PlayScreen_StateScreenScript_print(list);

			/* �Է°� ó�� */
			bool check = checkMatrix_all(writingSheet);
			if (check == true) // ��
			{
				if (screenText_PlayScreen_EnterScreen_Win(data, ADD_SCREEN_I, ADD_SCREEN_J)) // �̱�
				{
					goto REGAME;
				}
				else
				{
					return;
				}
			}
			else if (check == false)// ����
			{
				if (checkMatrix == 3)
				{
					/* �й� ���� ����� */
					if (screenText_PlayScreen_EnterScreen_GameOver(data->gameData->rate_level, ADD_SCREEN_I, ADD_SCREEN_J))
					{
						goto REGAME;
					}
					/* �й� �������� */
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

			/* �ɼ�â �������� */
			screenText_PlayScreen_StateScreenScript_ExtraKey_Out(list, 2);

			/* stateScreen ��� */
			screenText_PlayScreen_StateScreenScript_print(list);
			goto BACK;
		}
		/* ���� */
		else if (keyBoard == ESCAPE_KEY)
		{
			/* Satate Screen ��� */
			screenText_PlayScreen_StateScreenScript_ExtraKey(list, ESCAPE_KEY, checkMatrix);

			/* Satate Screen ��� */
			screenText_PlayScreen_StateScreenScript_print(list);

			/* Ż�� Y / N */
			if (screenText_PlayScreen_EscapeScreen(data->gameData->rate_level, ADD_SCREEN_I, ADD_SCREEN_J) == true)
			{
				return;
			}

			/* �ɼ�â �������� */
			screenText_PlayScreen_StateScreenScript_ExtraKey_Out(list, 3);

			/* stateScreen ��� */
			screenText_PlayScreen_StateScreenScript_print(list);

			goto BACK;
		}
	}

	/* �Ҵ� ���� */
	setMatrix_freeMatrixArr(answerMatrix);
	setMatrix_freeMatrixArr(questionMatrix);
	setMatrix_freeMatrixArr(writingSheet);
	setGoto_freeCursorLocationArr(move, locationCount);
	setBuffer_freeChar2DBuffer(buffer, PLAY_SCREEN_HEIGHT);

	return;
}

