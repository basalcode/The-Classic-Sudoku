// printBuffer.c 파일은 buffer에 있는 내용을 출력해주는 함수.

#include <stdio.h>
#include <string.h>

#include "printBuffer.h"

#define NUM_MAX 9
#define SPACE_PER_NUM 4
#define MAT_I ((NUM_MAX * 2) + 1)
#define MAT_J (NUM_MAX * SPACE_PER_NUM + 1)

// 2차원 문자열 배열 버퍼를 출력.
void printBuffer_char2DBuffer(char** buffer, int height)
{
	for (int i = 0; i < height; i++)
	{
		printf("%s\n", buffer[i]);
	}

	return;
}

// 2차원 매트릭스 문자 배열 버퍼 출력
void printBuffer_char2DMatrixBuffer(char** buffer)
{
	for (int i = 0; i < MAT_I; i++)
	{
		printf("%s\n", buffer[i]);
	}

	return;
}