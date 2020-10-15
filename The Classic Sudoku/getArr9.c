// getArr9.c ������ �Ҵ���� �迭�� ������ Ư�� ������ �������ִ� �Լ�.
// ��� ���Ҵ� 9���� ���Ҹ� ���� �迭�̸�, �������� -1���� �� ������ ���ܵ־���.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getArr9.h"

#include "setArr9.h"

#define ARR_SIZE 10
#define ARR_MAX 9
#define ARR_INIT -1

// �����Ҵ�� �ʱ�ȭ�� �Ϸ�� �迭�� ����.
int* getArr9_allocInitArr()
{
	 int* arr = malloc(sizeof(int) * ARR_SIZE);
	 memset(arr, ARR_INIT, sizeof(int) * ARR_SIZE);

	 return arr;
}

// �迭 arr�� ũ�⸦ �����ִ� �Լ�.
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

// arr1�� arr2�� ���� �����ִ� �Լ�. (��, ��ġ�� ���� ����)
int* getArr9_combineArr(int* arr1, int* arr2)
{
	int* retArr = getArr9_allocInitArr();

	setArr9_removeOverlapNumber(arr1, arr2);

	int arr1Size = getArr9_getArrSize(arr1);
	int arr2Size = getArr9_getArrSize(arr2);

	int retArrSize = arr1Size + arr2Size;
	
	if (retArrSize > ARR_MAX)
	{
		printf("getArr9_combineArr �Լ� �ַ�: ���� ���� �迭�� ũ�⺸�� �� Ů�ϴ�.\n");
		return NULL;
	}

	for (int i = 0; i < retArrSize; i++) // 2���� �迭 ����.
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

