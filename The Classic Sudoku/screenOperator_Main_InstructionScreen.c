// screenOperator_Main_InstructionScreen.c 컨트롤

#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#include "screenOperator_Main_instructionScreen.h"

#include "buffer_screenText.h"
#include "setBuffer.h"
#include "printBuffer.h"
#include "screenOperator_MainScreen.h"
#include "ScreenText_MainScreen_Instruction.h"

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

// page 1
void screenOperator_MainScreen_Instruction_Page1()
{
	char** buffer = buffer_screenTextToBuffer(screenText_MainScreen_Instruction_Page1);
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
			screenOperator_MainScreen_Instruction_Page2();
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

// page 2
void screenOperator_MainScreen_Instruction_Page2()
{
	char** buffer = buffer_screenTextToBuffer(screenText_MainScreen_Instruction_Page2);
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
			screenOperator_MainScreen_Instruction_Page3();
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

// page 3
void screenOperator_MainScreen_Instruction_Page3()
{
	char** buffer = buffer_screenTextToBuffer(screenText_MainScreen_Instruction_Page3);
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