#include <stdio.h>

int main()
{
	int	num, temp, count = 0;

	scanf("%d", &num);

	while (num > 0)
	{
		temp = num;
		while (temp > 0)
		{
			if (temp % 5 == 0)
			{
				count++;
				temp /= 5;
			}
			else
				break;
		}
		num--;
	}
	
	printf("%d", count);
	return (0);
}