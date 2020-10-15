// getString.c ������ ������ ���ڿ��� �������ִ� �Լ�����.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getString.h"

// �Է¹��� str�� �����迭�� ���� �������ִ� �Լ�.
char* getString_mallocString(char* str)
{
	int size = strlen(str);

	char* retStr = malloc(sizeof(char) * size + 1);
	memset(retStr, 0, sizeof(char) * size + 1);
	for (int i = 0; i < size; i++)
	{
		retStr[i] = str[i];
	}

	return retStr;
}

