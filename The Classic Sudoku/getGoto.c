// getGoto ������ Ŀ���� �̵��� ��ǥ�� ���� �������ִ� �Լ� ���� ����.

#include <stdlib.h>
#include <string.h>

#include "getGoto.h"

#include "setTextNode.h"

#define SCREEN_HEIGHT 24
#define SCREEN_WIDTH 77

#define MATRIX_SIZE 9
#define MATRIX_MAX 81

#define I 0
#define J 1

// ���ۿ� ����ִ� �̵� ��ǥ�� ���ؼ� �������ִ� �Լ�.
int** getGoto_cursorLocation(char** buffer, int choiseNum)
{
	int** locArr = malloc(sizeof(int) * choiseNum);
	for (int i = 0; i < choiseNum; i++)
	{
		locArr[i] = malloc(sizeof(int) * choiseNum);
		memset(locArr[i], 0, sizeof(int) * choiseNum);
	}

	int count = 0;
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		for (int j = 0; j < SCREEN_WIDTH; j++)
		{
			if (buffer[i][j] == '[')
			{
				if (buffer[i][j + 1] == ' ' && buffer[i][j + 2] == ']')
				{
					locArr[count][I] = i;
					locArr[count][J] = j + 1;
					count++;
				}
			}
		}
	}
	return locArr;
}

// Linked List�� ����ִ� ���뿡�� �̵���ǥ�� �����ؼ� �������ִ� �Լ�.
int** getGoto_cursorLocation_Node(PSTR_NODE list, int choiseNum, int start_i, int start_j)
{
	/* �������� ��ǥ �Ҵ� */
	int** locArr = malloc(sizeof(int) * choiseNum);
	for (int i = 0; i < choiseNum; i++)
	{
		locArr[i] = malloc(sizeof(int) * choiseNum);
		memset(locArr[i], 0, sizeof(int) * choiseNum);
	}

	/* Linked List ��ȸ�ϸ鼭 �����ϱ�*/
	PSTR_NODE curr = list->nextNode;
	
	int count = 0;
	int i_count = 0;
	while (curr != NULL)
	{
		for (int i = 0; i < curr->strLnegth; i++)
		{
			if (curr->str[i] == '[')
			{
				if (curr->str[i + 1] == ' ' && curr->str[i + 2] == ']')
				{
					locArr[count][I] = curr->nodeNumber + start_i + i_count;
					locArr[count][J] = i + start_j;
					count++;
				}
			}
		}
		i_count++;
		curr = curr->nextNode;
	}

	return locArr;
}

// PlayScreen ȭ�鿡�� �̵� ��ǥ�� ���ؼ� ���ۿ� ��� ���� ���ִ� �Լ�. 
int** getGoto_cursorLocation_playScreen()
{
	/* �������� ��ǥ �迭 �����Ҵ� */
	int** move = malloc(sizeof(int*) * MATRIX_MAX);
	for (int i = 0; i < MATRIX_MAX; i++)
	{
		move[i] = malloc(sizeof(int) * 2);
		memset(move[i], 0, sizeof(int) * 2);
	}

	/* ��Ʈ���� ���鼭 �ش� ��ǥ�� ������ */
	int moveIndex = 0;
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			move[moveIndex][I] = (i * 2) + 1 ;
			move[moveIndex][J] = (j * 4) + 2 ;
			moveIndex++;
		}
	}
	
	return move;
}