#include <stdio.h>

int main()
{
	int	year;

	scanf("%d", &year);
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				;
			else
			{	
				printf("0");
				return (0);
			}
		}
		printf("1");
		return (0);
	}
	printf("0");
	return (0);
}
