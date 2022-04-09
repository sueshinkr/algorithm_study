#include <stdio.h>

int main()
{
	int	a, b;

	while (scanf("%d %d", &a, &b) != -1)
		printf("%d\n", a + b);

	return (0);
}

//scanf는 eof를 만나면 -1을 반환.
