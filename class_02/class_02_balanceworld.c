#include <stdio.h>
#include <string.h>

int main()
{
	char	str[102];
	int		idx, check[102] = {0, }, check_idx;

	while(1)
	{
		fgets(str, 102, stdin);
		if (strlen(str) == 2 && str[0] == '.')
			break;

		idx = -1, check_idx = -1;
		
		while (str[++idx])
		{
			if (str[idx] == '(')
				check[++check_idx] = 1;
			else if (str[idx] == '[')
				check[++check_idx] = 2;
			else if (str[idx] == ')' && check[check_idx] == 1)
				check[check_idx--] = 0;
			else if (str[idx] == ']' && check[check_idx] == 2)
				check[check_idx--] = 0;
			else if (str[idx] == ')' || str[idx] == ']')
			{
				check_idx = 0;
				break;
			}
		}
		if (check_idx != -1)
			printf("no\n");
		else
			printf("yes\n");
	}

	return (0);
}
