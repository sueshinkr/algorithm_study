#include <stdio.h>

int main()
{
	int	num, temp, end = 0, end_count = 0;

	scanf("%d", &num);

	while(1)
	{
		temp = end;
		while (temp > 0)
		{	
			if (temp % 1000 == 666)
			{
				end_count++;
				break;
			}
			temp /= 10;
		}

		if(end_count == num)
		{	
			printf("%d", end);
			break;
		}

		end++;
	}
	
	return (0);
}

/*
int main()
{
	int	num, temp;
	int	end = 0, end_count = 0, count = 0;

	scanf("%d", &num);

	while(1)
	{
		temp = end;
		count = 0;
		while (temp > 0)
		{	
			if (temp % 10 == 6)
				count++;
			else
				count = 0;
			
			if (count == 3)
				end_count++;
			if (end_count == num)
			{	
				printf("%d", end);
				return (0);
			}
			temp /= 10;
		}
		end++;
	}
	
	return (0);
}
*/
