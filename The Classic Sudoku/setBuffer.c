// setBuffer.c ������ buffer�� ���밪�� �����ϰų� �Ҵ��ϴ� �Լ� ����.

#include <stdlib.h>
#include <string.h>

#include "setBuffer.h"

#define NUM_MAX 9
#define SPACE_PER_NUM 4
#define MAT_I ((NUM_MAX * 2) + 1)
#define MAT_J (NUM_MAX * SPACE_PER_NUM + 1)

// 2���� ���ڿ� �迭���� �Ҵ� ����.
void setBuffer_freeChar2DBuffer(char** buffer, int height)
{
	for (int i = 0; i < height; i++)
	{
		free(buffer[i]);
	}
	free(buffer);

	return;
}

// 2���� ��Ʈ���� ���� �Ҵ� ����.
void setBuffer_freeChar2DMatrixBuffer(char** buffer)
{
	for (int i = 0; i < MAT_I; i++)
	{
		free(buffer[i]);
	}
	free(buffer);

	return;
}