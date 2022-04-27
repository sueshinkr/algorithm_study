#include <stdio.h>
#include <stdlib.h>

static void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int	num, temp, idx, temp_idx, arr_idx = 0, *arr;

	scanf("%d", &num);
	arr = (int *)calloc(num + 1, sizeof(int));

	idx = -1;
	while (++idx < num)
	{
		scanf("%d", &temp);
		if (temp > 0)
		{
			temp_idx = ++arr_idx;
			arr[temp_idx] = temp;
			while (temp_idx > 1)
			{
				if (arr[temp_idx] < arr[temp_idx / 2])
				{
					swap(&arr[temp_idx], &arr[temp_idx / 2]);
					temp_idx /= 2;
				}
				else
					break ;
			}
		}
		else
		{
			if (arr_idx == 0)
			{
				printf("0\n");
				continue ;
			}

			printf("%d\n", arr[1]);
			arr[1] = arr[arr_idx];
			temp_idx = 1;
			while (temp_idx * 2 < arr_idx)
			{
				if (arr[temp_idx] > arr[temp_idx * 2] || arr[temp_idx] > arr[temp_idx * 2 + 1])
				{
					if (arr[temp_idx * 2] <= arr[temp_idx * 2 + 1])
					{	
						swap(&arr[temp_idx], &arr[temp_idx * 2]);
						temp_idx = temp_idx * 2;
					}
					else if (arr[temp_idx * 2] > arr[temp_idx * 2 + 1])
					{
						swap(&arr[temp_idx], &arr[temp_idx * 2 + 1]);
						temp_idx = temp_idx * 2 + 1;
					}
				}
				else
					break ;
			}
			arr[arr_idx--] = 0;
		}

	}

	free(arr);
	return (0);
}
