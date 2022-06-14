#include <stdio.h>
#define MIN(x, y) ((x < y) ? (x) : (y))
#define MAX 2147483647

int	check[200001] = {0, };

int	value(int n, int k)
{
	int q[100001], front = 0, rear = 0, cur;

	check[n] = 1;
	q[front] = n;
	if (n >= k)
		return (n - k + 1);
	while (front <= rear)
	{
		cur = q[front++];
		if (cur == k)
			return (check[k]);
		if ((check[cur * 2] == 0) && (cur * 2 <= 100000))
		{
			check[cur * 2] = check[cur];
			q[--front] = cur * 2;
		}
		if ((check[cur - 1] == 0) && (cur - 1 >= 0))
		{
			check[cur - 1] = check[cur] + 1;
			q[++rear] = cur - 1;
		}
		if ((check[cur + 1] == 0) && (cur + 1 <= 100000))
		{
			check[cur + 1] = check[cur] + 1;
			q[++rear] = cur + 1;
		}
	}
	return (-1);
}

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);

	printf("%d\n", value(n, k) - 1);
	return 0;
}


// 0-1 bfs
