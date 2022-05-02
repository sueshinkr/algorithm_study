#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main()
{
	int	test_num, m, n, x, y;
	int	temp_y, idx, count, max;
	
	scanf("%d", &test_num);

	idx = -1;
	while (++idx < test_num)
	{
		scanf("%d %d %d %d", &m, &n, &x, &y);
		if (x == y)
		{
			printf("%d\n", x);
			continue;
		}

		count = x;
		x = x % n;
		y = y % n;
		temp_y = x % n;
		max = lcm(m, n);
		while (1)
		{
			if (temp_y == y)
			{
				printf("%d\n", count);
				break;
			}
			count += m;
			temp_y = (temp_y + m) % n;
			if (count > max)
			{
				printf("-1\n");
				break;
			}
		}
	}
	return (0);
}
