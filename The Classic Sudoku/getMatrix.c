// getMatrix.c 파일은 matrix의 특정 값을 리턴해주는 함수 파일.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getMatrix.h"

#include "setMatrix.h"
#include "getArr9.h"
#include "setArr9.h"
#include "randArr9.h"

#include "printArr9.h"

#define INIT_MATRIX 0

#define LINE_SIZE 9
#define SECT_SIZE 3
#define SECT_START(sect) (sect * 3)
#define SECT_FIN(sect) ((sect * 3) + 3)
#define SECT_NUMBER(x) (x / 3)

#define ARR_SIZE 10

// matrix 2차원 배열을 동적할당, 초기화 해서 리턴해줌.
#include "printMatrix.h"
int** getMatrix_allocInitMatrixArr()
{
	int** matrix = malloc(sizeof(int*) * LINE_SIZE);
	for (int i = 0; i < LINE_SIZE; i++)
	{
		matrix[i] = malloc(sizeof(int) * LINE_SIZE);
		memset(matrix[i], INIT_MATRIX, sizeof(int) * LINE_SIZE);
	}

	return matrix;
}

// 매트릭스 배열을 복사해주는 함수.
int** getMatrix_copy2DMatrix(int** matrix)
{
	int** retMatrix = getMatrix_allocInitMatrixArr();

	for (int i = 0; i < LINE_SIZE; i++)
	{
		for (int j = 0; j < LINE_SIZE; j++)
		{
			retMatrix[i][j] = matrix[i][j]; // 그대로 복사.
		}
	}

	return retMatrix;
}

// matrix 해당 좌표의 세로줄에 있는 숫자들의 배열을 리턴해줌
int* getMatrix_getColNumber(int** matrix, int col, int row)
{
	int* retArr = getArr9_allocInitArr();
	
	int count = 0;
	for (int i = 0; i < LINE_SIZE; i++)
	{
		if (SECT_NUMBER(i) == SECT_NUMBER(col))
			continue;
		
		if (matrix[i][row] == 0)
			continue;

		retArr[count] = matrix[i][row];
		count++;
	}

	return retArr;
}

// matrix 해당 좌표의 가로줄에 있는 숫자들의 배열을 리턴해줌
int* getMatrix_getRowNumber(int** matrix, int col, int row)
{
	int* retArr = getArr9_allocInitArr();

	int count = 0;
	for (int i = 0; i < LINE_SIZE; i++)
	{
		if (SECT_NUMBER(i) == SECT_NUMBER(row))
			continue;

		if (matrix[col][i] == 0)
			continue;

		retArr[count] = matrix[col][i];
		count++;
	}

	return retArr;
}

// matrix 해당 좌표의 섹터에 있는 숫자들의 배열을 리턴해줌
int* getMatrix_getSectNumber(int** matrix, int col, int row)
{
	int* retArr = getArr9_allocInitArr();

	int sect_i = SECT_NUMBER(col);
	int sect_j = SECT_NUMBER(row);

	int count = 0;
	for (int i = SECT_START(sect_i); i < SECT_FIN(sect_i); i++)
	{
		for (int j = SECT_START(sect_j); j < SECT_FIN(sect_j); j++)
		{
			if (i == col && j == row)
				continue;
			if (matrix[i][j] == 0)
				continue;

			retArr[count] = matrix[i][j];
			count++;
		}
	}
	
	return retArr;
}

// matrix 현재 좌표의 가능성 배열을 뽑아줌.
int* getMatrix_getPossibleArr(int** matrix, int col, int row)
{
	int* arrCol = getMatrix_getColNumber(matrix, col, row);
	int* arrRow = getMatrix_getRowNumber(matrix, col, row);
	int* arrSect = getMatrix_getSectNumber(matrix, col, row);

	int* arrCombine = getArr9_combineArr(arrCol, arrRow);
	arrCombine = getArr9_combineArr(arrCombine, arrSect);

	int* retArr = getArr9_allocInitArr();

	for (int i = 0; i < LINE_SIZE; i++)
	{
		retArr[i] = i + 1;
	}

	setArr9_removeOverlapNumber(retArr, arrCombine);

	free(arrCol);
	free(arrRow);
	free(arrSect);
	free(arrCombine);

	return retArr;
}

#define LOC_MAX 2

// 생성해야할 난수좌표 배열만큼 동적 할당시켜주는 함수.
int** getMatrix_allocInitMatrixLocationArr(int difficulty)
{
	int** arr = malloc(sizeof(int*) * difficulty);
	for (int i = 0; i < difficulty; i++)
	{
		arr[i] = malloc(sizeof(int) * LOC_MAX);
		memset(arr[i], 0, sizeof(int) * LOC_MAX);
	}

	return arr;
}

#define I 0
#define J 1

#define RAND_I (randArr[I])
#define RAND_J (randArr[J])

#define LINE_MAX 8
#define MID_LINE 4
#define QUARTER 5
#define HALF 9

#define TEST printf("TEST\n")

// Type NULL : 무작위 좌표 리턴
int** getMatrix_randomLocationType(int difficulty)
{
	int** arr = getMatrix_allocInitMatrixLocationArr(difficulty);
	int* randArr = malloc(sizeof(int) * LOC_MAX); // 좌표 (i, j)
	memset(randArr, 0, sizeof(int) * LOC_MAX);
	
	for (int i = 0; i < difficulty ; i++)
	{
	RERAND:
		
		RAND_I = randArr9_randomNumber(0) % HALF;
		RAND_J = randArr9_randomNumber(0) % HALF;

		for (int j = 0; j < i; j++)
		{
			if (arr[j][I] == RAND_I && arr[j][J] == RAND_J)
			{
				goto RERAND;
			}
		}
		// 무작위로 입력
		arr[i][I] = RAND_I;
		arr[i][J] = RAND_J;
	}

	return arr;
}

// Type A : 완전대칭형 좌표 리턴
int** getMatrix_symmetryTypeA(int difficulty)
{
	int** arr = getMatrix_allocInitMatrixLocationArr(difficulty);
	int* randArr = malloc(sizeof(int) * LOC_MAX);
	memset(randArr, 0, sizeof(int) * LOC_MAX);

	int count = 0;
	for (int i = 0; i < difficulty / 4; i++)
	{
	RERAND1:
		setMatrix_setRandomMatrixLocation(randArr, QUARTER, QUARTER);

		for (int j = 0; j < count; j++)
		{
			if (arr[j][I] == RAND_I && arr[j][J] == RAND_J)
			{
				goto RERAND1;
			}
		}

		// 1 사분면
		arr[count][I] = RAND_I;
		arr[count][J] = RAND_J;
		count++;

		// 2 사분면
		arr[count][I] = RAND_I;
		arr[count][J] = LINE_MAX - RAND_J;
		count++;

		// 3 사분면
		arr[count][I] = LINE_MAX - RAND_I;
		arr[count][J] = LINE_MAX - RAND_J;
		count++;

		// 4 사분면
		arr[count][I] = LINE_MAX - RAND_I;
		arr[count][J] = RAND_J;
		count++;
	}

	for (int i = 0; i < (difficulty % 4) / 2; i++)
	{
	RERAND2:
		setMatrix_setRandomMatrixLocation(randArr, HALF, QUARTER);

		if (RAND_I != 4 && RAND_J != 4) // 아무것도 중간선에 안걸렸을 경우 재할당.
		{
			goto RERAND2;
		}

		for (int j = 0; j < count; j++)
		{
			if (arr[j][I] == RAND_I && arr[j][J] == RAND_J)
			{
				goto RERAND2;
			}
		}
		
		// 평행축에 좌표가 할당되었을 경우.
		if (RAND_I == 4)
		{
			arr[count][I] = RAND_I;
			arr[count][J] = RAND_J;
			count++;

			arr[count][I] = RAND_I;
			arr[count][J] = LINE_MAX - RAND_J;
			count++;
		}
		else if (RAND_J == 4)// 수직축에 좌표가 할당되었을 경우.
		{
			arr[count][I] = RAND_I;
			arr[count][J] = RAND_J;
			count++;

			arr[count][I] = LINE_MAX - RAND_I;
			arr[count][J] = RAND_J;
			count++;
		}
	}

	for (int i = 0; i < difficulty % 2; i++)
	{
		// 나머지 홀수는 정중앙
		arr[count][I] = MID_LINE;
		arr[count][J] = MID_LINE;
	}

	free(randArr);

	return arr;
}

// Type B : 풍차형 대칭 좌표 리턴
int** getMatrix_symmetryTypeB(int difficulty)
{
	int** arr = getMatrix_allocInitMatrixLocationArr(difficulty);
	int* randArr = malloc(sizeof(int) * LOC_MAX);
	memset(randArr, 0, sizeof(int) * LOC_MAX);

	int count = 0;
	for (int i = 0; i < difficulty / 4; i++)
	{
	RERAND1:
		setMatrix_setRandomMatrixLocation(randArr, QUARTER, QUARTER);
	
		for (int j = 0; j < count; j++)
		{
			if (arr[j][I] == RAND_I && arr[j][J] == RAND_J)
			{
				goto RERAND1;
			}
		}
		
		// 1 사분면
		arr[count][I] = RAND_I;
		arr[count][J] = RAND_J;
		count++;

		// 2 사분면
		arr[count][I] = RAND_J;
		arr[count][J] = LINE_MAX - RAND_I;
		count++;

		// 3 사분면
		arr[count][I] = LINE_MAX - RAND_I;
		arr[count][J] = LINE_MAX - RAND_J;
		count++;

		// 4 사분면
		arr[count][I] = LINE_MAX - RAND_J;
		arr[count][J] = RAND_I;
		count++;
	}

	for (int i = 0; i < (difficulty % 4) / 2; i++)
	{
	RERAND2:
		setMatrix_setRandomMatrixLocation(randArr, HALF, QUARTER);

		if (RAND_I != 4 && RAND_J != 4) // 아무것도 중간선에 안걸렸을 경우 재할당.
		{
			goto RERAND2;
		}

		for (int j = 0; j < count; j++)
		{
			if (arr[j][I] == RAND_I && arr[j][J] == RAND_J)
			{
				goto RERAND2;
			}
		}

		// 평행축에 좌표가 할당되었을 경우.
		if (RAND_I == 4)
		{
			arr[count][I] = RAND_I;
			arr[count][J] = RAND_J;
			count++;

			arr[count][I] = RAND_I;
			arr[count][J] = LINE_MAX - RAND_J;
			count++;
		}
		else if (RAND_J == 4)// 수직축에 좌표가 할당되었을 경우.
		{
			arr[count][I] = RAND_I;
			arr[count][J] = RAND_J;
			count++;

			arr[count][I] = LINE_MAX - RAND_I;
			arr[count][J] = RAND_J;
			count++;
		}
	}

	for (int i = 0; i < difficulty % 2; i++)
	{
		// 나머지 홀수는 정중앙
		arr[count][I] = MID_LINE;
		arr[count][J] = MID_LINE;
	}

	free(randArr);

	return arr;
}

// Type C : 나비 대칭형 좌표 리턴
int** getMatrix_symmetryTypeC(int difficulty)
{
	int** arr = getMatrix_allocInitMatrixLocationArr(difficulty);
	int* randArr = malloc(sizeof(int) * LOC_MAX);
	memset(randArr, 0, sizeof(int) * LOC_MAX);

	int count = 0;
	for (int i = 0; i < difficulty / 2; i++)
	{
	RERAND:
		setMatrix_setRandomMatrixLocation(randArr, HALF, QUARTER);

		for (int j = 0; j < count; j++)
		{
			if (arr[j][I] == RAND_I && arr[j][J] == RAND_J)
			{
				goto RERAND;
			}
		}

		// 중간 라인에 걸렸을 경우.
		if (RAND_J == MID_LINE)
		{
			// 우선 할당.
			arr[count][I] = RAND_I;
			arr[count][J] = RAND_J;
			count++;
			
			// 다음 좌표
		RE_I:
			RAND_I = randArr9_randomNumber(0) % 9;

			if (RAND_I == MID_LINE) 
				goto RE_I;

			for (int j = 0; j < count; j++)
			{
				if (arr[j][I] == RAND_I && arr[j][J] == MID_LINE) // 좌표 둘다 겹칠때.
					goto RE_I;
			}
			// 다음 좌표 할당.
			arr[count][I] = RAND_I;
			arr[count][J] = RAND_J;
			count++;

			continue;
		}

		// 1 이분면
		arr[count][I] = RAND_I;
		arr[count][J] = RAND_J;
		count++;

		// 2 이분면
		arr[count][I] = RAND_I;
		arr[count][J] = LINE_MAX - RAND_J;
		count++;
	}

	for (int i = 0; i < difficulty % 2; i++)
	{
		// 나머지 홀수는 정중앙
		arr[count][I] = MID_LINE;
		arr[count][J] = MID_LINE;
	}

	free(randArr);

	return arr;
}

// Type D : 모래시계 대칭형 좌표 리턴
int** getMatrix_symmetryTypeD(int difficulty)
{
	int** arr = getMatrix_allocInitMatrixLocationArr(difficulty);
	int* randArr = malloc(sizeof(int) * LOC_MAX);
	memset(randArr, 0, sizeof(int) * LOC_MAX);

	int count = 0;
	for (int i = 0; i < difficulty / 2; i++)
	{
	RERAND:
		setMatrix_setRandomMatrixLocation(randArr, QUARTER, HALF);

		for (int j = 0; j < count; j++)
		{
			if (arr[j][I] == RAND_I && arr[j][J] == RAND_J)
			{
				goto RERAND;
			}
		}

		// 중간 라인에 걸렸을 경우.
		if (RAND_I == MID_LINE)
		{
			// 우선 할당.
			arr[count][I] = RAND_I;
			arr[count][J] = RAND_J;
			count++;

			// 다음 좌표
		RE_I:
			RAND_J = randArr9_randomNumber(0) % 9;

			if (RAND_J == MID_LINE)
				goto RE_I;

			for (int j = 0; j < count; j++)
			{
				if (arr[j][I] == MID_LINE && arr[j][J] == RAND_J) // 좌표 둘다 겹칠때.
					goto RE_I;
			}
			// 다음 좌표 할당.
			arr[count][I] = RAND_I;
			arr[count][J] = RAND_J;
			count++;

			continue;
		}


		// 1 이분면
		arr[count][I] = RAND_I;
		arr[count][J] = RAND_J;
		count++;

		// 2 이분면
		arr[count][I] = LINE_MAX - RAND_I;
		arr[count][J] = RAND_J;
		count++;
	}

	for (int i = 0; i < difficulty % 2; i++)
	{
		// 나머지 홀수는 정중앙
		arr[count][I] = MID_LINE;
		arr[count][J] = MID_LINE;
	}

	free(randArr);

	return arr;
}