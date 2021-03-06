#include <stdio.h>
#include <stdlib.h>

/*
static void swap(int *str1, int *str2)
{
	int	temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

static void quick_sort(int *arr, int left, int right)
{
	int	low = left + 1, high = right, pivot = left;
	
	if (left < right)
	{
		while (low <= high)
		{	
			while (arr[low] <= arr[pivot] && low < right)
				low++;
			while (arr[high] >= arr[pivot] && high > left)
				high--;
			if (low >= high)
				break;	
			swap(&arr[low], &arr[high]);
			low++;
			high--;
		}

		swap(&arr[left], &arr[high]);
		quick_sort(arr, left, high - 1);
		quick_sort(arr, low, right);
	}
}
*/

static int compare(const void *a, const void *b)
{
	if (*(int *)a < *(int *)b)
		return (-1);
	else if (*(int *)a > *(int *)b)
		return (1);
	return (0);
}

static int binary_search(int *set_num_array, int set_num, int find_num)
{
	int	min = 0, max = set_num;
	int ans;

	while (min <= max)
	{
		ans = (min + max) / 2;
		if (find_num == set_num_array[ans])
			return (1);
		else if (find_num < set_num_array[ans])
			max = ans - 1;
		else
			min = ans + 1;
	}

	return (0);
}

int main()
{
	int	set_num, find_num;
	int	*set_num_array, *find_num_array;
	int	left, right, pivot, idx;

	scanf("%d", &set_num);
	set_num_array = (int *)malloc(set_num * sizeof(int));
	idx = -1;
	while (++idx < set_num)
		scanf("%d", &set_num_array[idx]);

	scanf("%d", &find_num);
	find_num_array = (int *)malloc(find_num * sizeof(int));
	idx = -1;
	while (++idx < find_num)
		scanf("%d", &find_num_array[idx]);

	qsort(set_num_array, set_num, sizeof(int), compare);

	idx = -1;
	while (++idx < find_num)
		printf("%d\n", binary_search(set_num_array, set_num - 1, find_num_array[idx]));
	free(set_num_array);
	free(find_num_array);
	return (0);
}

/*

set_num_array를 퀵정렬로 정렬 << ok
이진탐색으로 탐색

*/
