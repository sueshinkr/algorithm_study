#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct deque
{
	int	num;
	struct deque	*next;
	struct deque	*before;
} dq;

static void	push_front(dq *head)
{
	dq	*new;
	int	push_temp;

	scanf("%d", &push_temp);

	new = (dq *)malloc(sizeof(dq));
	new->num = push_temp;
	new->next = head->next;
	new->before = head;
	head->next = new;
	new->next->before = new;
}

static void	push_back(dq *tail)
{
	dq	*new;
	int	push_temp;

	scanf("%d", &push_temp);

	new = (dq *)malloc(sizeof(dq));
	new->num = push_temp;
	new->next = tail;
	new->before = tail->before;
	new->before->next = new;
	tail->before = new;
}

static void	pop_front(dq *head)
{
	dq *temp;

	if (!head->next->next)
	{	
		printf("-1\n");
		return ;
	}

	temp = head->next;
	printf("%d\n", temp->num);
	head->next = head->next->next;
	head->next->before = head;
	free(temp);
}

static void	pop_back(dq *tail)
{
	dq *temp;

	if (!tail->before->before)
	{	
		printf("-1\n");
		return ;
	}

	temp = tail->before;
	printf("%d\n", temp->num);
	tail->before = tail->before->before;
	tail->before->next = tail;
	free(temp);
}

static void	size_dq(dq *head)
{
	int	count = -1;

	while (head->next)
	{
		count++;
		head = head->next;
	}

	printf("%d\n", count);
}

static void	empty_dq(dq *head)
{
	if (!head->next->next)
		printf("1\n");
	else
		printf("0\n");
}

static void	front_dq(dq *head)
{
	if (!head->next->next)
		printf("-1\n");
	else
		printf("%d\n", head->next->num);
}

static void	back_dq(dq *tail)
{
	if (!tail->before->before)
		printf("-1\n");
	else
		printf("%d\n", tail->before->num);
}

int main()
{
	int		num, idx;
	char	order[20];
	dq		*head, *tail;
	
	scanf("%d", &num);
	head = (dq *)malloc(sizeof(dq));
	tail = (dq *)malloc(sizeof(dq));
	head->next = tail;
	head->before = NULL;
	tail->next = NULL;
	tail->before = head;

	idx = 0;
	while (idx < num)
	{
		scanf("%s", order);

		if (strcmp(order, "push_front") == 0)
			push_front(head);
		else if (strcmp(order, "push_back") == 0)
			push_back(tail);
		else if (strcmp(order, "pop_front") == 0)
			pop_front(head);
		else if (strcmp(order, "pop_back") == 0)
			pop_back(tail);
		else if (strcmp(order, "size") == 0)
			size_dq(head);
		else if (strcmp(order, "empty") == 0)
			empty_dq(head);
		else if (strcmp(order, "front") == 0)
			front_dq(head);
		else if (strcmp(order, "back") == 0)
			back_dq(tail);
		
		idx++;
	}

	return (0);
}







