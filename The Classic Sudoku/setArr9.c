// setArr9.c ������ �迭�� ���Ұ����� Ư���ϰ� �ٲ��ִ� ������ �ϴ� �Լ� ����.
// ��� ���Ҵ� 9���� ���Ҹ� ���� �迭�̸�, �������� -1���� �� ������ ���ܵ־���.

#include "setArr9.h"
#include "getArr9.h"

#define ARR_SIZE 10
#define ARR_MAX 9

// �迭���� 2�� ������ �ڸ��� ���� �ٲ��ִ� �Լ�.
void setArr9_setSwap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	
	return;
}

// arr �迭�� ������ ���� ��.
void setArr9_setNoBlankArr(int* arr)
{
	for (int i = 0; i < ARR_MAX; i++) // ���� ����
	{
		if (arr[i] == -1)
		{
			for (int j = i + 1; j < ARR_MAX; j++)
			{
				if (arr[j] != -1)
				{
					setArr9_setSwap(&arr[i], &arr[j]);
					break;
				}
			}
		}
	}
}

// arr �迭�� ������ �ִٸ� �������Ÿ� ���� ������������ ��������.
void setArr9_setArrangedArr(int* arr)
{
	setArr9_setNoBlankArr(arr);
	
	for (int i = 0; i < ARR_MAX; i++) // ��������
	{
		int min = arr[i];
		int pos = -1;
		for (int j = i + 1; j < ARR_MAX; j++)
		{
			if (arr[j] == -1)
				break;

			if (min > arr[j])
			{
				min = arr[j];
				pos = j;
			}
		}
		if (pos == -1)
			break;
		setArr9_setSwap(&arr[i], &arr[pos]);
	}

	return;
}

// arr1���� arr2�� ��ġ�� ���� ���ִ� �Լ�.
void setArr9_removeOverlapNumber(int* arr1, int* arr2)
{
	int arr1Size = getArr9_getArrSize(arr1);
	int arr2Size = getArr9_getArrSize(arr2);

	for (int i = 0; i < arr1Size; i++) // ��ġ�� ���� arr1���� ����
	{
		for (int j = 0; j < arr2Size; j++)
		{
			if (arr1[i] == arr2[j])
				arr1[i] = -1;
		}
	}
	setArr9_setArrangedArr(arr1);

	return;
}