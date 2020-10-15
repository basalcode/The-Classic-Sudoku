// setArr9.c 파일은 배열의 원소값등을 특정하게 바꿔주는 역할을 하는 함수 파일.
// 모든 원소는 9개의 원소를 가진 배열이며, 마지막에 -1값이 들어갈 공간을 남겨둬야함.

#include "setArr9.h"
#include "getArr9.h"

#define ARR_SIZE 10
#define ARR_MAX 9

// 배열내의 2개 원소의 자리를 서로 바꿔주는 함수.
void setArr9_setSwap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	
	return;
}

// arr 배열의 공백을 없애 줌.
void setArr9_setNoBlankArr(int* arr)
{
	for (int i = 0; i < ARR_MAX; i++) // 공백 제거
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

// arr 배열을 공백이 있다면 공백제거를 한후 오름차순으로 정렬해줌.
void setArr9_setArrangedArr(int* arr)
{
	setArr9_setNoBlankArr(arr);
	
	for (int i = 0; i < ARR_MAX; i++) // 오름차순
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

// arr1에서 arr2와 겹치는 값을 빼주는 함수.
void setArr9_removeOverlapNumber(int* arr1, int* arr2)
{
	int arr1Size = getArr9_getArrSize(arr1);
	int arr2Size = getArr9_getArrSize(arr2);

	for (int i = 0; i < arr1Size; i++) // 겹치는 원소 arr1에서 삭제
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