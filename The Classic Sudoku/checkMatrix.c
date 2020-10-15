// checkMatrix.c 파일은 매트릭스가 규칙에 맞는 값을 가지고 있는지 검사하는 함수 파일.

#include <stdbool.h>

#include "checkMatrix.h"

#define LINE_SIZE 9
#define SECT_SIZE 3
#define CORRECT_NUM 45

#define SECT_START(sect) (sect * 3)
#define SECT_FIN(sect) ((sect * 3) + 3)

// matrix에서 행의 값이 모두 맞는지 검사해주는 함수.
bool checkMatrix_col(int** matrix, int row)
{
	int sum = 0;
	for (int i = 0; i < LINE_SIZE; i++)
	{
		sum += matrix[i][row];
	}

	if (sum == 45)
		return true;
	else
		return false;
}

// matrix에서 열의 값이 모두 맞는지 검사해주는 함수.
bool checkMatrix_row(int** matrix, int col)
{
	int sum = 0;
	for (int i = 0; i < LINE_SIZE; i++)
	{
		sum += matrix[col][i];
	}

	if (sum == 45)
		return true;
	else
		return false;
}

// matrix에서 섹터의 값이 모두 맞는지 검사해주는 함수.
bool checkMatrix_secter(int** matrix, int sect_i, int sect_j)
{
	int sum = 0;
	for (int i = SECT_START(sect_i); i < SECT_FIN(sect_i); i++)
	{
		for (int j = SECT_START(sect_j); j < SECT_FIN(sect_j); j++)
		{
			sum += matrix[i][j];
		}
	}

	if (sum == 45)
		return true;
	else
		return false;
}

// 생성된 매트릭스가 잘 생성된 배열인지 체크.
bool checkMatrix_all(int** matrix)
{
	for (int i = 0; i < LINE_SIZE; i++)
	{
		if (checkMatrix_col(matrix, i) && checkMatrix_row(matrix, i) == false)
			return false;
	}

	for (int i = 0; i < SECT_SIZE; i++)
	{
		for (int j = 0; j < SECT_SIZE; j++)
		{
			if (checkMatrix_secter(matrix, i, j) == false)
				return false;
		}
	}

	return true;
}