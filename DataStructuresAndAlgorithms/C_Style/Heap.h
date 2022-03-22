#pragma once

void heapInsert(int H[], int n)
{
	int i = n, temp;
	temp = H[i];

	while (i > 1 && temp > H[i / 2])
	{
		H[i] = H[i / 2];
		i = i / 2;
	}

	H[i] = temp;
}

int deleteHeap(int H[], int n)
{
	int i, j, x, temp, val;
	val = H[1];
	x = H[n];
	H[1] = H[n];
	H[n] = val;
	i = 1; j = i * 2;
	

	while (j < n - 1)
	{
		if (H[j + 1] > H[j])
			j = j + 1;
		if (H[i] < H[j])
		{
			temp = H[i];
			H[i] = H[j];
			H[j] = temp;
			i = j;
			j = 2 * j;
		}
		else
			break;
	}

	return val;
}