#include <stdio.h>

int main()
{
	int	hour, minute;

	scanf("%d %d", &hour, &minute);
	minute -= 45;
	if (minute < 0)
	{
		minute += 60;
		hour--;
	}
	if (hour < 0)
		hour +=24;
	printf("%d %d", hour, minute);
	return (0);
}
