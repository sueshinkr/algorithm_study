#include <stdio.h>

int main()
{
	int	num, x, flag = 0, integer;

	scanf("%d %d", &num, &x);
	
	while(num-- > 0)
	{	
		scanf("%d", &integer);
		if (integer < x)
		{	
			if (flag == 1)
				printf(" ");
			printf("%d", integer);
			flag = 1;
		}
	}

	return (0);
}
