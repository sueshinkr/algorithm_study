#include <stdio.h>
#define MIN(x, y) ((x < y) ? (x) : (y))

int value(int n, int k)
{
	if(k <= n)
		return n-k;
	else if(k == 1) 
		return 1;
	else if(k % 2 == 1)
		return (1 + MIN(value(n, k - 1), value(n, k + 1)));
	else
		return MIN(k - n, value(n, k / 2));
}

int main(void)
{
	int n, k;
	
	scanf("%d %d", &n, &k);
	
	printf("%d\n", value(n, k));
	return 0;
}