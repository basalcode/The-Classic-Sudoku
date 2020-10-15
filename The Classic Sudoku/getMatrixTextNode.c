// getMatrixTextNode.c ������ �������� ��Ʈ������ �ؽ�Ʈ ���� �ٲ��ִ� �۾�.

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

// matrix�� node�� �� ���ڿ� �迭 �����Ҵ� �� �ʱ�ȭ �Լ�.
char* getMatrixTextNode_allocInitArr()
{
	char* retStr = malloc(STRING_SIZE);
	memset(retStr, 0, STRING_SIZE);

	return retStr;
}

// matrix node ����ü�� �����Ҵ� �� �ʱ�ȭ �Լ�.
PMATRIX_NODE getMatrixTextNode_allocInitMatrixStruct()
{
	PMATRIX_NODE list = malloc(sizeof(MATRIX_NODE));
	memset(list, 0, sizeof(MATRIX_NODE));

	return list;
}

// matrix topNode �����Լ�.
char* getMatrixTextNode_topNode(PDATA data)
{
	char* retStr = getMatrixTextNode_allocInitArr();
	TYPE_BOUNDARY lineType = data->gameData->designe_boundaryType;

	retStr[START_NUM] = 1;

	for (int i = START_NUM + 1; i < STRING_SIZE - 2;)
	{
		if (i % NUMB_SPACE == 0 && i % (NUMB_SPACE * SECT_SIZE) == 0) // ������
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
		else // �������� �ƴ� ��
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

// matrix middleNode �����Լ�.
char* getMatrixTextNode_middleNode(BorL blankOrLine, PDATA data)
{
	char* retStr = getMatrixTextNode_allocInitArr();
	TYPE_BOUNDARY lineType = data->gameData->designe_boundaryType;

	if (blankOrLine == BLANK) // ������ ������ �ƴ� ��
	{
		/* ���� �� */
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
			if (i % NUMB_SPACE == 0 && i % (NUMB_SPACE * SECT_SIZE) == 0) // ���� ���м�
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
			else // ���� ���м��� �ƴ� �����Ǵ� ���м�
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

		/* ������ �� */
		if (lineType == EVERY_LINE)
		{
			retStr[STRING_SIZE - 2] = 23;
		}
		else
		{
			retStr[STRING_SIZE - 2] = 5;
		}
	}
	else // ������ ������ ��
	{
		/* ���� �� */
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
			if (i % NUMB_SPACE == 0 && i % (NUMB_SPACE * SECT_SIZE) == 0) // ���� �������� ������
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
			else // ���� �������� �������� �ƴ� ��
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

		/* ������ �� */
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

// matrix bottomNode �����Լ�.
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

// ���� matrix �迭�� �ؽ�Ʈȭ ����.
char* getMatrixTextNode_arrToString(int* matrix, PDATA data)
{
	char* retStr = getMatrixTextNode_allocInitArr();
	TYPE_BOUNDARY lineType = data->gameData->designe_boundaryType;

	retStr[START_NUM] = 5;
	
	int count = 0;
	for (int i = START_NUM + 1; i < STRING_SIZE - 1;) // matrix �迭�� ���� ����
	{
		if (i % NUMB_SPACE == 0)  // �����ִ� ����
		{

			if (i % (NUMB_SPACE * SECT_SIZE) == 0) // ���͸��� ��
			{
				if (lineType == DOTED_LINE) // �����϶�
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
				else // �ɼ� ������.
				{
					retStr[i++] = 5;
				}
			}
			else // ���Ͱ� �ƴѰ���
			{
				if (lineType == EVERY_LINE) // ��缱 ǥ��
				{
					retStr[i++] = 5;
				}
				else
				{
					retStr[i++] = ' ';
				}
			}
		}
		else // ���� Ȥ�� ���� ����
		{
			if (i % 2 == 0) // ���ڱ���
			{
				if (matrix[count] == 0) // 0 �϶�
				{
					retStr[i] = ' ';
					i++;
					count++;
				}
				else // ���� �϶�.
				{
					retStr[i++] = INT_TO_ASCII + matrix[count++];
				}
			}
			else // ���鱸��
			{
				retStr[i++] = ' ';
			}
		}
	}
	return retStr;
}
