// checkMatrix.c ������ ��Ʈ������ ��Ģ�� �´� ���� ������ �ִ��� �˻��ϴ� �Լ� ����.

#include <stdbool.h>

#include "checkMatrix.h"

#define LINE_SIZE 9
#define SECT_SIZE 3
#define CORRECT_NUM 45

#define SECT_START(sect) (sect * 3)
#define SECT_FIN(sect) ((sect * 3) + 3)

// matrix���� ���� ���� ��� �´��� �˻����ִ� �Լ�.
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

// matrix���� ���� ���� ��� �´��� �˻����ִ� �Լ�.
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

// matrix���� ������ ���� ��� �´��� �˻����ִ� �Լ�.
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

// ������ ��Ʈ������ �� ������ �迭���� üũ.
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