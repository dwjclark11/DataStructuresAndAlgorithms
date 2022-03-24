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

/*
	Partition:
	l == first element of Array
	h == last element of Array
	returns the index of j afte the partition
*/
template <typename T>
int partition(T* A, int low, int high)
{
	/*
		A[5][1][9][10][3][x][MAX];
		  ^
		pivot = A[low]
	*/
	T pivot = A[low];

	int i = low, j = high;

	do
	{
		// Increment i if smaller than pivot
		do { i++; } while (A[i] <= pivot);
	
		// Decrement j if larger than pivot
		do { j--; } while (A[j] > pivot);

		// If i surpasses j, swap the values
		if (i < j)
			swap(&A[i], &A[j]);
	} while (i < j);

	// Swap the pivot point with j and create the partition
	swap(&A[low], &A[j]);
	// Return the position of j
	return j;
}

// Quicksort is a recursive function
template <typename T>
void quickSort(T* A, int low, int high)
{
	int j;

	if (low < high)
	{
		j = partition(A, low, high);
		quickSort(A, low, j);
		quickSort(A, j + 1, high);
	}
}

template <typename T>
void merge(T A[], int low, int mid, int high)
{
	int i = low, j = mid + 1, k = low;

	// Create a temp array 
	T B[100];


	while (i <= mid && j <= high)
	{
		if (A[i] < A[j])
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}

	for (; i <= mid; i++)
		B[k++] = A[i];

	for (; j <= high; j++)
		B[k++] = A[j];

	// Copy the sorted merged value from B to A
	for (int i = low; i <= high; i++)
		A[i] = B[i];
}

// This is the iterative version of merge Sort
template <typename T>
void mergeSortI(T A[], int n)
{
	int p, low, high, mid, i;

	for (p = 2; p <= n; p = p * 2)
	{
		for (i = 0; i + p - 1 < n; i = i + p)
		{
			low = i; 
			high = i + p - 1;
			mid = (low + high) / 2;

			// Merge each small list
			merge(A, low, mid, high);
		}

		// this is for arrays that have odd elements
		// If the element is odd it will be merged with the last pair
		if (n - i > p / 2)
		{
			low = i;
			high = i + p - 1;
			mid = (low + high) / 2;
			merge(A, low, mid, n - 1);
		}
	}

	// Are there any elements remaining
	//if (p / 2 < n)
	//	merge(A, 0, p / 2 - 1, n - 1);
}

template <typename T>
void mergeSortR(T A[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		mergeSortR(A, low, mid);
		mergeSortR(A, mid + 1, high);
		merge(A, low, mid, high);
	}
}


template <typename T>
T findMax(T A[], int n)
{
	T max = T();

	for (int i = 0; i < n; i++)
	{
		if (A[i] > max)
			max = A[i];
	}
	return max;
}

/*
	Count Sort is a kind of hashing.
	- We create a new array the size of the largest element in the given array
	- Then we loop through the given array and increment the index of the new array 
		based on the value at the current index of the given array
*/
template <typename T>
void countSort(T A[], int n)
{
	int i, j;
	T max, * C;
	max = findMax(A, n);
	C = new T[max + 1];

	// Set all elements in c array to zero
	for (i = 0; i < max + 1; i++)
		C[i] = 0;

	// Increment the index based on the value of A[i]
	for (i = 0; i < n; i++)
		C[A[i]]++;

	// Reset j & i to zezo
	i = 0; j = 0;

	// Copy the indexes back into the original array.
	while (i < max + 1)
	{
		// If C[i] > 0, place the index number as the value in A[j]
		// Also increment j and decrement i. 
		if (C[i] > 0)
		{
			A[j++] = i;
			C[i]--;
		}
		else
			i++;
	}
}