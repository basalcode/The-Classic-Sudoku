// setArr9.c ������ �迭�� ������ִ� �Լ� ����.
// ��� ���Ҵ� 9���� ���Ҹ� ���� �迭�̸�, �������� -1���� �� ������ ���ܵ־���.

#include <stdio.h>

#include "printArr9.h"

#include "getArr9.h"
#include "setArr9.h"

#define ARR_SIZE 10
#define ARR_MAX 9

// arr�� �������� ������ִ� �Լ�.
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