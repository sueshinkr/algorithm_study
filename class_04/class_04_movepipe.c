#include <stdio.h>

struct pipe
{
	int r;
	int c;
	int d;
};

int	n, count = 0;
int	arr[16][16];


static int	check()
{
	struct pipe p[16][16];
	int r, c;

	r = -1;
	while (++r < n)
	{
		c = -1;
		while (++c < n)
		{
			p[r][c].r = 0;
			p[r][c].c = 0;
			p[r][c].d = 0;
		}
	}

	p[0][1].r = 1;

	r = -1;
	while (++r < n)
	{
		c = 1;
		while (++c < n)
		{
			if (arr[r][c] == 0)
			{
				if (c > 0 && (p[r][c - 1].r != 0 || p[r][c - 1].d != 0))
					p[r][c].r += (p[r][c - 1].r + p[r][c - 1].d);
				if (r > 0 && (p[r - 1][c].c != 0 || p[r - 1][c].d != 0))
					p[r][c].c += (p[r - 1][c].c + p[r - 1][c].d);
				if (r > 0 && c > 0 && arr[r - 1][c] == 0 && arr[r][c - 1] == 0)
				{
					if (p[r - 1][c - 1].r != 0 || p[r - 1][c - 1].c != 0 || p[r - 1][c - 1].d != 0)
						p[r][c].d += (p[r - 1][c - 1].r + p[r - 1][c - 1].c + p[r - 1][c - 1].d);
				}
			}
		}
	}

	return (p[n - 1][n - 1].r + p[n - 1][n - 1].c + p[n - 1][n - 1].d);
}

int	main()
{
	int	r, c;

	scanf("%d", &n);

	r = -1;
	while (++r < n)
	{
		c = -1;
		while (++c < n)
			scanf("%d", &arr[r][c]);
	}

	printf("%d\n", check());
}
