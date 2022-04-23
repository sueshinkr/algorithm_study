#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int	num;
	char	name[21];
} pokemon;

int	compare(const void *one, const void *two)
{
	pokemon *a = (pokemon *)one;
	pokemon *b = (pokemon *)two;

	if (strcmp(a->name, b->name) > 0)
		return (1);
	else if (strcmp(a->name, b->name) < 0)
		return (-1);
	return (0);
}

int	main()
{
	int	num, q_num, idx, find_num, left, right, mid, cmp;
	char	temp[21];
	pokemon *poke;
	pokemon	*poke_sort;

	scanf("%d %d", &num, &q_num);

	poke = (pokemon *)malloc(num * sizeof(pokemon));
	poke_sort = (pokemon *)malloc(num * sizeof(pokemon));

	idx = -1;
	while (++idx < num)
	{
		scanf("%s", poke[idx].name);
		strcpy(poke_sort[idx].name, poke[idx].name); 
		poke[idx].num = idx + 1;
		poke_sort[idx].num = idx + 1;
	}

	qsort(poke_sort, num, sizeof(pokemon), compare);

	idx = -1;
	while (++idx < q_num)
	{
		scanf("%s", temp);
		if (temp[0] > '0' && temp[0] <= '9')
		{	
			find_num = atoi(temp);
			printf("%s\n", poke[find_num - 1].name);
		}
		else
		{
			left = 0, right = num - 1;
			while (left <= right)
			{
				mid = (left + right) / 2;
				cmp = strcmp(poke_sort[mid].name, temp);
				if (cmp == 0)
				{
					printf("%d\n", poke_sort[mid].num);
					break;
				}
				else if (cmp > 0)
					right = mid - 1;
				else
					left = mid + 1;
			}
		}
	}
	free(poke);
	free(poke_sort);
	return (0);
}	
