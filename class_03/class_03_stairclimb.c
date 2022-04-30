#include <stdio.h>
#include <stdlib.h>

typedef struct score
{
	int	jump;
	int	non_jump;
} sc;

static int max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int main()
{
	int	num, *stair, idx;
	sc	*score;

	scanf("%d", &num);
	stair = (int *)malloc(num * sizeof(int));
	score = (sc *)malloc(num * sizeof(sc));

	idx = -1;
	while (++idx < num)
		scanf("%d", &stair[idx]);

	score[0].jump = stair[0];
	score[0].non_jump = stair[0];
	score[1].jump = stair[1];
	score[1].non_jump = stair[0] + stair[1];

	idx = 1;
	while (++idx < num)
	{
		score[idx].jump = max(score[idx - 2].jump, score[idx - 2].non_jump) + stair[idx];
		score[idx].non_jump = score[idx - 1].jump + stair[idx];
	}

	printf("%d", max(score[num - 1].jump, score[num - 1].non_jump));
	free(stair);
	free(score);
	return (0);
}