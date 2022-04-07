#include <stdio.h>
#include <string.h>

int main()
{
	char	str[100];
	char	alpset[26];
	int		idx;

	scanf("%s", str);
	memset(alpset, -1, sizeof(alpset));
	
	idx = strlen(str);
	while(idx-- > 0)
		alpset[str[idx] - 'a'] = idx;
	
	while(++idx < 26)
	{
		printf("%d", alpset[idx]);
		if (idx == 25)
			break;
		printf(" ");
	}	

	return (0);
}
