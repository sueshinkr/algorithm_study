#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static void	check(int num, int togo, bool **arr, bool *check_line)
{
	int	idx = 0;

	while (++idx <= num)
	{
		if (arr[togo][idx] == true && check_line[idx] == false)
		{
			check_line[idx] = true;
			check(num, idx, arr, check_line);
		}
	}
}


int	main()
{
	int	num, line_num, idx, togo, a, b, count = 0;
	bool	**arr, *check_line;

	scanf("%d %d", &num, &line_num);
	arr = (bool **)malloc((num + 1) * sizeof(bool *));
	check_line = (bool *)calloc((num + 1), sizeof(bool));

	idx = -1;
	while (++idx <= num)
		arr[idx] = (bool *)calloc((num + 1), sizeof(bool));

	while(line_num-- > 0)
	{
		scanf("%d %d", &a, &b);
		arr[a][b] = true;
		arr[b][a] = true;
	}
	
	idx = 0;
	while (++idx <= num)
	{
		togo = 0;
		while (++togo <= num)
		{
			if (arr[idx][togo] == true && check_line[togo] == false)
			{
				check(num, togo, arr, check_line);
				count++;
			}
		}
		if (check_line[idx] == false)
			count++;
	}

	printf("%d\n", count);
	return (0);

}
