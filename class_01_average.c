#include <stdio.h>

int	main()
{
	int		n;
	double	score[1000];
	double	average;
	double	total;
	int		max;
	int		idx;

	scanf("%d", &n);
	idx = 0;
	while (idx < n)
		scanf("%lf", &score[idx++]);
	idx = 0;
	while (idx < n)
	{
		if (max < score[idx])
			max = score[idx];
		idx++;
	}
	idx = 0;
	total = 0;
	while (idx < n)
	{
		total += score[idx] / max * 100;
		idx++;
	}
	printf("%.6lf", total / n);
}
