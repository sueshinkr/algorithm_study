#include <stdio.h>
#include <stdlib.h>

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

int main()
{
	int	set_num, find_num;
	int	*set_num_array, *find_num_array;
	int	left, right, pivot, idx;

	scanf("%d", &set_num);
	set_num_array = (int *)malloc((set_num + 1)* sizeof(int));
	
	idx = 0;
	while (idx < set_num)
		scanf("%d", &set_num_array[idx++]);
	set_num_array[idx] = 0;

	scanf("%d", &find_num);
	find_num_array = (int *)malloc(find_num * sizeof(int));

	idx = 0;
	while (idx < find_num)
		scanf("%d", &find_num_array[idx++]);

	quick_sort(set_num_array, 0, set_num - 1);

	printf(":::::::::\n");
	idx = 0;
	while (idx < set_num)
		printf("%d ", set_num_array[idx++]);

	return (0);
}

/*

set_num_array를 퀵정렬로 정렬 << ok
이진탐색으로 탐색

*/
