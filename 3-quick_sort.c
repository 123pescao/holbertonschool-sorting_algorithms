#include "sort.h"

/**
*quick_sort - Sorts an array of integers in ascending order using Quick sort
*@array: Pointer to the array to be sorted
*@size: Size of the array
*/

void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_recursive(array, 0, size - 1, size);
}

/**
*quicksort_recursive - Recursively sorts a partition of an array
*@array: Pointer to the array to be sorted
*@low: The starting index of the partition to be sorted
*@high: The ending index of the partition to be sorted
*@size: The size of the original array
*/

void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto_partition(array, low, high, size);
		quicksort_recursive(array, low, pivot_idx - 1, size);
		quicksort_recursive(array, pivot_idx + 1, high, size);
	}

	if (low == 0 && high == (int)(size - 1))
		print_array(array, size);
}

/**
*lomuto_partition - Partitions the array using Lomuto partition scheme
*@array: Pointer to the array to be partitioned
*@low: The starting index of the partition
*@high: The ending index of the partition
*@size: The size of the original array
*Return: The index of the pivot element
*/

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (temp != array[i])
				print_array(array, size);
		}
    }

    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    if (temp != array[i + 1])
        print_array(array, size);

    return (i);
}
