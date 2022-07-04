#include <stdio.h>

int	n;
int	count[1000000] = {0, };

int main()
{
	scanf ("%d", &n);

	count[--n] = 1;
	count[--n] = 2;

	while (--n >= 0)
		count[n] = (count[n + 1] + count[n + 2]) % 15746;
	printf("%d\n", count[0]);
	return (0);
}