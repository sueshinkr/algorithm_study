#include <stdio.h>

int main()
{
	int	a, b, mul, temp;

	scanf("%d %d", &a, &b);

	mul = a * b;
	if (a < b)
	{	
		temp = a;
		a = b;
		b = temp;
	}

	while (a % b != 0)
	{	
		temp = a;
		a = b;
		b = temp % a;
	}
	
	printf("%d\n%d", b, mul / b);
	return (0);
}

// 유클리드 호제법 
