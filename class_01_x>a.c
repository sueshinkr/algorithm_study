#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	num, x, flag = 0;
	int	*integer;

	scanf("%d %d", &num, &x);
	integer = (int *)malloc(num * sizeof(int));
	
	while(num-- > 0)
	{	
		scanf("%d", integer);
		if (*integer < x)
		{	
			if (flag == 1)
				printf(" ");
			printf("%d", *integer);
			flag = 1;
		}
	}

	return (0);
}
