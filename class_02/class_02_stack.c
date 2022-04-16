#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int		num, *stack, idx, stack_idx, push_temp;
	char	order[10];
	
	scanf("%d", &num);
	stack = (int *)malloc(num * sizeof(int));

	idx = 0;
	stack_idx = 0;
	stack[0] = -1;
	while (idx < num)
	{
		scanf("%s", order);

		if (strcmp(order, "push") == 0)
		{
			scanf("%d", &push_temp);
			stack[stack_idx++] = push_temp;
		}
		else if (strcmp(order, "pop") == 0)
		{
			if (stack[0] == -1)
				printf("-1\n");
			else
			{
				printf("%d\n", stack[--stack_idx]);
				stack[stack_idx] = -1;
			}
		}
		else if (strcmp(order, "size") == 0)
			printf("%d\n", stack_idx);
		else if (strcmp(order, "empty") == 0)
		{
			if (stack[0] == -1)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp(order, "top") == 0)
		{
			if (stack[0] == -1)
				printf("-1\n");
			else
				printf("%d\n", stack[stack_idx - 1]);
		}
		
		idx++;
	}

	return (0);
}
