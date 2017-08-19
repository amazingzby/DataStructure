#include "sort.h"
#include <assert.h>
void quick_sort(int a[], int start, int end)
{
	if (start < end)
	{
		int i = start, j = end, x = a[start];
		while (i < j)
		{
			while (i < j&&a[j] >= x)
				j--;
			if (i < j)
				a[i++] = a[j];
			while (i < j&&a[i] < x)
				i++;
			if (i < j)
				a[j--] = a[i];
		}
		a[i] = x;
		quick_sort(a, start, i - 1);
		quick_sort(a, i + 1, end);
	}
}

void bubble_sort(int a[], int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		for (int j = i+1; j <=end; j++)
		{
			if (a[j - 1] > a[j])
			{
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
}

void select_sort(int a[], int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		for (int j = i + 1; j <= end; j++)
		{
			if (a[j] < a[i])
			{
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
}

void swap(int * array, int  i, int  j)
{
	assert(array);
    int  tmp;
	tmp = array[j];
    array[j] = array[i];
    array[i] = tmp;
}
void minHeapify(int array[], int heapSize, int currentNode)
{
	int leftChild, rightChild, minimum;
	leftChild = 2 * currentNode+1;
	rightChild = 2 * currentNode+2;
	minimum = currentNode;
	if (leftChild < heapSize&&array[leftChild] < array[currentNode])
		minimum = leftChild;
	if (rightChild < heapSize&&array[rightChild] < array[minimum])
		minimum = rightChild;
	if (minimum != currentNode)
	{
		swap(array, minimum, currentNode);
		minHeapify(array, heapSize, minimum);
	}
}
void heap_sort(int a[], int heapSize)
{
	for (int i = heapSize; i > 1; --i)
	{
		for (int j = i / 2; j >= 0; j--)
		{
			minHeapify(a, i, j);
		}
	}
}