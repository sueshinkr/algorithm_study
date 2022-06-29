#include <stdio.h>
#include <stdlib.h>

static int check_bomb(int idx);

struct ans_list
{
	char	*str;
	struct ans_list *next;
};

char	str[1000001];
char	bomb[36];
int		str_len = 1000000;

struct ans_list *head;

static int	check_no_bomb(int idx)
{
	int ans_idx = 0;
	struct ans_list *ans;
	ans = (struct ans_list *)malloc(sizeof(struct ans_list));
	ans->str = (char *)malloc(str_len * sizeof(char));

	while (str[idx] && str[idx] != bomb[0])
		ans->str[ans_idx++] = str[idx++];

	if (str[idx])
	{
		idx = check_bomb(idx);
		if (str[idx])
			idx = check_no_bomb(idx);
	}
	if (ans_idx != 0)
	{
		ans->next = head;
		head = ans;
		str_len -= (ans_idx - 1);
	}
	return (idx);
}

static int	check_bomb(int idx)
{
	int	bomb_idx = 0, ans_idx = 0;
	struct ans_list *ans;
	ans = (struct ans_list *)malloc(sizeof(struct ans_list));
	ans->str = (char *)malloc(str_len * sizeof(char));

	ans->str[ans_idx] = bomb[bomb_idx];
	while (str[idx])
	{
		if (str[++idx] == bomb[0])
			idx = check_bomb(idx);
		if (str[idx] == bomb[++bomb_idx])
			ans->str[++ans_idx] = str[idx];
		else
			break;
	}
	if (bomb[bomb_idx])
	{
		idx = check_no_bomb(idx);
		ans->next = head;
		head = ans;
		str_len -= (ans_idx - 1);
		return(idx);
	}
	return (idx);
}

int	main()
{
	struct ans_list *temp;

	scanf("%s", str);
	scanf("%s", bomb);

	check_no_bomb(0);

	if (!head)
		printf("FRULA\n");
	else
	{
		while (head)
		{
			printf("%s", head->str);
			free(head->str);
			temp = head;
			head = head->next;
			free(temp);
		}
		printf("\n");
	}
	return (0);
}
