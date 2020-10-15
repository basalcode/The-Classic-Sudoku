// setMatrix.c ������ ��Ʈ���� ���ο� Ư�� ���� �Է��ϰų� �����ϴ� ������ �ϴ� �Լ� ����.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>

#include "setMatrix.h"

#include "getMatrix.h"
#include "randArr9.h"
#include "getArr9.h"
#include "setArr9.h"
#include "setDataStructure.h"

#define LINE_SIZE 9
#define SECT_SIZE 3
#define SECT_START(sect) (sect * 3)
#define SECT_FIN(sect) ((sect * 3) + 3)

#define SECT_I (sectLoc / 3)
#define SECT_J (sectLoc % 3)

#define MAT_I ((SECT_START(SECT_I)) + (matrixLoc / 3))
#define MAT_J ((SECT_START(SECT_J)) + (matrixLoc % 3))

#define MATRIX_MAX 81

#define ARR_I arr[i][0]
#define ARR_J arr[i][1]

#define TEST printf("TEST\n")

// answerMatrix�� ������ִ� �Լ�.
bool setMatrix_setAnswerMatrix(int** matrix, int sectLoc, int matrixLoc)
{
	int* possibleArr = getMatrix_getPossibleArr(matrix, MAT_I, MAT_J);
	while(1)
	{
		int arrSize = getArr9_getArrSize(possibleArr);
		if (arrSize == 0)
		{
			free(possibleArr);
			return false;
		}
		int randIndex = (randArr9_randomNumber(NUM_0to8) % arrSize);

		matrix[MAT_I][MAT_J] = possibleArr[randIndex];
		possibleArr[randIndex] = -1;
		setArr9_setArrangedArr(possibleArr);

		matrixLoc++;
		if (matrixLoc == 9)
		{
			sectLoc++;
			if (sectLoc == 9)
			{
				free(possibleArr);
				return true;
			}
			matrixLoc = 0;
		}

		if (setMatrix_setAnswerMatrix(matrix, sectLoc, matrixLoc))
		{
			free(possibleArr);
			return true;
		}
		else
		{
			if (matrixLoc == 0)
			{
				sectLoc--;
				matrixLoc = 8;
			}
			else
			{
				matrixLoc--;
			}

			matrix[MAT_I][MAT_J] = 0; // �ʱ�ȭ.
		}
	}
}

// qestionMatrix�� ���̵�, ���������� ���� �������� ������.
void setMatrix_setQuestionMatrix(int** answerMatrix, int** questionMatrix, PDATA data)
{
	int tier[7] = { 54, 46, 39, 33, 28, 24, 21 };

	int difficulty = MATRIX_MAX * tier[data->gameData->difficulty_tier] / 100;
	
	if (data->gameData->numberSetting_random_OnOff == true) // �������� ���� �ű涧
	{
		int** arr = getMatrix_randomLocationType(difficulty);

		for (int i = 0; i < difficulty; i++)
		{
			questionMatrix[ARR_I][ARR_J] = answerMatrix[ARR_I][ARR_J];
		}
		return;
	}

	/* ������ �ƴҶ� ��Ī�϶� */
	int** arr = NULL;
	int symmetryType = data->gameData->numberSetting_symmetryType;
	
	if (data->gameData->numberSetting_symmetryType == RANDOM) // ������ ���õǾ�������
	{
		symmetryType = randArr9_randomNumber(0) % 4; // 0 ~ 4 ������ ���ڰ� ���� ���� ������.
	}

	switch (symmetryType)
	{
	case COMPLETE:
	{
		arr = getMatrix_symmetryTypeA(difficulty);
		break;
	}
	case WINDMILL:
	{
		arr = getMatrix_symmetryTypeB(difficulty);
		break;
	}
	case LEFT_RIGHT:
	{
		arr = getMatrix_symmetryTypeC(difficulty);
		break;
	}
	case UP_DOWN:
	{
		arr = getMatrix_symmetryTypeD(difficulty);
		break;
	}
	default:
	{
		printf("setMatrix_setQuestionMatrix �Լ� �ַ� : ���̵��� �߸��� ���� ���ֽ��ϴ�.\n");
		break;
	}
	}
	
	for (int i = 0; i < difficulty; i++)
	{
		questionMatrix[ARR_I][ARR_J] = answerMatrix[ARR_I][ARR_J];
	}

	return;
}

#define RAND_I 0
#define RAND_J 1

// �Ҵ���� arr�� i (0 ~ max_i �̸� ������ ��), j (0 ~ max_j �̸� ������ ��) �� �Ҵ�����.
void setMatrix_setRandomMatrixLocation(int* arr, int max_i, int max_j)
{
RERAND:
	arr[RAND_I] = randArr9_randomNumber(0) % max_i;
	arr[RAND_J] = randArr9_randomNumber(0) % max_j;

	if (arr[RAND_I] == 4 && arr[RAND_J] == 4)
	{
		goto RERAND;
	}

	return;
}

// matirx�迭�� �Ҵ���ִ� �޸� ����.
void setMatrix_freeMatrixArr(int** matrix)
{
	for (int i = 0; i < LINE_SIZE; i++)
	{
		free(matrix[i]);
	}
	free(matrix);

	return;
}

