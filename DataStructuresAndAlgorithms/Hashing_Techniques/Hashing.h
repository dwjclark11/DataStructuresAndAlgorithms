#pragma once

#define SIZE 10

template <typename T>
int hash(T key)
{
	return key % SIZE;
}

template <typename T>
int probe(T H[], T key)
{
	int index = hash(key);
	int i = 0;
	while (H[(index + i) % SIZE] != 0)
		i++;

	return (index + i) % SIZE;
}

template <typename T>
void insertHash(T H[], T key)
{
	int index = hash<T>(key);

	if (H[index] != 0)
		index = probe(H, key);

	H[index] = key;
}

template <typename T>
int search(T  H[], T key)
{
	int index = hash(key);

	int i = 0;

	while (H[(index + i) % SIZE] != key && H[(index + i) % SIZE] != 0)
		i++;
	if (H[(index + i) % 10] == key)
		return (index + i) % SIZE;
	else
		return -1;
}