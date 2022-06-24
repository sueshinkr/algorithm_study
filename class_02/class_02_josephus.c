#include <stdio.h>
#include <stdlib.h>

typedef struct person
{
	int	num;
	struct person	*next;
} per;

static void	add_list(per *head, int idx)
{
	per	*new, *temp;

	new = (per *)malloc(sizeof(per));
	new->num = idx + 1;

	if (!head->next)
	{
		head->next = new;
		new->next = head;
	}
	else
	{
		temp = head->next;
		while (temp->num != idx)
			temp = temp->next;
		temp->next = new;
		new->next = head->next;
	}
}

static void	del_list(per *prev)
{
	per	*temp;

	temp = prev->next;
	prev->next = temp->next;

	free(temp);
}

int main()
{
	per *head, *temp;
	int	num, k, idx, lst_idx, *josephus;

	scanf("%d %d", &num, &k);
	josephus = (int *)malloc(num * sizeof(int));
	head = (per *)malloc(sizeof(per));

	idx = 0;
	while (idx < num)
		add_list(head, idx++);
	
	idx = -1;
	temp = head;
	while (++idx < num)
	{
		lst_idx = 0;
		while (++lst_idx < k)
			temp = temp->next;
		josephus[idx] = temp->next->num;
		del_list(temp);
	}

	free(head);

	idx = -1;
	while (++idx < num)
	{
		if (idx == 0)
			printf("<");
		if (idx != num - 1)
			printf("%d, ", josephus[idx]);
		else
			printf("%d>", josephus[idx]);
	}

	free(josephus);
	return (0);
}
