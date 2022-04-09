#include <stdio.h>

int main()
{
	int	scale[8];
	int	idx = 0;
	int	count = 0;

	while (idx < 8)
		scanf("%d", &scale[idx++]);
	
	idx = 0;
	while (++idx < 8)
	{
		if (scale[idx] > scale[idx - 1])
			count++;
		else
			count--;
	}

	if (count == 7)
		printf("ascending");
	else if (count == -7)
		printf("descending");
	else
		printf("mixed");
	return (0);
}
