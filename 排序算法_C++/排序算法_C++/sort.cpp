#include "sort.h"
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