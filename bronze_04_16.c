#include <stdio.h>

int main()
{
	char	num[6];
	int		idx;
	int		result;

	scanf("%s", num);
	idx = 0;
	result = 0;
	while(num[idx])
	{	
		if (num[idx] >= 'A' && num[idx] <= 'F')
			result = result * 16 + (num[idx] - 'A' + 10); 
		else
			result = result * 16 + (num[idx] - '0');
		idx++;
	}
	printf("%d", result);

	return (0);
}
