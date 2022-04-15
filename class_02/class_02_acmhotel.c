#include <stdio.h>

int main()
{
	int	num, idx, floor, width, check, room;

	scanf("%d", &num);
	
	idx = -1;
	while (++idx < num)
	{
		scanf("%d %d %d", &floor, &width, &check);

		room = 0;
		if (check % floor == 0)
			room += check / floor + floor * 100;
		else
			room += check / floor + 1 + (check % floor) * 100;

		printf("%d\n", room);
	}

	return (0);
}
