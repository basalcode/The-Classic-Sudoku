// setBuffer.c 파일은 buffer의 내용값을 변경하거나 할당하는 함수 파일.

#include <stdlib.h>
#include <string.h>

#include "setBuffer.h"

#define NUM_MAX 9
#define SPACE_PER_NUM 4
#define MAT_I ((NUM_MAX * 2) + 1)
#define MAT_J (NUM_MAX * SPACE_PER_NUM + 1)

// 2차원 문자열 배열버퍼 할당 해제.
void setBuffer_freeChar2DBuffer(char** buffer, int height)
{
	for (int i = 0; i < height; i++)
	{
		free(buffer[i]);
	}
	free(buffer);

	return;
}

// 2차원 매트릭스 버퍼 할당 해제.
void setBuffer_freeChar2DMatrixBuffer(char** buffer)
{
	for (int i = 0; i < MAT_I; i++)
	{
		free(buffer[i]);
	}
	free(buffer);

	return;
}