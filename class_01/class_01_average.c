#include <stdio.h>

int	main()
{
	int		n;
	double	score[1000], total = 0;
	int		max = 0;
	int		idx = 0;

	scanf("%d", &n);

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
	while (idx < n)
		total += score[idx++] / max * 100;

	printf("%.6lf", total / n);
	return (0);
}
