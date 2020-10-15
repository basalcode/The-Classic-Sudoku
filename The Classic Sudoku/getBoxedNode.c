// getBoxedNode.c 파일은 Linked List에 박스를 씌우는데 필요한 string을 생성해주는 함수파일.

#include <stdlib.h>
#include <string.h>

#include "getBoxedNode.h"

#include "setBoxedNode.h"

// length 크기의 Box 상단을 만들어주는 함수.
char* getBoxedNode_TopLine(int length)
{
	int size = sizeof(char) * length + 2 + 1; // 앞 뒤 꺽새 + 1('\0')
	
	char* topStr = malloc(size);
	memset(topStr, 0, size);

	topStr[0] = 1;

	for (int i = 1; i < size - 2; i++) // '\0' 전전까지 돌림
	{
		topStr[i] = 6;
	}

	topStr[size - 2] = 2; // '\0' 전 값

	return topStr;
}

// length 크기의 Box 상단을 만들어주는 함수.
char* getBoxedNode_BottomLine(int length)
{
	int size = sizeof(char) * length + 2 + 1; // 앞 뒤 꺽새 + 1('\0')

	char* botStr = malloc(size);
	memset(botStr, 0, size);

	botStr[0] = 3;

	for (int i = 1; i < size - 2; i++) // '\0' 전전까지 돌림
	{
		botStr[i] = 6;
	}

	botStr[size - 2] = 4; // '\0' 전 값

	return botStr;
}

// str을 받아서 length에 맞춘 배열을 3가지 정렬방식(왼쪽, 가운데, 오른쪽 정렬)에 맞춰 만들어줌. 
char* getBoxedNode_MidLine(char* str, int length, ARRANGEMENT arrange)
{
	int size = sizeof(char) * length + 2 + 1; // 좌우 박스 표시 + '\0' (+3)
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

	free(str); // 사용된 기존 스트링은 할당해제.

	return midStr;
}