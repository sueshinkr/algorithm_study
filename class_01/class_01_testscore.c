#include <stdio.h>

int main()
{
	int	score;

	scanf("%d", &score);
	
	if (score >= 90)
		printf("A");
	else if (score >= 80)
		printf("B");
	else if (score >= 70)
		printf("C");
	else if (score >= 60)
		printf("D");
	else
		printf("F");
	
	//printf("%c", "FFFFFFDCBAA"[score/10]);
	// write / printf / putchar ...
	
	return (0);
}

