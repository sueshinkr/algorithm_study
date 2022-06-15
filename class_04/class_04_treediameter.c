#include <stdio.h>
#define MAX(x, y) ((x > y) ? (x) : (y)) 

struct tree
{
	int parent;
	int	weight;
};

int	n, max_ans = 0;
struct tree t[10001];

static void	make_tree()
{
	int	idx, parent, child, weight;

	idx = 0;
	while (++idx < n)
	{
		scanf("%d %d %d", &parent, &child, &weight);

		t[child].parent = parent;
		t[child].weight = weight;
	}
}

static int	find_dia(int cur)
{
	int	idx, len, first_max = 0, second_max = 0;

	idx = cur;
	while (++idx <= n)
	{
		if (t[idx].parent == cur)
		{
			len = find_dia(idx);
			if (len > first_max)
			{
				second_max = first_max;
				first_max = len;
			}
			else if (len > second_max)
				second_max = len;
		}
	}

	if (first_max + second_max > max_ans)
		max_ans = first_max + second_max;
	return (t[cur].weight + first_max);
}

int	main()
{
	scanf("%d", &n);

	make_tree();
	find_dia(1);
	printf("%d\n", max_ans);
}