// getGoto 파일은 커서의 이동할 좌표의 값을 저장해주는 함수 파일 모음.

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

// 버퍼에 들어있는 이동 좌표를 구해서 리턴해주는 함수.
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

// Linked List에 들어있는 내용에서 이동좌표를 추출해서 리턴해주는 함수.
int** getGoto_cursorLocation_Node(PSTR_NODE list, int choiseNum, int start_i, int start_j)
{
	/* 리턴해줄 좌표 할당 */
	int** locArr = malloc(sizeof(int) * choiseNum);
	for (int i = 0; i < choiseNum; i++)
	{
		locArr[i] = malloc(sizeof(int) * choiseNum);
		memset(locArr[i], 0, sizeof(int) * choiseNum);
	}

	/* Linked List 순회하면서 값구하기*/
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

// PlayScreen 화면에서 이동 좌표를 구해서 버퍼에 담아 리턴 해주는 함수. 
int** getGoto_cursorLocation_playScreen()
{
	/* 리턴해줄 좌표 배열 동적할당 */
	int** move = malloc(sizeof(int*) * MATRIX_MAX);
	for (int i = 0; i < MATRIX_MAX; i++)
	{
		move[i] = malloc(sizeof(int) * 2);
		memset(move[i], 0, sizeof(int) * 2);
	}

	/* 매트릭스 돌면서 해당 좌표를 구해줌 */
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