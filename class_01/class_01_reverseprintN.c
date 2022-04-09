#include <stdio.h>

int	main()
{
	int	n;

	scanf("%d", &n);
	while (n > 0)
		printf("%d\n", n--);
	return (0);
}

// 훨씬 더 빠른 알고리즘이 존재? 문자열로 처리가 훨씬 빠른가?
