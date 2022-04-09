#include <stdio.h>

int main()
{
	int		n, idx = 0, result = 0;
	char	num[100];
	
	scanf("%d", &n);
	scanf("%s", num);
	
	while (idx < n)
		result += num[idx++] - '0';

	printf("%d", result);
	return (0);
}
