// randArr9.c 파일은 배열에 들어갈 난수, 난수배열 등을 생성해주는 함수 파일.
// 모든 원소는 9개의 원소를 가진 배열이며, 마지막에 -1값이 들어갈 공간을 남겨둬야함.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "randArr9.h"

#define ARR_SIZE 10 // 9개의 원소 + -1 (null문자 역할)
#define ARR_MAX 9 // 반복문 사용시.
#define ARR_INIT -1 // -1로 초기화.

// start값에 따라서 0 혹은 1부터 9개의 랜덤수를 리턴.
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

// start값에 따라서 0 혹은 1 부터 9개의 겹치지 않는 랜덤수로 이루어진 배열을 리턴.
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