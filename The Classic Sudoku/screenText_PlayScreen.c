// screenText_PlayScreen.c ������ ���� ����ȭ�� ���õ� �ؽ�Ʈ ���� �Լ�.

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

// ��Ʈ���� ������ Linked List�� �������ִ� �Լ�.
void screenText_PlayScreen_Matrix(int** answerMatrix, int** questionMatrix, PMATRIX_NODE list, PDATA data)
{
	/* Linked List ȭ */ /* �ڽ�ó�� ���� �Ǿ�����.*/
	setMatrixTextNode_setLinkedList(list, questionMatrix, data);

	return;
}

// ��Ʈ�� �ȳ���
void screenText_PlayScreen_ControlScreen(PSTR_NODE list)
{
	setTextNode_addNodeToEnd(list, " [ C O N T R O L _ ]", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  * �̵� �ϱ�", LEFT);
	setTextNode_addNodeToEnd(list, "        [��]", LEFT);
	setTextNode_addNodeToEnd(list, "   [��] [��] [��] ", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  * ���� �Է�", LEFT);
	setTextNode_addNodeToEnd(list, "   [ 1 ] ~ [ 9 ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  * ���� ����", LEFT);
	setTextNode_addNodeToEnd(list, "   [ ��Backspace ]", LEFT);
	setTextNode_addNodeToEnd(list, "   [ Delete ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  * �ɼ�â - [ O ]", LEFT);
	setTextNode_addNodeToEnd(list, "  * �˻� - [ ENTER ]", LEFT);
	setTextNode_addNodeToEnd(list, "  * ���� - [ ESC ]", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);

	return;
}

// ����â
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

// ����â ����
#define ASCII_NUMBER 48
#define MATRIX_WIDTH 37

#define STATE_SCREEN_START_I 21
#define STATE_SCREEN_START_J 2

/* ����â�� ������� �Լ�. */
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

/* 1~9������ ���� �Է��� ����â���� ���� �� ��� */
void screenText_PlayScreen_StateScreenScript_Input(PSTR_NODE list, bool numberExist, int i, int j, int matrix)
{
	char* str = malloc(sizeof(char) * MATRIX_WIDTH + 1);
	memset(str, 0, sizeof(char) * MATRIX_WIDTH + 1);

	/* ���ڰ� �ִ� ���� �Է� �Ұ�*/
	if (numberExist)
	{
		sprintf(str, "[����] (%d %d) ���� �̹� ���ݾ�  ", i, j); 
	}
	else /* ���ڰ� ���� ���� �Է� ���� */
	{
		sprintf(str, "[�Է�] (%d %d) <--- %d �Է� ���� ", i, j, matrix);
	}

	setTextNode_addNodeToEnd(list, str, LEFT);

	/* ����â ���μ����� �ʰ� ��, ���� ������ ! */
	if (getTextNode_getNodeMax(list) > 5)
	{
		setTextNode_eraseNodeToStart(list);
	}

	/* �Ҵ� ���� */
	free(str);

	return;
}

/* ���� ����� �Է� ����â���� ���� �� ���.*/
void screenText_PlayScreen_StateScreenScript_Remove(PSTR_NODE list, bool initNumber, bool numberExist, int i, int j, int matrix)
{
	char* str = malloc(sizeof(char) * MATRIX_WIDTH + 1);
	memset(str, 0, sizeof(char) * MATRIX_WIDTH + 1);

	/* �ش� ��ǥ�� �ʱ갪�� ���.*/ /* ����� ������ٰ� ����*/
	if (initNumber)
	{
		sprintf(str, "[�ȵ�] (%d %d) �ʱⰪ ���� ������", i, j);
	}
	else /* �ʱⰪ �ƴ� */
	{
		/* �ʱⰪ�� �ƴѵ� ���ڰ� ���� ��� */
		if (numberExist)
		{
			sprintf(str, "[����] (%d %d) ---> %d ���� ���� ", i, j, matrix);
		}
		else /* �ʱⰪ�� �ƴѵ� ���ڰ� ���� ��� */
		{

			sprintf(str, "[����] (%d %d) ���µ� ��� ����", i, j);
		}

	}

	setTextNode_addNodeToEnd(list, str, LEFT);

	/* ����â ���μ����� �ʰ� ��, ���� ������ ! */
	if (getTextNode_getNodeMax(list) > 5)
	{
		setTextNode_eraseNodeToStart(list);
	}

	/* �Ҵ� ���� */
	free(str);

	return;
}

/* ��Ÿ �Է��� �������� */
void screenText_PlayScreen_StateScreenScript_ExtraKey(PSTR_NODE list, int keyBoard, int max)
{
	char* str = malloc(sizeof(char) * MATRIX_WIDTH + 1);
	memset(str, 0, sizeof(char) * MATRIX_WIDTH + 1);


	if (keyBoard == ENTER_)
	{
		sprintf(str, "[�˻�] ������ ���� Ȯ�� %d / 3 ", max);
	}
	else if (keyBoard == OPTION_)
	{
		sprintf(str, "[�ɼ�] �ɼ�â�� ���� �߽��ϴ�.   ");
	}
	else if (keyBoard == ESCAPE_)
	{
		sprintf(str, "[����] ����â�� ���� �߽��ϴ�.   ");
	}
	
	setTextNode_addNodeToEnd(list, str, LEFT);

	/* ����â ���μ����� �ʰ� ��, ���� ������ ! */
	if (getTextNode_getNodeMax(list) > 5)
	{
		setTextNode_eraseNodeToStart(list);
	}

	/* �Ҵ� ���� */
	free(str);

	return;
}

/* ��Ÿ �Է� Ż��� */
void screenText_PlayScreen_StateScreenScript_ExtraKey_Out(PSTR_NODE list, int index)
{
	char* str = malloc(sizeof(char) * MATRIX_WIDTH + 1);
	memset(str, 0, sizeof(char) * MATRIX_WIDTH + 1);

	switch(index)
	{
	case 1:
	{
		sprintf(str, "[�ɼ�] ���� ������ �����߽��ϴ�.");
		break;
	}
	case 2:
	{
		sprintf(str, "[�˻�] �˻縦 ����������߽��ϴ�.");
		break;
	}
	case 3:
	{
		sprintf(str, "[����] �������� �ٽ� �����մϴ�.");
		break;
	}
	}
	

	setTextNode_addNodeToEnd(list, str, LEFT);

	/* ����â ���μ����� �ʰ� ��, ���� ������ ! */
	if (getTextNode_getNodeMax(list) > 5)
	{
		setTextNode_eraseNodeToStart(list);
	}

	/* �Ҵ� ���� */
	free(str);
}

// ��Ʈ �迭
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

// ��Ʈ �迭 ����
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

	/* ���� �Է� ON*/
	if (generate)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				/* �迭�� ���ڿ� ��ǥ�� ��ġ �Ҷ� */
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
	else /* ���� �Է� OFF*/
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


/* ���⼭���ʹ� ���� â. */
/* �ɼ� - O */

#define TEMP_I 6
#define TEMP_J 9

#define OPTION_MOVE_MAX 11
/* �ɼǽ�ũ���� ���õ� �Լ�. ���, �� ���� �� */
void screenText_PlayScreen_OptionScreen(PDATA data)
{
	/* Linked List ���� */
	PSTR_NODE list = getTextNode_allocInitHeader();

	setTextNode_addNodeToEnd(list, "< O P T I O N >", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, " * �⺻�� ' ǥ��       * ����", LEFT);
	setTextNode_addNodeToEnd(list, "   ON [ ]  OFF [ ]       ON [ ]  OFF [ ]  ", LEFT);
	setTextNode_addNodeToEnd(list, "                        ", LEFT);
	setTextNode_addNodeToEnd(list, " * ��輱 ������       * ���� ����", LEFT);
	setTextNode_addNodeToEnd(list, "   �⺻��      [ ]       ���� ���   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "   ��  ��      [ ]       �˼� ���   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "   ��缱 ǥ�� [ ]       BGM  ���   [ ]", LEFT);
	setTextNode_addNodeToEnd(list, "   ��輱 ���� [ ]        [ESC] - â�ݱ�  ", LEFT);
	setTextNode_addNodeToEnd(list, "", LEFT);

	setBoxedNode_addBoxNode(list, 0);

	/* ��� */
	PSTR_NODE curr;

	/* ���� */ /* ���� ��ġ�� �˷������ */
	int** move = getGoto_cursorLocation_Node(list, OPTION_MOVE_MAX, TEMP_I - 1, TEMP_J + 1);
	int pos = 0;
	int flag;

BACK:
	/* Ŀ���� ���� ��ġ ��� */
	flag = pos;
	MOVE_SET;

	curr = list->nextNode;

	/* ȭ�� ��� */
	int count = 0;
	while (curr != NULL)
	{
		setGoto_setCursor(TEMP_I + count++, TEMP_J);
		printf("%s", curr->str);
		
		curr = curr->nextNode;
	}

	/* Data �о�ͼ� V ǥ�� ���ִ� �۾� */
	// ǥ�� ON / OFF
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

	// ���� ON / OFF
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
	

	// ��輱 ������
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

	// ���� TYPE
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
		/* ����Ű ���� */
		if (DIRECTION_KEY_COMMON(keyBoard))
		{
			keyBoard = _getch();
			pos = screenOperator_driectionKeyboard_playScreen(move, OPTION_MOVE_MAX, pos, keyBoard);
		}
		/* ���͸� ��������. */
		else if (keyBoard == ENTER_KEY)
		{
			switch (pos)
			{
			/* �⺻�� ON / OFF */
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
			/* ���� ON / OFF */
			case 2: // ON
			{
				/* �̹� ������������ Ű���Է��� �ҿ�����ϱ� �����ִ°�� ���Է��� ������, ����������� ����Ȱɷ�.*/
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
				/* ���������� ������������ ����.*/
				if (data->gameData->music_OnOff == true)
				{
					PlaySound(NULL, NULL, 0);
					data->gameData->music_OnOff = false;
				}

				goto BACK;
			}
			/* ��輱 ������ - �⺻�� */
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
			/* ���� ���� */
			// ���� ����ȰͰ� �ٸ� ������ ��� �ð�쿡�� �۵���.
			case 5:
			{
				if (data->gameData->music_playList != K_POP)
				{
					data->gameData->music_playList = K_POP;
					if (data->gameData->music_OnOff == true) // �Ҹ�����������,
					{
						PlaySound(NULL, NULL, 0); // ������,
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
					if (data->gameData->music_OnOff == true) // �Ҹ�����������,
					{
						PlaySound(NULL, NULL, 0); // ������,
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
					if (data->gameData->music_OnOff == true) // �Ҹ�����������,
					{
						PlaySound(NULL, NULL, 0); // ������,
						char* directory = screenOperator_MainScreen_Option_Music(data);
						PlaySound(TEXT(directory), NULL, SND_ASYNC | SND_LOOP);
						free(directory);
					}
				}
				goto BACK;
			}
			}
		}
		/* ESC Ű�� ��������. */
		else if (keyBoard == ESCAPE_KEY)
		{
			return;
		}
	}

	/* �Ҵ� ���� */
	setTextNode_freeNodes(list);
	setGoto_freeCursorLocationArr(move, OPTION_MOVE_MAX);
	free(list);

	return;
}

/* Ű���� ���� �޾Ƽ� Ŀ���� �̵� �����ִ� �Լ�.*/
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
/* �˻� - ������ ��� �� */
// �¸� true - ����� false - main ȭ��
bool screenText_PlayScreen_EnterScreen_Win(PDATA data, int start_i, int start_j)
{
	bool ret;
	
	PSTR_NODE list = getTextNode_allocInitHeader();

	char* str = malloc(sizeof(char) * STR_SIZE);
	memset(str, 0, sizeof(char) * STR_SIZE);
	char* str2 = malloc(sizeof(char) * STR_SIZE);
	memset(str2, 0, sizeof(char) * STR_SIZE);

	/* ���� ���۽� ����ġ�� �����Ǵ°� ����Ͽ� ��� */
	int exp;

	if (data->gameData->rate_exp == 0)
	{
		// ����ġ�� 0�϶�.
		exp = (data->gameData->difficulty_tier + 1) * 5 * 2;
	}
	else
	{
		// �ƴҶ�
		exp = (data->gameData->difficulty_tier + 1) * 5 * 3;
	}

	int displayExp = (data->gameData->difficulty_tier + 1) * 5 * 2;

	/* �¸��� ������ ���� */
	// ����ġ, ����, Ƽ��
	if (data->gameData->difficulty_hintArr_OnOff == false)
	{
		exp *= 2; // ��Ʈ off�� ����ġ 200% ����
	}

	/* ����ġ �߰� */
	data->gameData->rate_exp += exp;
	/* ���� ��� */
	data->gameData->rate_level = data->gameData->rate_exp / ( 40 + (data->gameData->rate_exp / 40 * 10)) + 1;

	if (data->gameData->rate_level >= 31)
	{
		data->gameData->rate_myTier = 6;
	}
	else
	{
		data->gameData->rate_myTier = (data->gameData->rate_level - 1) / 5;
	}

	// ��ü �·�
	data->gameData->rate.total[1] += 1; // ��
	data->gameData->rate.total[2] -= 1; // ��
	data->gameData->rate.total[3] = data->gameData->rate.total[1] * 100 / data->gameData->rate.total[0];

	// �� �·�
	switch (data->gameData->difficulty_tier)
	{
	case BRONZE:
	{
		data->gameData->rate.bronze[1] += 1; // ��
		data->gameData->rate.bronze[2] -= 1; // ��
		data->gameData->rate.bronze[3] = data->gameData->rate.bronze[1] * 100 / data->gameData->rate.bronze[0];
		break;
	}
	case SILVER:
	{
		data->gameData->rate.silver[1] += 1; // ��
		data->gameData->rate.silver[2] -= 1; // ��
		data->gameData->rate.silver[3] = data->gameData->rate.silver[1] * 100 / data->gameData->rate.silver[0];
		break;
	}
	case GOLD:
	{
		data->gameData->rate.gold[1] += 1; // ��
		data->gameData->rate.gold[2] -= 1; // ��
		data->gameData->rate.gold[3] = data->gameData->rate.gold[1] * 100 / data->gameData->rate.gold[0];
		break;
	}
	case PLATINUM:
	{
		data->gameData->rate.platinum[1] += 1; // ��
		data->gameData->rate.platinum[2] -= 1; // ��
		data->gameData->rate.platinum[3] = data->gameData->rate.platinum[1] * 100 / data->gameData->rate.platinum[0];
		break;
	}
	case DIAMOND:
	{
		data->gameData->rate.diamond[1] += 1; // ��
		data->gameData->rate.diamond[2] -= 1; // ��
		data->gameData->rate.diamond[3] = data->gameData->rate.diamond[1] * 100 / data->gameData->rate.diamond[0];
		break;
	}
	case MASTER:
	{
		data->gameData->rate.master[1] += 1; // ��
		data->gameData->rate.master[2] -= 1; // ��
		data->gameData->rate.master[3] = data->gameData->rate.master[1] * 100 / data->gameData->rate.master[0];
		break;
	}
	case GRAND_MASTER:
	{
		data->gameData->rate.grandMaster[1] += 1; // ��
		data->gameData->rate.grandMaster[2] -= 1; // ��
		data->gameData->rate.grandMaster[3] = data->gameData->rate.grandMaster[1] * 100 / data->gameData->rate.grandMaster[0];
		break;
	}
	}

	setDataStructure_saveStructure(data);

	/* �迭 ��� */
	
	setTextNode_addNodeToEnd(list, "< Y O U _ W I N >", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);

	switch (data->gameData->rate_myTier)
	{
	case BRONZE:
	{
		sprintf(str, " * ����� [ BRONZE ] Ŭ����");
		break;
	}
	case SILVER:
	{
		sprintf(str, " * �ǹ� [ SILVER ] Ŭ����");

		break;
	}
	case GOLD:
	{
		sprintf(str, " * ��� [ GOLD ] Ŭ����");

		break;
	}
	case PLATINUM:
	{
		sprintf(str, " * �÷�Ƽ�� [ PLATINUM ] Ŭ����");

		break;
	}
	case DIAMOND:
	{
		sprintf(str, " * ���̾Ƹ�� [ DIAMOND ] Ŭ����");

		break;
	}
	case MASTER:
	{
		sprintf(str, " * ������ [ MASTER ] Ŭ����");

		break;
	}
	case GRAND_MASTER:
	{
		sprintf(str, " * �׷��� ������ [ GRAND MASTER ] Ŭ����");

		break;
	}
	}
	setTextNode_addNodeToEnd(list, str, LEFT);
	memset(str, 0, sizeof(char) * STR_SIZE);

	
	if (data->gameData->difficulty_hintArr_OnOff == true)
	{
		sprintf(str, "[ �������� + %2d Exp�� ����ϴ�. (��ƮON) ]", displayExp);
	}
	else
	{
		sprintf(str, "[ �������� + %2d Exp�� ����ϴ�. (��ƮOFF) ]", displayExp);
	}
	
	setTextNode_addNodeToEnd(list, str, MIDDLE);
	memset(str, 0, sizeof(char) * STR_SIZE);

	switch(data->gameData->rate_myTier)
	{
	case BRONZE:
	{
		sprintf(str, "* ���� Ƽ�� : ����� [ BROANZE ]");
		sprintf(str2, "[ Level - %2d ]  [ Exp - %4d ]", data->gameData->rate_level, data->gameData->rate_exp);
		break;
	}
	case SILVER:
	{
		sprintf(str, "* ���� Ƽ�� : �ǹ� [ SILVER ]");
		sprintf(str2, "[ Level - %2d ]  [ Exp - %4d ]", data->gameData->rate_level, data->gameData->rate_exp);
		break;
	}
	case GOLD:
	{
		sprintf(str, "* ���� Ƽ�� : ��� [ GOLD ]");
		sprintf(str2, "[ Level - %2d ]  [ Exp - %4d ]", data->gameData->rate_level, data->gameData->rate_exp);

		break;
	}
	case PLATINUM:
	{
		sprintf(str2, "* ���� Ƽ�� : �÷�Ƽ�� [ PLATINUM ]");
		sprintf(str2, "[ Level - %2d ]  [ Exp - %4d ]", data->gameData->rate_level, data->gameData->rate_exp);

		break;
	}
	case DIAMOND:
	{
		sprintf(str, "* ���� Ƽ�� : ���̾Ƹ�� [ DIAMOND ]");
		sprintf(str2, "[ Level - %2d ]  [ Exp - %4d ]", data->gameData->rate_level, data->gameData->rate_exp);

		break;
	}
	case MASTER:
	{
		sprintf(str, "* ���� Ƽ�� : ������ [ MASTER ]");
		sprintf(str2, "[ Level - %2d ]  [ Exp - %4d ]", data->gameData->rate_level, data->gameData->rate_exp);
		break;
	}
	case GRAND_MASTER:
	{
		sprintf(str, "* ���� Ƽ�� : �׷��� ������ [ GRAND MASTER ]");
		sprintf(str2, "[ Level - %2d ]  [ Exp - %4d ]", data->gameData->rate_level, data->gameData->rate_exp);
		break;
	}
	}
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, str, MIDDLE);

	setTextNode_addNodeToEnd(list, str2, MIDDLE);
	setTextNode_addNodeToEnd(list, "[ Y ] - ���ο� ����  [ N ] - ����ȭ��", MIDDLE);
	setTextNode_addNodeToEnd(list, "", MIDDLE);

	setBoxedNode_addBoxNode(list, STR_SIZE- 1);

	/* ��� */
	PSTR_NODE curr = list->nextNode;

	int count = 0;
	while (curr != NULL)
	{	
		setGoto_setCursor(start_i + count++, start_j);
		printf("%s", curr->str);

		curr = curr->nextNode;
	}

	/* ���� */
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

	/* �Ҵ� ���� */
	setTextNode_freeNodes(list);
	free(list);
	free(str);

	return ret;
}

// 3ȸ ������ �й�. true - ���� false - �й�
bool screenText_PlayScreen_EnterScreen_Lost(int max, int level, int start_i, int start_j)
{
	bool ret;
	
	PSTR_NODE list = getTextNode_allocInitHeader();

	int penalty = (level / 5 + 1) * 5;

	char* str = malloc(sizeof(char) * STR_SIZE);
	memset(str, 0, sizeof(char) * STR_SIZE);

	setTextNode_addNodeToEnd(list, "< WARNING >", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, " * �ùٸ� ������ �迭�� �ƴմϴ�.", MIDDLE);

	sprintf(str, "  [ ���� �˻�Ƚ�� : %d / 3 ]", max);
	setTextNode_addNodeToEnd(list, str, MIDDLE);
	memset(str, 0, sizeof(char) * STR_SIZE);

	setTextNode_addNodeToEnd(list, "* �ٽ� �õ� �Ͻðڽ��ϱ� ?", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "  [ Y ] - ��  [ N ] - �ƴϿ�  ", MIDDLE);

	sprintf(str, " (�ߵ� �����, - %2d Exp �г�Ƽ)", penalty);
	setTextNode_addNodeToEnd(list, str, MIDDLE);
	memset(str, 0, sizeof(char) * STR_SIZE);

	setBoxedNode_addBoxNode(list, STR_SIZE - 1);

	/* ��� */
	PSTR_NODE curr = list->nextNode;

	int count = 0;
	while (curr != NULL)
	{
		setGoto_setCursor(start_i + count++, start_j);
		printf("%s", curr->str);

		curr = curr->nextNode;
	}

	/* ���� */
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

	/* �Ҵ� ���� */
	setTextNode_freeNodes(list);
	free(list);
	free(str);

	return ret;
}

/* �й� ȭ�� */ //true - ����� false - �������� 
bool screenText_PlayScreen_EnterScreen_GameOver(int level, int start_i, int start_j)
{
	bool ret;

	PSTR_NODE list = getTextNode_allocInitHeader();

	int penalty = (level / 5 + 1) * 5;

	char* str = malloc(sizeof(char) * STR_SIZE);
	memset(str, 0, sizeof(char) * STR_SIZE);

	setTextNode_addNodeToEnd(list, "< G A M E _ O V E R >", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	sprintf(str, "* ���ӿ��� �����ϴ�. (-% 2d Exp)", penalty);
	setTextNode_addNodeToEnd(list, str, MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "* �ٽ� ���� �Ͻðڽ��ϱ� ?", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ Y ] - ��  [ N ] - �ƴϿ�", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);

	setBoxedNode_addBoxNode(list, STR_SIZE - 1);

	/* ��� */
	PSTR_NODE curr = list->nextNode;

	int count = 0;
	while (curr != NULL)
	{
		setGoto_setCursor(start_i + count++, start_j);
		printf("%s", curr->str);

		curr = curr->nextNode;
	}

	/* ���� */
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

	/* �Ҵ� ���� */
	setTextNode_freeNodes(list);
	free(list);
	free(str);

	return ret;
}

/* ������ - esc */ // ture - ���� ���� false ���
bool screenText_PlayScreen_EscapeScreen(int level, int start_i, int start_j)
{
	bool ret;

	PSTR_NODE list = getTextNode_allocInitHeader();

	int penalty = (level / 5 + 1) * 5;

	char* str = malloc(sizeof(char) * STR_SIZE);
	memset(str, 0, sizeof(char) * STR_SIZE);

	setTextNode_addNodeToEnd(list, "< EXIT >", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "* ���� ������ �����Ͻðڽ��ϱ� ?", MIDDLE);
	sprintf(str, "( �����, -%2d Exp �� �����˴ϴ�. )", penalty);
	setTextNode_addNodeToEnd(list, "", MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);
	setTextNode_addNodeToEnd(list, "[ Y ] - ��  [ N ] - �ƴϿ�", MIDDLE);
	setTextNode_addNodeToEnd(list, str, MIDDLE);
	setTextNode_addNodeToEnd(list, "", LEFT);

	setBoxedNode_addBoxNode(list, STR_SIZE - 1);

	/* ��� */
	PSTR_NODE curr = list->nextNode;

	int count = 0;
	while (curr != NULL)
	{
		setGoto_setCursor(start_i + count++, start_j);
		printf("%s", curr->str);

		curr = curr->nextNode;
	}

	/* ���� */
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

	/* �Ҵ� ���� */
	setTextNode_freeNodes(list);
	free(list);
	free(str);

	return ret;
}