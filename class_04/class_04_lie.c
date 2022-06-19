#include <stdio.h>

int parent[51];
int	truth[50] = {0, }, party_arr[50][51] = {0, };

static int	find_parent(int a)
{
	if (parent[a] == a)
		return a;
	else
		return (find_parent(parent[a]));
}
static void	match_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (truth[a] == 1 && truth[b] == 1)
		;
	else if (truth[a] == 1)
		parent[b] = a;
	else if (truth[b] == 1)
		parent[a] = b;
	else
	{
		if (a < b)
			parent[b] = a;
		else
			parent[a] = b;
	}
}

int main()
{
	int	n, party, people_num, truth_num, temp, idx, count = 0;
	
	scanf("%d %d", &n, &party);
	scanf("%d", &truth_num);

	idx = 0;
	while (++idx <= n)
		parent[idx] = idx;

	while (truth_num-- > 0)
	{
		scanf("%d", &temp);
		truth[temp] = 1;
	}

	idx = -1;
	while (++idx < party)
	{
		scanf("%d", &people_num);
		temp = -1;
		while (++temp < people_num)
		{
			scanf("%d", &party_arr[idx][temp]);
			if (temp > 0)
				match_parent(party_arr[idx][temp - 1], party_arr[idx][temp]);
		}
	}

	idx = -1;
	while (++idx < party)
	{
		temp = -1;
		while (party_arr[idx][++temp])
		{
			if (truth[find_parent(party_arr[idx][temp])] == 1)
			{
				count--;
				break;
			}
		}
		count++;
	}

	printf("%d\n", count);
	return (0);
}

//union-find
