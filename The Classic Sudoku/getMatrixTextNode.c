// getMatrixTextNode.c 파일은 숫자형인 매트릭스를 텍스트 노드로 바꿔주는 작업.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getMatrixTextNode.h"

#include "setMatrixTextNode.h"

#define LINE_SIZE 9
#define SECT_SIZE 3
#define NUMB_SPACE 4
#define BOARDER_SIZE 4

#define START_NUM 0
#define INDEX i / NUMB_SPACE

#define STRING_SIZE (sizeof(char) * (1 + (LINE_SIZE * NUMB_SPACE) + 1))

#define INT_TO_ASCII 48

// matrix용 node에 들어갈 문자열 배열 동적할당 및 초기화 함수.
char* getMatrixTextNode_allocInitArr()
{
	char* retStr = malloc(STRING_SIZE);
	memset(retStr, 0, STRING_SIZE);

	return retStr;
}

// matrix node 구조체의 동적할당 및 초기화 함수.
PMATRIX_NODE getMatrixTextNode_allocInitMatrixStruct()
{
	PMATRIX_NODE list = malloc(sizeof(MATRIX_NODE));
	memset(list, 0, sizeof(MATRIX_NODE));

	return list;
}

// matrix topNode 생성함수.
char* getMatrixTextNode_topNode(PDATA data)
{
	char* retStr = getMatrixTextNode_allocInitArr();
	TYPE_BOUNDARY lineType = data->gameData->designe_boundaryType;

	retStr[START_NUM] = 1;

	for (int i = START_NUM + 1; i < STRING_SIZE - 2;)
	{
		if (i % NUMB_SPACE == 0 && i % (NUMB_SPACE * SECT_SIZE) == 0) // 교차점
		{
			if (lineType == REMOVE_LINE)
			{
				retStr[i++] = 6;
			}
			else
			{
				retStr[i++] = 22;
			}
		}
		else // 교차점이 아닌 점
		{
			if (lineType == EVERY_LINE)
			{
				if (i % 4 == 0)
				{
					retStr[i++] = 22;
				}
				else
				{
					retStr[i++] = 6;
				}
			}
			else
			{
				retStr[i++] = 6;
			}
		}
	}
	retStr[STRING_SIZE - 2] = 2;

	return retStr;
}

// matrix middleNode 생성함수.
char* getMatrixTextNode_middleNode(BorL blankOrLine, PDATA data)
{
	char* retStr = getMatrixTextNode_allocInitArr();
	TYPE_BOUNDARY lineType = data->gameData->designe_boundaryType;

	if (blankOrLine == BLANK) // 섹터의 교점이 아닌 선
	{
		/* 시작 선 */
		if (lineType == EVERY_LINE)
		{
			retStr[START_NUM] = 25;
		}
		else
		{
			retStr[START_NUM] = 5;
		}
		for (int i = START_NUM + 1; i < STRING_SIZE - 2;)
		{
			if (i % NUMB_SPACE == 0 && i % (NUMB_SPACE * SECT_SIZE) == 0) // 섹터 구분선
			{
				if (lineType == EVERY_LINE)
				{
					retStr[i++] = 16;
				}
				else if (lineType == DOTED_LINE)
				{
					retStr[i++] = '|';
				}
				else if (lineType == REMOVE_LINE)
				{
					retStr[i++] = ' ';
				}
				else
				{
					retStr[i++] = 5;
				}
			}
			else // 섹터 구분선이 아닌 생략되는 구분선
			{
				if (lineType == EVERY_LINE)
				{
					if (i % 4 == 0)
					{
						retStr[i++] = 16;
					}
					else
					{
						retStr[i++] = 6;
					}
				}
				else
				{
					retStr[i++] = ' ';
				}
			}
		}

		/* 마무리 선 */
		if (lineType == EVERY_LINE)
		{
			retStr[STRING_SIZE - 2] = 23;
		}
		else
		{
			retStr[STRING_SIZE - 2] = 5;
		}
	}
	else // 섹터의 교점인 선
	{
		/* 시작 선 */
		if (lineType == REMOVE_LINE)
		{
			retStr[START_NUM] = 5;
		}
		else
		{
			retStr[START_NUM] = 25;
		}
		
		for (int i = START_NUM + 1; i < STRING_SIZE - 2;)
		{
			if (i % NUMB_SPACE == 0 && i % (NUMB_SPACE * SECT_SIZE) == 0) // 섹터 교차점의 교차점
			{
				if (lineType == DOTED_LINE)
				{
					retStr[i++] = '+';
				}
				else if (lineType == REMOVE_LINE)
				{
					retStr[i++] = ' ';
				}
				else
				{
					retStr[i++] = 16;
				}
			}
			else // 섹터 교차점의 교차점이 아닌 선
			{
				if (lineType == EVERY_LINE)
				{
					if (i % 4 == 0)
					{
						retStr[i++] = 16;
					}
					else
					{
						retStr[i++] = 6;
					}
				}
				else if (lineType == DOTED_LINE)
				{
					retStr[i++] = '-';
				}
				else if (lineType == REMOVE_LINE)
				{
					retStr[i++] = ' ';
				}
				else
				{
					retStr[i++] = 6;
				}
			}
		}

		/* 마무리 선 */
		if (lineType == REMOVE_LINE)
		{
			retStr[STRING_SIZE - 2] = 5;
		}
		else
		{
			retStr[STRING_SIZE - 2] = 23;
		}
	}

	return retStr;
}

// matrix bottomNode 생성함수.
char* getMatrixTextNode_bottomNode(PDATA data)
{
	char* retStr = getMatrixTextNode_allocInitArr();
	TYPE_BOUNDARY lineType = data->gameData->designe_boundaryType;

	retStr[START_NUM] = 3;

	for (int i = START_NUM + 1; i < STRING_SIZE - 2;)
	{
		if (i % NUMB_SPACE == 0 && i % (NUMB_SPACE * SECT_SIZE) == 0)
		{
			if (lineType == REMOVE_LINE)
			{
				retStr[i++] = 6;
			}
			else
			{
				retStr[i++] = 21;
			}
		}
		else
		{
			if (lineType == EVERY_LINE)
			{
				if (i % 4 == 0)
				{
					retStr[i++] = 21;
				}
				else
				{
					retStr[i++] = 6;
				}
			}
			else
			{
				retStr[i++] = 6;
			}
		}
	}
	retStr[STRING_SIZE - 2] = 4;

	return retStr;
}

// 받은 matrix 배열을 텍스트화 해줌.
char* getMatrixTextNode_arrToString(int* matrix, PDATA data)
{
	char* retStr = getMatrixTextNode_allocInitArr();
	TYPE_BOUNDARY lineType = data->gameData->designe_boundaryType;

	retStr[START_NUM] = 5;
	
	int count = 0;
	for (int i = START_NUM + 1; i < STRING_SIZE - 1;) // matrix 배열의 행을 루핑
	{
		if (i % NUMB_SPACE == 0)  // 선이있는 구간
		{

			if (i % (NUMB_SPACE * SECT_SIZE) == 0) // 섹터마다 선
			{
				if (lineType == DOTED_LINE) // 점선일때
				{
					if (i == STRING_SIZE - 2)
					{
						retStr[i++] = 5;
					}
					else
					{
						retStr[i++] = '|';
					}
				}
				else if (lineType == REMOVE_LINE && i != STRING_SIZE - 2)
				{
					retStr[i++] = ' ';

				}
				else // 옵션 없을때.
				{
					retStr[i++] = 5;
				}
			}
			else // 섹터가 아닌공간
			{
				if (lineType == EVERY_LINE) // 모든선 표시
				{
					retStr[i++] = 5;
				}
				else
				{
					retStr[i++] = ' ';
				}
			}
		}
		else // 숫자 혹은 공백 구간
		{
			if (i % 2 == 0) // 숫자구간
			{
				if (matrix[count] == 0) // 0 일때
				{
					retStr[i] = ' ';
					i++;
					count++;
				}
				else // 숫자 일때.
				{
					retStr[i++] = INT_TO_ASCII + matrix[count++];
				}
			}
			else // 공백구간
			{
				retStr[i++] = ' ';
			}
		}
	}
	return retStr;
}
