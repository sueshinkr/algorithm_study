#include <stdio.h>

static int check(int create, int breaksum)
{
	int	result;

	result = create;
	while (create > 0)
	{
		result += (create % 10);
		create /= 10;
	}

	if (result == breaksum)
		return (1);
	else
		return (0); 
}
int main()
{
	int	breaksum, temp, count = 1;

	scanf("%d", &breaksum);
	
	temp = breaksum;
	while (temp /= 10)
		count++;
	count *= 9;
	
	while (count > 0)
	{
		if (check(breaksum - count, breaksum))
		{
			printf("%d", breaksum - count);
			return (0);
		}
		count--;
	}
	
	printf("0");
	return (0);
}
