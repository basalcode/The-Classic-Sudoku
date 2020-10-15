// setMatrix.c 파일은 매트릭스 내부에 특정 값을 입력하거나 수정하는 역할을 하는 함수 파일.

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

// answerMatrix를 만들어주는 함수.
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

			matrix[MAT_I][MAT_J] = 0; // 초기화.
		}
	}
}

// qestionMatrix를 난이도, 상수생성방식 등을 기준으로 생성함.
void setMatrix_setQuestionMatrix(int** answerMatrix, int** questionMatrix, PDATA data)
{
	int tier[7] = { 54, 46, 39, 33, 28, 24, 21 };

	int difficulty = MATRIX_MAX * tier[data->gameData->difficulty_tier] / 100;
	
	if (data->gameData->numberSetting_random_OnOff == true) // 랜덤으로 값을 매길때
	{
		int** arr = getMatrix_randomLocationType(difficulty);

		for (int i = 0; i < difficulty; i++)
		{
			questionMatrix[ARR_I][ARR_J] = answerMatrix[ARR_I][ARR_J];
		}
		return;
	}

	/* 랜덤이 아닐때 대칭일때 */
	int** arr = NULL;
	int symmetryType = data->gameData->numberSetting_symmetryType;
	
	if (data->gameData->numberSetting_symmetryType == RANDOM) // 랜덤이 선택되어있을때
	{
		symmetryType = randArr9_randomNumber(0) % 4; // 0 ~ 4 사이의 숫자가 들어가서 랜덤 픽해줌.
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
		printf("setMatrix_setQuestionMatrix 함수 애러 : 난이도에 잘못된 값이 들어가있습니다.\n");
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

// 할당받은 arr에 i (0 ~ max_i 미만 사이의 값), j (0 ~ max_j 미만 사이의 값) 을 할당해줌.
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

// matirx배열에 할당되있는 메모리 해제.
void setMatrix_freeMatrixArr(int** matrix)
{
	for (int i = 0; i < LINE_SIZE; i++)
	{
		free(matrix[i]);
	}
	free(matrix);

	return;
}

