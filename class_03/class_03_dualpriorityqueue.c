#include <stdio.h>
#include <stdlib.h>

int data[1000001] = {0, };
int	key_idx = 0;

typedef struct num
{
	int	value;
	int	key;
} n;

static void	insert_que(n *arr_min, n *arr_max, int *min, int *max)
{
	int	new, idx_min, idx_max;

	scanf("%d", &new);
	idx_min = ++(*min);
	idx_max = ++(*max);

	while (idx_min != 1 && new < arr_min[idx_min / 2].value)
	{
		arr_min[idx_min].value = arr_min[idx_min / 2].value;
		arr_min[idx_min].key = arr_min[idx_min / 2].key;
		idx_min = idx_min / 2;
	}
	arr_min[idx_min].value = new;
	arr_min[idx_min].key = key_idx;

	while (idx_max != 1 && new > arr_max[idx_max / 2].value)
	{
		arr_max[idx_max].value = arr_max[idx_max / 2].value;
		arr_max[idx_max].key = arr_max[idx_max / 2].key;
		idx_max = idx_max / 2;
	}
	arr_max[idx_max].value = new;
	arr_max[idx_max].key = key_idx++;
	data[arr_max[idx_max].key] = 0;
}

static void	delete_min(n *arr_min, int *min)
{
	if (*min == 0)
		return ;

	int	parent = 1, child = 2;
	int	temp_value = arr_min[*min].value, temp_key = arr_min[*min].key;
	data[arr_min[1].key] = -1;
	
	while (child <= *min)
	{
		if ((child < *min) && (arr_min[child].value > arr_min[child + 1].value))
			child++;
		if (temp_value <= arr_min[child].value)
			break;
		arr_min[parent].value = arr_min[child].value;
		arr_min[parent].key = arr_min[child].key;
		parent = child;
		child *= 2;
	}
	(*min)--;
	arr_min[parent].value = temp_value;
	arr_min[parent].key = temp_key;
}

static void	delete_max(n *arr_max, int *max)
{
	if (*max == 0)
		return ;
	
	int	parent = 1, child = 2;
	int	temp_value = arr_max[*max].value, temp_key = arr_max[*max].key;
	data[arr_max[1].key] = -1;

	while (child <= *max)
	{
		if ((child < *max) && (arr_max[child].value < arr_max[child + 1].value))
			child++;
		if (temp_value >= arr_max[child].value)
			break;
		arr_max[parent].value = arr_max[child].value;
		arr_max[parent].key = arr_max[child].key;
		parent = child;
		child *= 2;
	}

	(*max)--;
	arr_max[parent].value = temp_value;
	arr_max[parent].key = temp_key;
}

int main()
{
	int		test_num, data_num, minmax;
	int		min = 0, max = 0, count = 0;
	char	temp;
	n *arr_min, *arr_max;

	scanf("%d", &test_num);
	while (test_num-- > 0)
	{
		scanf("%d", &data_num);
		arr_min = (n *)malloc(data_num * sizeof(n));
		arr_max = (n *)malloc(data_num * sizeof(n));
		key_idx = 0, min = 0, max = 0, count = 0;
		while (data_num-- > 0)
		{
			scanf(" %c", &temp);
			if (temp == 'I')
			{
				insert_que(arr_min, arr_max, &min, &max);
				count++;
			}
			else
			{
				scanf("%d", &minmax);
				if (count != 0)
				{
					if (minmax == -1)
						delete_min(arr_min, &min);
					else
						delete_max(arr_max, &max);
					count--;
				}
				while (max > 0 && data[arr_max[1].key] == -1)
					delete_max(arr_max, &max);
				while (min > 0 && data[arr_min[1].key] == -1)
					delete_min(arr_min, &min);
			}
		}
		if (count == 0)
			printf("EMPTY\n");
		else
			printf("%d %d\n", arr_max[1].value, arr_min[1].value);
	}

	return (0);
}
