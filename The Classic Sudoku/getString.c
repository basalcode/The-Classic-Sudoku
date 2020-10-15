// getString.c 파일은 일차원 문자열을 리턴해주는 함수파일.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getString.h"

// 입력받은 str을 동적배열로 만들어서 리턴해주는 함수.
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

