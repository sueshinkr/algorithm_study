#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int compare(const void *a, const void *b)
{
	return (strcmp(*(char **)a, *(char **)b));
}

static int compare2(const void *a, const void *b)
{
	return (strcmp((char *)a, *(char **)b));
}

int main()
{
	int	nseen, nheard, idx, nsh_idx = 0;
	char	**nseen_name, nheard_name[21], **nsh_name;

	scanf("%d %d", &nseen, &nheard);
	nseen_name = (char **)malloc(nseen * sizeof(char *));
	nsh_name = (char **)malloc(nseen * sizeof(char *));

	idx = -1;
	while (++idx < nseen)
	{
		nseen_name[idx] = (char *)malloc(21 * sizeof(char));
		scanf("%s", nseen_name[idx]);
	}
	qsort(nseen_name, nseen, sizeof(nseen_name[0]), compare);

	idx = -1;
	while (++idx < nheard)
	{
		scanf("%s", nheard_name);
		if (bsearch(nheard_name, nseen_name, nseen, sizeof(nseen_name[0]), compare2))
		{
			nsh_name[nsh_idx] = (char *)malloc(21 * sizeof(char));
			strcpy(nsh_name[nsh_idx++], nheard_name);
		}
	}
	qsort(nsh_name, nsh_idx, sizeof(nsh_name[0]), compare);

	printf("%d\n", nsh_idx);
	idx = -1;
	while (++idx < nsh_idx)
	{	
		printf("%s\n", nsh_name[idx]);
		free(nsh_name[idx]);
	}

	idx = -1;
	while (++idx < nseen)
		free(nseen_name[idx]);
	free(nseen_name);
	free(nsh_name);

	return (0);
}
