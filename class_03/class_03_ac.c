#include <stdio.h>
#include <stdlib.h>

typedef struct deque
{
	int	*num;
	int	front, rear;
} dq;

int main()
{

	int	test_num, num, idx, temp, temp_idx, rotate, skip = 0;
	char	order[100001], temp_str[1000001];
	dq arr;

	scanf("%d", &test_num);

	idx = -1;
	while (++idx < test_num)
	{
		scanf("%s %d", order, &num);
		scanf("%s", temp_str);

		arr.front = 0;
		arr.rear = num - 1;
		arr.num = (int *)calloc(num, sizeof(int));
		temp = -1;
		temp_idx = 0;
		while (++temp < num)
		{
			while (temp_str[temp_idx] < '0' || temp_str[temp_idx] > '9')
				temp_idx++;
			while (temp_str[temp_idx] >= '0' && temp_str[temp_idx] <= '9')
				arr.num[temp] = arr.num[temp] * 10 + temp_str[temp_idx++] - '0';
		}
		rotate = 1;
		temp = -1;
		while (order[++temp])
		{
			if (order[temp] == 'R')
				rotate *= -1;
			else if (order[temp] == 'D')
			{	
				if (num == 0 || arr.front == num || arr.rear == -1)
				{
					skip = 1;
					break;
				}
				if (rotate == 1)
				{
					if (arr.front == num - 1)
						arr.front = num;
					else
						arr.front = (arr.front + 1) % num;
				}
				else
				{
					if (arr.rear == 0)
						arr.rear = -1;
					else
						arr.rear = (arr.rear - 1) % num;
				}
			}
		}

		if (skip == 1)
		{
			printf("error\n");
			skip = 0;
		}
		else if (arr.front == num || arr.rear == -1)
			printf("[]\n");
		else if (rotate == 1)
		{
			printf("[");
			while (arr.front < arr.rear)
				printf("%d,", arr.num[arr.front++]);
			printf("%d]\n", arr.num[arr.front]);
		}
		else
		{
			printf("[");
			while (arr.rear > arr.front)
				printf("%d,", arr.num[arr.rear--]);
			printf("%d]\n", arr.num[arr.rear]);
		}
		free(arr.num);
	}

	return (0);
}


//freopen("I.in", "r", stdin);
//freopen("output.txt", "w", stdout);
