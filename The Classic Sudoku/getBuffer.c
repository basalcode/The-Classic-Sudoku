// getBuffer.c 파일은 완성된 버퍼를 리턴하는 함수 파일.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getBuffer.h"

#include "setTextNode.h"
#include "getTextNode.h"

#include "setBoxedNode.h"

#define NUM_MAX 9
#define SPACE_PER_NUM 4
#define MAT_I ((NUM_MAX * 2) + 1)
#define MAT_J (NUM_MAX * SPACE_PER_NUM + 1)

// Linked List의 node에 저장되어있던 2차원 문자열 배열을 버퍼에 저장해줌.
char** getBuffer_textNode(PSTR_NODE list, int height, int width)
{
	char** buffer = malloc(sizeof(char*) * height);
	for (int i = 0; i < height; i++)
	{
		buffer[i] = malloc(sizeof(char) * width + 1); // '\0'
		memset(buffer[i], 0, sizeof(char) * width + 1);
	}

	PSTR_NODE curr = list->nextNode;
	int count = 0;
	while (curr != NULL)
	{
		strcpy(buffer[count], curr->str);
		count++;
		curr = curr->nextNode;
	}

	return buffer;
}

// Linked List를 boxWidthSize 가로 크기의 박스를 만들어서 버퍼에 저장해주는 함수.
char** getBuffer_completedTextNode(PSTR_NODE list, int boxWidthSize)
{
	char** buffer;

	setBoxedNode_addBoxNode(list, boxWidthSize);

	int height = getTextNode_getNodeMax(list);;
	int width = getTextNode_getStringLengthMax(list);;

	buffer = getBuffer_textNode(list, height, width);

	return buffer;
}

// matrix Linked List를 버퍼에 저장.
char** getBuffer_matrixTextNode(PMATRIX_NODE list)
{
	char** buffer = malloc(sizeof(char*) * (MAT_I));
	
	for (int i = 0; i < MAT_I; i++)
	{
		buffer[i] = malloc(sizeof(char) * (MAT_J)+1);
		memset(buffer[i], 0, sizeof(char) * (MAT_J)+1);
	}

	PMATRIX_NODE curr = list->nextNode;
	int count = 0;
	while (curr != NULL)
	{
		strcpy(buffer[count], curr->str);
		count++;
		curr = curr->nextNode;
	}

	return buffer;
}