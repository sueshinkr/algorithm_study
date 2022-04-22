#include <stdio.h>
#include <stdlib.h>

/*
static int dp(int num, int *count)
{
	int temp1, temp2;

	if (num <= 1)
		return (0);
	else if (count[num] != 0)
		return (count[num]);

	if (num % 3 == 0)
		temp1 = dp(num / 3, count) + 1;
	else if (num % 3 == 1)
		temp1 = dp((num - 1) / 3, count) + 2;
	else
		temp1 = dp((num - 2) / 3, count) + 3;

	if (num % 2 == 0)
		temp2 = dp(num / 2, count) + 1;
	else
		temp2 = dp((num - 1) / 2, count) + 2;

	count[num] = temp1 < temp2 ? temp1 : temp2;
	return (count[num]);
}

int main()
{
	int	num, *count;

	scanf("%d", &num);
	count = (int *)calloc(num + 1, sizeof(int));
	
	printf("%d", dp(num, count));
	free(count);
	return (0);
}
*/

static int dp(int num)
{
	int temp1, temp2;

	if (num <= 1)
		return (0);
	
	temp1 = dp(num / 3) + num % 3 + 1;
	temp2 = dp(num / 2) + num % 2 + 1;

	return (temp1 < temp2 ? temp1 : temp2);
}

int main()
{
	int	num;

	scanf("%d", &num);
	
	printf("%d", dp(num));
	return (0);
}