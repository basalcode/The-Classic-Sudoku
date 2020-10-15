// screenOperator_MainScreen.c ������ ����ȭ�� ���� �Լ�����.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

#include "screenOperator_MainScreen.h"
#include "screenOperator_Main_CheckRateScreen.h"
#include "screenOperator_Main_instructionScreen.h"
#include "screenOperator_Main_OptionScreen.h"
#include "screenOperator_Main_ReviewScreen.h"
#include "screenOperator_PlayScreen.h"

#include "buffer_screenText.h"
#include "printBuffer.h"
#include "getGoto.h"
#include "setGoto.h"
#include "setBuffer.h"

#include "getDataStructure.h"
#include "setDataStructure.h"

#include "screenText_MainScreen.h"
#include "ScreenText_MainScreen_Instruction.h"
#include "ScreenText_MainScreen_Option.h"
#include "ScreenText_MainScreen_CheckRate.h"
#include "ScreenText_MainScreen_Review.h"

#define SCREEN_HEIGHT 24
#define SCREEN_WIDTH 77

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
#define ESCAPE_KEY 27

#define I 0
#define J 1

// Ű���� �������� ��Ÿ���ִ� �Լ�. ���� ��ǥ ��ġ�� ������.
int screenOperator_driectionKeyboard(int** move, int moveMax, int keyBoard, int pos)
{
	switch (keyBoard)
	{
	case DIRECTION_KEY_UP:
	{
		MOVE_SET;
		printf(" ");
		MOVE_UP(moveMax);
		MOVE_SET;
		printf("V");
		break;
	}
	case DIRECTION_KEY_DOWN:
	{
		MOVE_SET;
		printf(" ");
		MOVE_DOWN(moveMax);
		MOVE_SET;
		printf("V");
		break;
	}
	case DIRECTION_KEY_LEFT:
	{
		MOVE_SET;
		printf(" ");
		MOVE_UP(moveMax);
		MOVE_SET;
		printf("V");
		break;
	}
	case DIRECTION_KEY_RIGHT:
	{
		MOVE_SET;
		printf(" ");
		MOVE_DOWN(moveMax);
		MOVE_SET;
		printf("V");
		break;
	}
	default:
	{
		break;
	}
	}

	return pos;
}

// Ű���� �������� ��Ÿ���ִ� �Լ�. ���� ��ǥ ��ġ�� ������.
int screenOperator_driectionKeyboard_notRemove(int** move, int moveMax, int keyBoard, int pos)
{

	switch (keyBoard)
	{
	case DIRECTION_KEY_UP:
	{
		MOVE_UP(moveMax);
		MOVE_SET;
		break;
	}
	case DIRECTION_KEY_DOWN:
	{
		MOVE_DOWN(moveMax);
		MOVE_SET;
		break;
	}
	case DIRECTION_KEY_LEFT:
	{
		MOVE_UP(moveMax);
		MOVE_SET;
		break;
	}
	case DIRECTION_KEY_RIGHT:
	{
		MOVE_DOWN(moveMax);
		MOVE_SET;
		break;
	}
	default:
	{
		break;
	}
	}

	return pos;
}

// ����ȭ�� ����.
void screenOperator_MainScreen(PDATA data)
{
	int max = 6;

	char** buffer = buffer_screenTextToBuffer(mainScreenText_setScreen);
	int** move = getGoto_cursorLocation(buffer, max);

	char keyBoard;
	int pos = 0;
BACK:
	system("mode con cols=80 lines=25");
	printBuffer_char2DBuffer(buffer, SCREEN_HEIGHT);
	
	MOVE_SET;
	printf("V");
	
	while (1)
	{
		keyBoard = _getch();
		if (DIRECTION_KEY_COMMON(keyBoard))
		{
			keyBoard = _getch();
			pos = screenOperator_driectionKeyboard(move, max, keyBoard, pos);
			
		}
		else if (keyBoard == ENTER_KEY)
		{
			switch (pos)
			{
			case 0: // 1. ���� �÷���
			{
				screenOperator_PlayScreen(data);
				goto BACK;
			}
			case 1: // 2. ���� ����
			{
				screenOperator_MainScreen_Instruction_Page1();
				goto BACK;
			}
			case 2: // 3. ���� �ɼ�
			{
				screenOperator_MainScreen_Option_Main(data);
				goto BACK;
			}
			case 3: // 4. ���� Ȯ��
			{
				screenOperator_MainScreen_CheckRate_Page1(data);
				goto BACK;
			}
			case 4: // 5. ���� ����.
			{
				screenOperator_MainScreen_Review_Page1();
				goto BACK;
			}
			case 5: // 6. ������
			{
				return;
			}
			}
		}
		else if (keyBoard == ESCAPE_KEY)
		{
			return;
		}
	}
	
	setBuffer_freeChar2DBuffer(buffer, SCREEN_HEIGHT);
	setGoto_freeCursorLocationArr(move, max);

	return;
}