#include "sort.h"
#include <stdio.h>

/*
 * File: 106-bitonic_sort.c
 * Auth: JORDAN L. MEFUJIE, JOSHUA A.
 */
void swap(int *a, int *b)
void bitonic_compare(int up, int *array, size_t start, size_t end)
void bitonic_merge(int up, int *array, size_t start, size_t end)
void _bitonic_sort(int up, int *array, size_t size, size_t start, size_t end)
void bitonic_sort(int *array, size_t size)


/**
 * swap - Swaps 2 integer values
 * @a: Address of first value
 * @b: Address of second value
 *
 * Return: Always void
 */
void swap(int *a, int *b)
{
    if (*a != *b)
    {
        *a = *a + *b;
        *b = *a - *b;
        *a = *a - *b;
    }
/**
 * bitonic_compare – Compares of bitonically
 * @up: True if UP sorting
 * @array: The Array Pointer
 * @start: The Start Index
 * @end: The Stop Index
 */
void bitonic_compare(int up, int *array, size_t start, size_t end)
{
	size_t half = (end - start + 1) / 2, i;

	for (i = start; i < start + half; i++)
		if ((array[i] > array[i + half]) == up)
			swap(&array[i], &array[i + half]);
}

/**
 * bitonic_merge – merges of bitonically
 * @up: True if UP sorting
 * @array: The Array Pointer
 * @start: The Start Index
 * @end: The Stop Index
 */
void bitonic_merge(int up, int *array, size_t start, size_t end)
{
	size_t mid = (start + end) / 2;

	if (end - start < 1)
		return;
	bitonic_compare(up, array, start, end);
	bitonic_merge(up, array, start, mid);
	bitonic_merge(up, array, mid + 1, end);
}

/**
 * _bitonic_sort - Sorts of bitonically by recursion
 * @up: True if UP sorting
 * @array: The array pointer
 * @size: The length of the array
 * @start: The start index
 * @end: The stop index
 */
void _bitonic_sort(int up, int *array, size_t size, size_t start, size_t end)
{
	size_t mid = (start + end) / 2;

	if (end - start < 1)
		return;
	printf("Merging [%lu/%lu] (%s):\n", end - start + 1, size,
		up ? "UP" : "DOWN");
	print_array(array + start, end - start + 1);
	_bitonic_sort(1, array, size, start, mid);
	_bitonic_sort(0, array, size, mid + 1, end);
	bitonic_merge(up, array, start, end);
	printf("Result [%lu/%lu] (%s):\n", end - start + 1, size,
		up ? "UP" : "DOWN");
	print_array(array + start, end - start + 1);
}

/**
 * bitonic_sort – Sorts of  bitonically
 * @array: The array pointer
 * @size: The length of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	_bitonic_sort(1, array, size, 0, size - 1);
}

