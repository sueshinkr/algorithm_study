#include <stdio.h>
#include <stdlib.h>

static int compare(const void *a, const void *b)
{
	if (*(int *)a < *(int *)b)
		return (-1);
	else if (*(int *)a > *(int *)b)
		return (1);
	return (0);
}

int main()
{
	int	num, *num_arr, idx = 0;

	scanf("%d", &num);
	num_arr = (int *)malloc(num * sizeof(int));
	
	while (idx < num)
		scanf("%d", &num_arr[idx++]);

	qsort(num_arr, num, sizeof(int), compare);
	
	idx = 0;
	while (idx < num)
		printf("%d\n", num_arr[idx++]);

	free(num_arr);
	return (0);
}
