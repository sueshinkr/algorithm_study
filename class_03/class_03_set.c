#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
static void	set_add(bool *set)
{
	int	num;

	scanf("%d", &num); 

	if (set[num] == false)
		set[num] = true;
}

static void	set_remove(bool *set)
{
	int	num;

	scanf("%d", &num);

	if (set[num] == true)
		set[num] = false;
}

static void	set_check(bool *set)
{
	int	num;
	scanf("%d", &num);

	if (set[num] == true)
		printf("1\n");
	else
		printf("0\n");
}

static void	set_toggle(bool *set)
{
	int	num;
	scanf("%d", &num);

	if (set[num] == true)
		set[num] = false;
	else
		set[num] = true;
}

static void	set_all(bool *set)
{
	int	idx = 0;

	while (++idx <= 20)
		set[idx] = true;
}

static void	set_empty(bool *set)
{
	int	idx = 0;

	while (++idx <= 20)
		set[idx] = false;
}

int	main()
{
	int		op_num;
	bool	set[21] = {0, };
	char	op[10];

	scanf("%d", &op_num);

	while (op_num-- > 0)
	{
		scanf("%s", op);

		if (!strcmp(op, "add"))
			set_add(set);
		else if (!strcmp(op, "remove"))
			set_remove(set);
		else if (!strcmp(op, "check"))
			set_check(set);
		else if (!strcmp(op, "toggle"))
			set_toggle(set);
		else if (!strcmp(op, "all"))
			set_all(set);
		else if (!strcmp(op, "empty"))
			set_empty(set);
	}
	
	return (0);
}
*/

static void	set_add(int *set)
{
	int	num;

	scanf("%d", &num); 

	*set = *set | (1 << (num - 1));
}

static void	set_remove(int *set)
{
	int	num;

	scanf("%d", &num);

	*set = *set & ~(1 << (num - 1));
}

static void	set_check(int *set)
{
	int	num;
	scanf("%d", &num);

	if (*set & (1 << (num - 1)))
		printf("1\n");
	else
		printf("0\n");
}

static void	set_toggle(int *set)
{
	int	num;
	scanf("%d", &num);

	*set = *set ^ (1 << (num - 1));
}

static void	set_all(int *set)
{
	//int	idx = 0;

	*set = *set | 0b11111111111111111111;
	//while (++idx <= 20)
	//	set = set | (1 << idx);
}

static void	set_empty(int *set)
{
	//int	idx = 0;

	*set = *set & 0b00000000000000000000;
}

int	main()
{
	int		op_num, set = 0;
	char	op[10];

	scanf("%d", &op_num);

	while (op_num-- > 0)
	{
		scanf("%s", op);

		if (!strcmp(op, "add"))
			set_add(&set);
		else if (!strcmp(op, "remove"))
			set_remove(&set);
		else if (!strcmp(op, "check"))
			set_check(&set);
		else if (!strcmp(op, "toggle"))
			set_toggle(&set);
		else if (!strcmp(op, "all"))
			set_all(&set);
		else if (!strcmp(op, "empty"))
			set_empty(&set);
	}

	return (0);
}