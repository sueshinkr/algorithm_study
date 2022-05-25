#include <stdio.h>
#include <stdlib.h>

static void	bfs(int *arr, int *check)
{
	int	front = 0, rear = 0, cur, idx;
	int	que[1000] = {0, };

	que[0] = 1;
	while (front <= rear)
	{
		if (que[front] == 100)
			break;

		cur = que[front];
		idx = 0;
		while (++idx < 7)
		{
			if (cur + idx <= 100)
			{
				if (arr[cur + idx] != 0)
				{
					if (check[arr[cur + idx]] == 0)
					{
						que[++rear] = arr[cur + idx];
						check[que[rear]] = check[cur] + 1;
					}
				}
				else
				{
					if (check[cur + idx] == 0)
					{
						que[++rear] = cur + idx;
						check[que[rear]] = check[cur] + 1;
					}
				}
			}
		}
		front++;
	}
}



int	main()
{
	int		ladder_num, snake_num, arr[101] = {0, }, check[101] = {0, };
	int		x, y, u, v;

	scanf("%d %d", &ladder_num, &snake_num);

	while(ladder_num-- > 0)
	{
		scanf("%d %d", &x, &y);
		arr[x] = y;
	}
	while(snake_num-- > 0)
	{
		scanf("%d %d", &u, &v);
		arr[u] = v;
	}

	bfs(arr, check);

	printf("%d\n", check[100]);
	return (0);
}