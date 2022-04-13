#include <stdio.h>

int main()
{
	int	num, temp = 1, plus_temp = 6, count = 1;
	
	scanf("%d", &num);

	while(temp < num)
	{
		temp += plus_temp;
		plus_temp += 6;
		count++;
	}
	
	printf("%d", count);
	return (0);
}
