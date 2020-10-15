//	printMatrix.c 파일은 매트릭스안에 특정 값을 출력하는 함수 파일.

#include <stdio.h>

#include "printMatrix.h"

#define LINE_SIZE 9
#define SECT_SIZE 3
#define SECT_START(sect) (sect * 3)
#define SECT_FIN(sect) ((sect * 3) + 3)

// 전체 매트릭스를 출력해주는 함수.
void printMatrix_printAll(int** matrix)
{
	for (int i = 0; i < LINE_SIZE; i++)
	{
		for (int j = 0; j < LINE_SIZE; j++)
		{
			printf(" %d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return;
}