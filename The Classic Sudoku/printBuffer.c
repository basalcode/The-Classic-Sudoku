// printBuffer.c ������ buffer�� �ִ� ������ ������ִ� �Լ�.

#include <stdio.h>
#include <string.h>

#include "printBuffer.h"

#define NUM_MAX 9
#define SPACE_PER_NUM 4
#define MAT_I ((NUM_MAX * 2) + 1)
#define MAT_J (NUM_MAX * SPACE_PER_NUM + 1)

// 2���� ���ڿ� �迭 ���۸� ���.
void printBuffer_char2DBuffer(char** buffer, int height)
{
	for (int i = 0; i < height; i++)
	{
		printf("%s\n", buffer[i]);
	}

	return;
}

// 2���� ��Ʈ���� ���� �迭 ���� ���
void printBuffer_char2DMatrixBuffer(char** buffer)
{
	for (int i = 0; i < MAT_I; i++)
	{
		printf("%s\n", buffer[i]);
	}

	return;
}