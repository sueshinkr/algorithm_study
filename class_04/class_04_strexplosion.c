#include <stdio.h>
#include <string.h>

char	ans[1000000];
char	str[1000000];
char	bomb[36];

static int	check_bomb(int idx)
{
	int	bomb_idx = 1;

	if (str[idx] == bomb[0])
		idx = check_bomb(idx + 1);
	while (str[idx] && str[idx] == bomb[bomb_idx])
	{
		idx++;
		bomb_idx++;
	}
	if (bomb[bomb_idx] != 0)
		idx -= bomb_idx;
	return (idx);
}

static void	check()
{
	int	idx = 0, bomb_idx = 0, ans_idx = 0;

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