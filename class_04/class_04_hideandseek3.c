#include <stdio.h>
#define MIN(x, y) ((x < y) ? (x) : (y))

int value(int N, int K)
{
	if(K <= N)
		return N-K;
	else if(K == 1) 
		return 1;
	else if(K % 2 == 1)
		return (1 + MIN(value(N, K - 1), value(N, K + 1)));
	else
		return MIN(K - N, value(N, K / 2));
}

int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d\n", value(N, K));
	return 0;
}