#include <stdio.h>

int main()
{
	int	num;
	
	scanf("%d", &num);

	if (num == 4 || num == 7)
		printf("-1");
	else if (num % 5 == 1 || num % 5 == 3)
		printf("%d", num / 5 + 1);
	else if (num % 5 == 2 || num % 5 == 4)
		printf("%d", num / 5 + 2);
	else
		printf("%d", num / 5);
	
	return (0);
}
