// randArr9.c ������ �迭�� �� ����, �����迭 ���� �������ִ� �Լ� ����.
// ��� ���Ҵ� 9���� ���Ҹ� ���� �迭�̸�, �������� -1���� �� ������ ���ܵ־���.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "randArr9.h"

#define ARR_SIZE 10 // 9���� ���� + -1 (null���� ����)
#define ARR_MAX 9 // �ݺ��� ����.
#define ARR_INIT -1 // -1�� �ʱ�ȭ.

// start���� ���� 0 Ȥ�� 1���� 9���� �������� ����.
int randArr9_randomNumber(START num)
{
	srand((unsigned)time(NULL));
	static int randomNumberCount = 0;
	randomNumberCount++;

	int retNumber = 0;
	
	for (int i = 0; i < randomNumberCount; i++)
	{
		retNumber = rand() % ARR_MAX + num;
	}

	if (randomNumberCount > 30)
		randomNumberCount = 0;

	return retNumber;
}

// start���� ���� 0 Ȥ�� 1 ���� 9���� ��ġ�� �ʴ� �������� �̷���� �迭�� ����.
int* randArr9_randomNumberArr(START num)
{
	int* randArr = malloc(sizeof(int) * ARR_SIZE);
	memset(randArr, ARR_INIT, sizeof(int) * ARR_SIZE);

	for (int i = 0; i < ARR_MAX; i++)
	{
	RERAND:
		randArr[i] = randArr9_randomNumber(num);
		for (int j = 0; j < i; j++)
		{
			if (randArr[j] == randArr[i])
			{
				goto RERAND;
			}
		}
	}

	return randArr;
}