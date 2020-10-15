// buffer_screenText.c ������ ���� ��ũ���� ������� ��� ���۸� �������ִ� �Լ�����.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buffer_screenText.h"

#include "screenText_MainScreen.h"
#include "getMatrixTextNode.h"
#include "getTextNode.h"
#include "setTextNode.h"
#include "getBuffer.h"
#include "setBuffer.h"
#include "setDataStructure.h"
#include "getMatrix.h"
#include "setMatrix.h"

#include "ScreenText_MainScreen_Instruction.h"
#include "ScreenText_MainScreen_Option.h"
#include "ScreenText_MainScreen_CheckRate.h"
#include "ScreenText_MainScreen_Review.h"
#include "screenText_PlayScreen.h"

#define SCREEN_WIDTH 77

#define MATRIX_HEIGHT 19
#define MATRIX_WIDTH 37

#define STATE_HIGHT 8
#define CONTROL_WIDTH 20

#define PLAY_SCREEN_HEIGHT 27
#define PLAY_SCREEN_WIDTH 60

#define STATE_SCREEN_HEIGHT 5

#include "printMatrixTextNode.h"
#include "printTextNode.h"
#include "printBuffer.h"

// �Լ��� �Ű������� �޾Ƽ� ���۷� �������ִ� �Լ�.
char** buffer_screenTextToBuffer(void (*fp)(PSTR_NODE))
{
	PSTR_NODE list = getTextNode_allocInitHeader();
	fp(list);

	char** buffer = getBuffer_completedTextNode(list, SCREEN_WIDTH);

	setTextNode_freeNodes(list);
	free(list);

	return buffer;
}

// �Լ��� �Ű������� �޾Ƽ� ���۷� �������ִ� �Լ�. 4. ����Ȯ�� ����.
#include <Windows.h>
char** buffer_screenTextToBuffer_rate(void(*fp)(PSTR_NODE, PDATA), PDATA data)
{
	PSTR_NODE list = getTextNode_allocInitHeader();
	fp(list, data);

	char** buffer = getBuffer_completedTextNode(list, SCREEN_WIDTH);

	setTextNode_freeNodes(list);
	free(list);

	return buffer;
}

// playScreen ��ü�� ���ۿ� ����ִ� �Լ�.
char** buffer_screenTextToBuffer_PlayScreen(int** answerMatrix, int** questionMatrix, PDATA data)
{
	/* buffer �Ҵ� */
	char** buffer = malloc(sizeof(char*) * PLAY_SCREEN_HEIGHT);
	for (int i = 0; i < PLAY_SCREEN_HEIGHT; i++)
	{
		buffer[i] = malloc(sizeof(char) * PLAY_SCREEN_WIDTH + 1); // ���� 2ĭ ����  + '\0'
		memset(buffer[i], 0, sizeof(char) * PLAY_SCREEN_WIDTH + 1);
	}

	/* Linked List �Ҵ� 1 */
	PMATRIX_NODE matrixNode = getMatrixTextNode_allocInitMatrixStruct();
	PSTR_NODE strNode = getTextNode_allocInitHeader();

	screenText_PlayScreen_Matrix(answerMatrix, questionMatrix, matrixNode, data);
	screenText_PlayScreen_ControlScreen(strNode);

	char** matrixBuffer = getBuffer_matrixTextNode(matrixNode);
	char** strBuffer = getBuffer_completedTextNode(strNode, CONTROL_WIDTH);

	for (int i = 0; i < MATRIX_HEIGHT; i++)
	{
		strcpy(buffer[i], matrixBuffer[i]);
		strcat(buffer[i], " ");
		strcat(buffer[i], strBuffer[i]);
	}

	/* �Ҵ� ����*/
	setMatrixTextNode_freeNodes(matrixNode);
	setTextNode_freeNodes(strNode);
	free(matrixNode);
	free(strNode);
	setBuffer_freeChar2DMatrixBuffer(matrixBuffer);
	setBuffer_freeChar2DBuffer(strBuffer, MATRIX_HEIGHT);

	/* Linked List �Ҵ� 2 */
	PSTR_NODE strNode1 = getTextNode_allocInitHeader();
	PSTR_NODE strNode2 = getTextNode_allocInitHeader();

	screenText_PlayScreen_StateScreen(strNode1, data);
	screenText_PlayScreen_HintsScreen(strNode2, data);

	char** strBuffer1 = getBuffer_completedTextNode(strNode1, MATRIX_WIDTH - 2);
	char** strBuffer2 = getBuffer_completedTextNode(strNode2, CONTROL_WIDTH);

	for (int i = MATRIX_HEIGHT; i < PLAY_SCREEN_HEIGHT; i++)
	{
		strcpy(buffer[i], strBuffer1[i - MATRIX_HEIGHT]);
		strcat(buffer[i], " ");
		strcat(buffer[i], strBuffer2[i - MATRIX_HEIGHT]);
	}

	/* �Ҵ� ����*/
	setTextNode_freeNodes(strNode1);
	setTextNode_freeNodes(strNode2);
	free(strNode1);
	free(strNode2);
	setBuffer_freeChar2DBuffer(strBuffer1, STATE_HIGHT);
	setBuffer_freeChar2DBuffer(strBuffer2, STATE_HIGHT);

	return buffer;
}