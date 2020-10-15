// goto_setCursor.c ������ goto �Լ����� ����.

#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#include "setGoto.h"

// Ŀ���� y, x ��ǥ�� �̵����ִ� �Լ�.
void setGoto_setCursor(int x, int y)
{
	COORD cursor = { y, x };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);

	return;
}

// cursorLocationArr�Լ��� �Ҵ� ���� ���ִ� �Լ�.
void setGoto_freeCursorLocationArr(int** move, int max)
{
	for (int i = 0; i < max; i++)
	{
		free(move[i]);
	}
	free(move);
}

