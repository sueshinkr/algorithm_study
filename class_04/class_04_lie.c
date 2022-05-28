#include <stdio.h>
#include <stdbool.h>

int main()
{
	int		n, party, truth_num, temp, party_idx, each_party, people_idx, check = 0, count = 0;
	int		party_arr[50][50] = {0, };
	bool	check_arr[51] = {0, };

	scanf("%d %d", &n, &party);
	scanf("%d", &truth_num);

	while (truth_num--  > 0)
	{
		scanf("%d", &temp);
		check_arr[temp] = true;
	}

	party_idx = -1;
	while (++party_idx < party)
	{
		scanf("%d", &each_party);
		
		people_idx = -1;
		while (++people_idx < each_party)
		{
			scanf("%d", &party_arr[party_idx][people_idx]);
			if (check_arr[party_arr[party_idx][people_idx]] == true)
				check = 1;
		}

		if (check == 1)
		{
			people_idx = -1;
			while (++people_idx < each_party)
				check_arr[party_arr[party_idx][people_idx]] = true;
			check = 0;
		}
	}

	party_idx = -1;
	while (++party_idx < party)
	{
		people_idx = -1;
		while (party_arr[party_idx][++people_idx] != 0)
		{
			if (check_arr[party_arr[party_idx][people_idx]] == true)
				check = 1;
		}
		if (check != 1)
			count++;
		else
			check = 0;
	}

	printf("%d\n", count);
	return (0);
}