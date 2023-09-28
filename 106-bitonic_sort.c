#include "sort.h"
#include <stdio.h>

/*
 * File: 106-bitonic_sort.c
 * Auth: JORDAN L. MEFUJIE, JOSHUA A.
 */

void bitonic_compare(bool up, int *x, size_t size)
void bitonic_merge(bool up, int *x, size_t size, size_t orig_size)
void bitonic_sort_r(bool up, int *x, size_t size, size_t orig_size)
void bitonic_sort(int *array, size_t size)


/**
 * bitonic_compare - helper to bitonic_merge, sorts contents of current
 * subarray
 * @up: If true, sort in ascending order, false, descending
 * @x: Subarray in current frame of recursion
 * @size: Number of elements in “x”
 */
void bitonic_compare(bool up, int *x, size_t size)
{
	size_t dist, i;
	int tmp;

	dist = size / 2;
	for (i = 0; i < dist; i++)
	{
		if ((x[i] > x[i + dist]) == up)
		{
			tmp = x[i];
			x[i] = x[i + dist];
			x[i + dist] = tmp;
		}
	}
}

/**
 * bitonic_merge - Second recursive function of bitonic_sort, sorts subarrays
 * via the bitonic_compare, and merges the sorted results together.
 * @up: If true, sort in ascending order, false, descending
 * @x: Subarray in the Previous frame of recursion
 * @size: Number of elements in “x”
 * @orig_size: Number of elements in source array being sorted
 */
void bitonic_merge(bool up, int *x, size_t size, size_t orig_size)
{
	int *first, *second;

	if (size > 1)
	{
		first = x;
		second = x + (size / 2);
		bitonic_compare(up, x, size);
		bitonic_merge(up, first, size / 2, orig_size);
		bitonic_merge(up, second, size / 2, orig_size);
	}
}

/**
 * bitonic_sort_r - First recursive engine of bitonic_sort, divides
 * array into a binary tree of subarrays, and assigns sorting order.
 * @up: If true, sort in ascending order, false, descending
 * @x: Subarray in the previous frame of recursion
 * @size: Number of elements in “x”
 * @orig_size: Number of elements in source array being sorted
 */
void bitonic_sort_r(bool up, int *x, size_t size, size_t orig_size)
{
	int *first, *second;

	if (size <= 1)
		return;
	first = x;
	second = x + (size / 2);
	printf("Merging [%lu/%lu] (%s):\n", size, orig_size,
	       (up ? "UP" : "DOWN"));
	print_array(x, size);
	bitonic_sort_r(true, first, size / 2, orig_size);
	bitonic_sort_r(false, second, size / 2, orig_size);
	bitonic_merge(up, first, size, orig_size);
	printf("Result [%lu/%lu] (%s):\n", size, orig_size,
	       (up ? "UP" : "DOWN"));
	print_array(x, size);
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order 
 * using a bitonic sort alogrithm
 * @array: Array of values to be Printed
 * @size: Number of elements in the Array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;

	bitonic_sort_r(true, array, size, size);
}

