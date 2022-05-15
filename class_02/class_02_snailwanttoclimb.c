#include <stdio.h>

int main()
{
	int	up, down, height, count = 0;

	scanf("%d %d %d", &up, &down, &height);

	if ((height - up) % (up - down) != 0)
		count++;
	printf("%d\n", count + (height - up) / (up - down) + 1);
	
	return (0);
}

/*
// 시간 초과
int	main()
{
	int	up, down, height, total = 0, count = 1;

	scanf("%d %d %d", &up, &down, &height);

	while (height - total > up)
	{
		total += (up - down);
		count++;
	}

	printf("%d", count);
	return (0);
}
*/