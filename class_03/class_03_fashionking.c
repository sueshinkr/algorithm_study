#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct clothes
{
	int	num;
	char	type[21];
} clo;

int	main()
{
	int	test_num, num, idx, ans;
	char	name[21], new_type[21];
	clo	*c;

	scanf("%d", &test_num);
	while (test_num-- > 0)
	{
		scanf("%d", &num);
		c = (clo *)calloc(num + 1, sizeof(clo));

		while (num-- > 0)
		{
			scanf("%s %s", name, new_type);

			idx = 0;
			while (1)
			{
				if (c[idx].num == 0)
				{
					strcpy(c[idx].type, new_type);
					c[idx].num++;
					break;
				}
				if (!strcmp(c[idx].type, new_type))
				{
					c[idx].num++;
					break;
				}
				else
					idx++;
			}
		}

		ans = 1;
		idx = -1;
		while (c[++idx].num)
			ans *= (c[idx].num + 1);

		printf("%d\n", ans - 1);
		free(c);
	}

	return (0);
}