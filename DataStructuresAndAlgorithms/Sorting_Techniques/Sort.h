#pragma once

template <typename T>
void swap(T* a, T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <typename T>
void bubbleSort(T* A, int n)
{
	int flag = 0;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (A[j] > A[j + 1])
			{
				swap(&A[j], &A[j + 1]);
				flag = 1;
			}
			if (!flag) break;
		}
	}
}

template <typename T>
void insertionSort(T* A, int n)
{
	T x;
	int j;

	for (int i = 1; i < n; i++)
	{
		j = i - 1; 
		x = A[i];

		while (j > -1 && A[j] > x)
		{
			// Shift all elements
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;
	}
}

template <typename T>
void selectionSort(T* A, int n)
{
	int k;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = k = i; j < n; j++)
		{
			if (A[j] < A[k])
				k = j;
		}
		swap(&A[i], &A[k]);
	}
}