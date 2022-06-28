#include <stdio.h>
#include <string.h>

char	ans[1000001];
char	str[1000001];
char	bomb[36];
int		ans_idx = 0;

static int	check_bomb(int idx)
{
	int	bomb_idx = 1, temp_idx = -1;

	if (str[idx] == bomb[0])
		idx = check_bomb(idx + 1);

	while (str[idx] && str[idx] == bomb[bomb_idx])
	{
		idx++;
		bomb_idx++;
		if (str[idx] == bomb[0])
			idx = check_bomb(idx + 1);
	}
	if (bomb[bomb_idx] != 0)
	{
		while (++temp_idx < bomb_idx)
			ans[ans_idx++] = bomb[temp_idx];
	}
	return (idx);
}

static void	check()
{
	int	idx = 0, bomb_idx = 0;

	while (str[idx])
	{
		if (str[idx] != bomb[bomb_idx])
			ans[ans_idx++] = str[idx++];
		else
			idx = check_bomb(idx + 1);
	}
}

int	main()
{
	scanf("%s", str);
	scanf("%s", bomb);

	check();

	if(ans[0])
		printf("%s\n", ans);
	else
		printf("FRULA\n");
	return (0);
}

/*
abacabcc

abc
*/