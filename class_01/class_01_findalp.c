#include <stdio.h>
#include <string.h>

int main()
{
	char	str[100];
	int	alpset[26] = {0, }, idx;

	scanf("%s", str);
	
	idx = strlen(str);
	while(idx-- > 0)
		alpset[str[idx] - 'a'] = idx + 1;
	
	while(++idx < 26)
	{
		printf("%d", alpset[idx] - 1);
		if (idx == 25)
			break;
		printf(" ");
	}	

	return (0);
}
