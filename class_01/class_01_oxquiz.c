#include <stdio.h>

int main()
{
	int		num;
	char	ox[80];
	int		idx;
	int		score;
	int		count;

	scanf("%d", &num);
	
	while (num-- > 0)
	{
		scanf("%s", ox);
		idx = 0;
		score = 0;
		count = 1;
		while (ox[idx])
		{
			if (ox[idx++] == 'O')
				score += count++;
			else
				count = 1;
		}
		printf("%d\n", score);
	}
	
	return (0);
}
