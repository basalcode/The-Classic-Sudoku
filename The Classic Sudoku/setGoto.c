// goto_setCursor.c 파일은 goto 함수전용 파일.

#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#include "setGoto.h"

// 커서를 y, x 좌표로 이동해주는 함수.
void setGoto_setCursor(int x, int y)
{
	COORD cursor = { y, x };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);

	return;
}

// cursorLocationArr함수를 할당 해제 해주는 함수.
void setGoto_freeCursorLocationArr(int** move, int max)
{
	for (int i = 0; i < max; i++)
	{
		free(move[i]);
	}
	free(move);
}

