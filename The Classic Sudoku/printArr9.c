// setArr9.c 파일은 배열을 출력해주는 함수 파일.
// 모든 원소는 9개의 원소를 가진 배열이며, 마지막에 -1값이 들어갈 공간을 남겨둬야함.

#include <stdio.h>

#include "printArr9.h"

#include "getArr9.h"
#include "setArr9.h"

#define ARR_SIZE 10
#define ARR_MAX 9

// arr를 정렬한후 출력해주는 함수.
void printArr9_printArr(int* arr)
{
	int arrSize = getArr9_getArrSize(arr);
	for (int i = 0; i < arrSize; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return;
}