#include <stdio.h>

int	monster[20];
int	citizen[20];
int check_town[20] = {0, };
int	n, max_hp, max = 0;

static void cal(int monster_sum, int town_num, int hp, int save)
{
	int	temp;

	monster_sum += monster[town_num];

	if (monster_sum > hp)
	{
		if (save > max)
			max = save;
		return ;
	}
	else
	{
		hp -= monster_sum;
		save += citizen[town_num];
		temp = -1;
		while (++temp < n)
		{
			if (check_town[temp] == 0 && temp != town_num)
			{
				check_town[town_num] = 1;
				cal(monster_sum, temp, hp, save);
				check_town[town_num] = 0;	
			}
		}
	}
	if (town_num == n - 1)
	{
		if (save > max)
			max = save;
	}
	return ;
}

int main()
{
	int	idx;

	scanf("%d %d", &n, &max_hp);

	idx = -1;
	while (++idx < n)
		scanf("%d", &monster[idx]);
	
	idx = -1;
	while (++idx < n)
		scanf("%d", &citizen[idx]);

	idx = -1;
	while (++idx < n)
	{
		check_town[idx] = 1;
		cal(0, idx, max_hp, 0);
		check_town[idx] = 0;
	}

	printf("%d\n", max);
	return (0);
}