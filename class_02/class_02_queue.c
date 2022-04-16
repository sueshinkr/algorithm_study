#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue
{
	int	num;
	struct queue *next;
} que;

static void	push_queue(que *head, int push_temp)
{
	que	*new;

	while (head->next)
		head = head->next;
	new = (que *)malloc(sizeof(que));
	new->num = push_temp;
	new->next = NULL;
	head->next = new;
}

static void	pop_queue(que *head)
{
	que *temp;

	if (!head->next)
	{	
		printf("-1\n");
		return ;
	}

	temp = head->next;
	printf("%d\n", temp->num);
	head->next = head->next->next;
	free(temp);
}

static void	size_queue(que *head)
{
	int	count = 0;

	while (head->next)
	{
		count++;
		head = head->next;
	}

	printf("%d\n", count);
}

static void	back_queue(que *head)
{
	if (!head->next)
	{
		printf("-1\n");
		return ;
	}

	while (head->next)
		head = head->next;
	
	printf("%d\n", head->num);
}

int main()
{
	int		num, idx, push_temp;
	char	order[10];
	que		*head;
	
	scanf("%d", &num);
	head = (que *)malloc(sizeof(que));
	head->next = NULL;

	idx = 0;
	while (idx < num)
	{
		scanf("%s", order);

		if (strcmp(order, "push") == 0)
		{
			scanf("%d", &push_temp);
			push_queue(head, push_temp);
		}
		else if (strcmp(order, "pop") == 0)
			pop_queue(head);
		else if (strcmp(order, "size") == 0)
			size_queue(head);
		else if (strcmp(order, "empty") == 0)
		{
			if (!head->next)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp(order, "front") == 0)
		{
			if (!head->next)
				printf("-1\n");
			else
				printf("%d\n", head->next->num);
		}
		else if (strcmp(order, "back") == 0)
			back_queue(head);
		
		idx++;
	}

	return (0);
}
