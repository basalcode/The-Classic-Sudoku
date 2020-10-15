// getBoxedNode.c ������ Linked List�� �ڽ��� ����µ� �ʿ��� string�� �������ִ� �Լ�����.

#include <stdlib.h>
#include <string.h>

#include "getBoxedNode.h"

#include "setBoxedNode.h"

// length ũ���� Box ����� ������ִ� �Լ�.
char* getBoxedNode_TopLine(int length)
{
	int size = sizeof(char) * length + 2 + 1; // �� �� ���� + 1('\0')
	
	char* topStr = malloc(size);
	memset(topStr, 0, size);

	topStr[0] = 1;

	for (int i = 1; i < size - 2; i++) // '\0' �������� ����
	{
		topStr[i] = 6;
	}

	topStr[size - 2] = 2; // '\0' �� ��

	return topStr;
}

// length ũ���� Box ����� ������ִ� �Լ�.
char* getBoxedNode_BottomLine(int length)
{
	int size = sizeof(char) * length + 2 + 1; // �� �� ���� + 1('\0')

	char* botStr = malloc(size);
	memset(botStr, 0, size);

	botStr[0] = 3;

	for (int i = 1; i < size - 2; i++) // '\0' �������� ����
	{
		botStr[i] = 6;
	}

	botStr[size - 2] = 4; // '\0' �� ��

	return botStr;
}

// str�� �޾Ƽ� length�� ���� �迭�� 3���� ���Ĺ��(����, ���, ������ ����)�� ���� �������. 
char* getBoxedNode_MidLine(char* str, int length, ARRANGEMENT arrange)
{
	int size = sizeof(char) * length + 2 + 1; // �¿� �ڽ� ǥ�� + '\0' (+3)
	int strSize = strlen(str);
	int blankSize = length - strSize;

	char* midStr = malloc(size);
	memset(midStr, 0, size);

	midStr[0] = 5;

	int count = 0;
	for (int i = 1; i < size - 2; i++)
	{
		if (arrange == LEFT || arrange == ELSE)
		{
			if (i < strSize + 1)
			{
				midStr[i] = str[count++];
			}
			else
			{
				midStr[i] = ' ';
			}
		}
		else if (arrange == MIDDLE)
		{
			if (i < (blankSize / 2) + 1)
			{
				midStr[i] = ' ';
			}
			else if (i >= (blankSize / 2) + 1 && i < (blankSize / 2) + 1 + strSize)
			{
				midStr[i] = str[count++];
			}
			else
			{
				midStr[i] = ' ';
			}
		}
		else
		{
			if (i < blankSize + 1)
			{
				midStr[i] = ' ';
			}
			else
			{
				midStr[i] = str[count++];
			}
		}
	}

	midStr[size - 2] = 5;

	free(str); // ���� ���� ��Ʈ���� �Ҵ�����.

	return midStr;
}