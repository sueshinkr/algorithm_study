#include <stdio.h>

int main()
{
	int	a, b, new_a, new_b;

	scanf("%d %d", &a, &b);
	new_a = a % 10 * 100 + (a / 10) % 10 * 10 + a / 100;
	new_b = b % 10 * 100 + (b / 10) % 10 * 10 + b / 100;

	if (new_a > new_b)
		printf("%d", new_a);
	else
		printf("%d", new_b);
	return (0);
}
