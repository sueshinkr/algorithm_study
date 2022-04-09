#include <stdio.h>

#define ABS(x) ((x) > 0 ? (x) : (-x))
static int find_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int main()
{
	int	x, y, w, h;
	int	min_x = 0, min_y = 0;

	scanf("%d %d %d %d", &x, &y, &w, &h);
	
	min_x = find_min(x, ABS(w - x));
	min_y = find_min(y, ABS(h - y));

	printf("%d", find_min(min_x, min_y));
	return (0);
}
