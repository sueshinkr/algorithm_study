#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct child
{
	int	child;
	struct child *next;
} ch;

ch	*arr[100001];
int	result[100001];

static void	make_node(int a, int b)
{
	ch	*temp1;
	temp1 = (ch *)malloc(sizeof(ch));
	temp1->child = a;
	temp1->next = arr[b];
	arr[b] = temp1;

	ch	*temp2;
	temp2 = (ch *)malloc(sizeof(ch));
	temp2->child = b;
	temp2->next = arr[a];
	arr[a] = temp2;
}

static void	dfs(int parent)
{
	ch	*check;

	check = arr[parent];
	while (check)
	{
		if (result[check->child] == 0)
		{
			result[check->child] = parent;
			dfs(check->child);
		}
		check = check->next;
	}
}

int	main()
{
	int	n, a, b, idx;

	scanf("%d", &n);

	idx = -1;
	while(++idx < n - 1)
	{
		scanf("%d %d", &a, &b);
		make_node(a, b);
	}

	dfs(1);
	
	idx = 1;
	while (++idx <= n)
		printf("%d\n", result[idx]);
	return (0);
}