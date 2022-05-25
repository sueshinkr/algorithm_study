#include <stdio.h>
#include <math.h>

int	min[50001] = {0, };

static int	cal(int	n)
{
	int	temp, sqrt_n, idx = 0, ans;

	if (min[n] == 0)
		min[n] = 4;
	else
		return min[n];

	sqrt_n = (int)sqrt(n);
	while (sqrt_n - idx > 0)
	{
		temp = n - (int)pow(sqrt_n - idx, 2);
		if (temp == 0)
		{
			min[n] = 1;
			break;
		}
		else
		{
			ans = cal(temp) + 1;
			if (ans < min[n])
				min[n] = ans;
		}
		idx++;
	}
	return (min[n]);
}

int	main()
{
	int	n;

	scanf("%d", &n);

	printf("%d\n", cal(n));
	return (0);
}

/*
int main()
{
	int n;
	int i, j, k;
	scanf("%d", &n);

	char array[150000] ={0};

	for (i = 1; i < 224; i++)
	{
		for (j = 1; j <= i; j++)
		{
			for (k = 1; k <= j; k++)
			{
				array[i * i + j * j + k * k] = 1;
			}
		}
	}

	for (i = 1; i < 224; i++)
	{
		for (j = 1; j < 224; j++)
		{
			array[i * i + j * j] = 2;
		}
	}

	for (i = 1; i < 224; i++) array[i * i] = 3;

	printf("%d", 4 - array[n]);

	return 0;
}

*/