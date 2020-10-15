// screenOperator_Main_CheckRateScreen.c 컨트롤

#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#include "screenOperator_Main_CheckRateScreen.h"

#include "buffer_screenText.h"
#include "setBuffer.h"
#include "printBuffer.h"
#include "screenOperator_MainScreen.h"
#include "ScreenText_MainScreen_CheckRate.h"

#include "getGoto.h"
#include "setGoto.h"

#define SCREEN_HEIGHT 24
#define SCREEN_WIDTH 77

#define DIRECTION_KEY_COMMON(key) (key == 0 || key == 0xE0 || key == -32)

#define ENTER_KEY 13
#define ESCAPE_KEY 27

#define MOVE_SET (setGoto_setCursor(move[pos][I], move[pos][J]))
#define I 0
#define J 1


void screenOperator_MainScreen_CheckRate_Page1(PDATA data)
{
	char** buffer = buffer_screenTextToBuffer_rate(screenText_MainScreen_CheckRate_Page1, data);
	char keyBoard;

BACK:
	system("cls");
	printBuffer_char2DBuffer(buffer, SCREEN_HEIGHT);
	int pos = 0;

	// 키 조작
	while (1)
	{
		keyBoard = _getch();
		if (keyBoard == ENTER_KEY)
		{
			screenOperator_MainScreen_CheckRate_Page2(data);
			goto BACK;
		}
		else if (keyBoard == ESCAPE_KEY)
		{
			return;
		}
	}

	setBuffer_freeChar2DBuffer(buffer, SCREEN_HEIGHT);

	return;
}

void screenOperator_MainScreen_CheckRate_Page2(PDATA data)
{
	char** buffer = buffer_screenTextToBuffer_rate(screenText_MainScreen_CheckRate_Page2, data);
	char keyBoard;

BACK:
	system("cls");
	printBuffer_char2DBuffer(buffer, SCREEN_HEIGHT);
	int pos = 0;

	// 키 조작
	while (1)
	{
		keyBoard = _getch();
		if (keyBoard == ENTER_KEY)
		{
			screenOperator_MainScreen_CheckRate_Page3(data);
			goto BACK;
		}
		else if (keyBoard == ESCAPE_KEY)
		{
			return;
		}
	}

	setBuffer_freeChar2DBuffer(buffer, SCREEN_HEIGHT);

	return;
}

void screenOperator_MainScreen_CheckRate_Page3(PDATA data)
{
	char** buffer = buffer_screenTextToBuffer_rate(screenText_MainScreen_CheckRate_Page3, data);
	char keyBoard;

	system("cls");
	printBuffer_char2DBuffer(buffer, SCREEN_HEIGHT);
	int pos = 0;

	// 키 조작
	while (1)
	{
		keyBoard = _getch();
		if (keyBoard == ESCAPE_KEY)
		{
			return;
		}
	}

	setBuffer_freeChar2DBuffer(buffer, SCREEN_HEIGHT);

	return;
}