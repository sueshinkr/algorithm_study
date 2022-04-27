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

static int compare_by_start(const void *a, const void *b)
{
	if ((*(time *)a).start == (*(time *)b).start)
		return ((*(time *)a).end - (*(time *)b).end);
	else
		return ((*(time *)a).start - (*(time *)b).start);
}

int main()
{
	int	num, idx, temp, count = 0;
	time	*t_start, *t_end;

	scanf("%d", &num);
	t_start = (time *)malloc(num * sizeof(time));
	t_end = (time *)malloc(num * sizeof(time));

	idx = -1;
	while (++idx < num)
	{
		scanf("%d %d", &t_start[idx].start, &t_start[idx].end);
		t_end[idx].start = t_start[idx].start;
		t_end[idx].end = t_start[idx].end;
	}

	qsort(t_start, num, sizeof(time), compare_by_start);
	qsort(t_end, num, sizeof(time), compare_by_end);

	temp = t_end[0].end;
	idx = 0;
	while (idx < num)
	{
		while (temp > t_start[idx].start)
		{
			idx++;
			if (idx >= num)
			{	
				count++;
				printf("%d\n", count);
				free(t_start);
				free(t_end);
				return (0);
			}
		}
		temp = t_start[idx++].end;
		count++;
		printf("temp : %d, idx : %d, count : %d\n", temp, idx, count);
		while (temp == t_start[idx].start)
		{
			if (t_start[idx].start == t_start[idx].end && idx != num - 1)
				count++;
			idx++;
		}
	}

	count++;
	printf("%d\n", count);
	free(t_start);
	free(t_end);
	return (0);
}