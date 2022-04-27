#include <stdio.h>
#include <stdlib.h>

typedef struct use_time
{
	int	start;
	int	end;
} time;

static int compare_by_end(const void *a, const void *b)
{
	if ((*(time *)a).end == (*(time *)b).end)
		return ((*(time *)a).start - (*(time *)b).start);
	else
		return ((*(time *)a).end - (*(time *)b).end);
}

int main()
{
	int	num, idx, temp, count = 1;
	time	*t_end;

	scanf("%d", &num);
	t_end = (time *)malloc(num * sizeof(time));

	idx = -1;
	while (++idx < num)
		scanf("%d %d", &t_end[idx].start, &t_end[idx].end);

	qsort(t_end, num, sizeof(time), compare_by_end);

	temp = t_end[0].end;
	idx = 0;
	while (++idx < num)
	{
		if (temp <= t_end[idx].start)
		{
			temp = t_end[idx].end;
			count++;
		}
	}
	
	printf("%d", count);
	free(t_end);
	return (0);
}
