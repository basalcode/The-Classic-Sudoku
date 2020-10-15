// getArr9.c 파일은 할당받은 배열의 정보나 특정 값들을 리턴해주는 함수.
// 모든 원소는 9개의 원소를 가진 배열이며, 마지막에 -1값이 들어갈 공간을 남겨둬야함.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getArr9.h"

#include "setArr9.h"

#define ARR_SIZE 10
#define ARR_MAX 9
#define ARR_INIT -1

// 동적할당과 초기화가 완료된 배열을 리턴.
int* getArr9_allocInitArr()
{
	 int* arr = malloc(sizeof(int) * ARR_SIZE);
	 memset(arr, ARR_INIT, sizeof(int) * ARR_SIZE);

	 return arr;
}

// 배열 arr의 크기를 구해주는 함수.
int getArr9_getArrSize(int* arr)
{
	int size = 0;
	for (int i = 0; i < ARR_SIZE; i++)
	{
		if (arr[i] == -1)
			break;
		size++;
	}

	return size;
}

// arr1과 arr2의 값을 합쳐주는 함수. (단, 겹치는 원소 없이)
int* getArr9_combineArr(int* arr1, int* arr2)
{
	int* retArr = getArr9_allocInitArr();

	setArr9_removeOverlapNumber(arr1, arr2);

	int arr1Size = getArr9_getArrSize(arr1);
	int arr2Size = getArr9_getArrSize(arr2);

	int retArrSize = arr1Size + arr2Size;
	
	if (retArrSize > ARR_MAX)
	{
		printf("getArr9_combineArr 함수 애러: 생성 값이 배열의 크기보다 더 큽니다.\n");
		return NULL;
	}

	for (int i = 0; i < retArrSize; i++) // 2개의 배열 결합.
	{
		if (i < arr1Size)
		{
			retArr[i] = arr1[i];
		}
		else
		{
			retArr[i] = arr2[i - arr1Size];
		}
	}
	setArr9_setArrangedArr(retArr);

	return retArr;
}

