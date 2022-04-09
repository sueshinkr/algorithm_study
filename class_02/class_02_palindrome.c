#include <stdio.h>

int main()
{
	int	num, reverse_num, temp;

	while (1)
	{
		scanf("%d", &num);
		if (num == 0)
			break;

		temp = num;
		reverse_num = 0;
		while (temp > 0)
		{
			reverse_num *= 10;
			reverse_num += temp % 10;
			temp /= 10;
		}
		if (num == reverse_num)
			printf("yes\n");
		else
			printf("no\n");
	}

	return (0);
}

/*
static int	pow_ab(int a, int b)
{
	if (b == 0)
		return (1);
	else if (b < 0)
		return (0);
	a *= pow_ab(a, b - 1);
	return (a);
}

int main()
{
	int	num, temp, count;

	while(1)
	{
		scanf("%d", &num);
		if (num == 0)
			break;

		count = 0;
		while (num / pow_ab(10, count) > 0)
			count++;

		while (count-- > 0)
		{
			if (num / pow_ab(10, count) != num % 10)
			{	
				printf("no\n");
				break;
			}
			num = (num % pow_ab(10, count--)) / 10;
		}
		if (count < 0)
			printf("yes\n");
	}

	return (0);
}
*/
