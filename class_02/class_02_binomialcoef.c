#include <stdio.h>

int main()
{
	int	n, k, temp, result = 1;

	scanf("%d %d", &n, &k);

	temp = -1;
	while (++temp < k)
		result *= n--;
	while (temp-- > 0)
		result /= k--;

	printf("%d", result);
}
