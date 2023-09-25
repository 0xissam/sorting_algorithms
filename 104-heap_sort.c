#include "sort.h"
#include <stdio.h>

/**
 * swap - utility func to swap 2 int
 * @a: integer a
 * @b: integer b
 **/
void swap(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}

/**
 * maxHeapify - func to heapify a Max Heap. The func
 * assumes that everything under given root (element at index idx)
 * is already heapified
 * @array: array aa
 * @size: array size for print
 * @idx: index i
 * @n: array size of run
 */
void maxHeapify(int *array, size_t size, int idx, size_t n)
{
	int largest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < (int)n && array[left] > array[largest])
		largest = left;

	if (right < (int)n && array[right] > array[largest])
		largest = right;

	if (largest != idx)
	{
		swap(&array[idx], &array[largest]);
		print_array(array, size);
		maxHeapify(array, size, largest, n);
	}
}

/**
 * heap_sort -  func to sort an array of given size
 * @array: array to sort
 * @size: size of array
 **/
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == '\0' || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; --i)
		maxHeapify(array, size, i, size);

	for (i = (size - 1); i > 0; --i)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);

		maxHeapify(array, size, 0, i);
	}
}
