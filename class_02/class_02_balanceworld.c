#include <stdio.h>
#include <string.h>

int main()
{
	char	str[102];
	int		idx, check, check_small, check_middle, flag[102], flag_idx;

	while(1)
	{
		fgets(str, 102, stdin);
		if (strlen(str) == 2 && str[0] == '.')
			break;

		check = 1;
		check_small = 0;
		check_middle = 0;
		flag_idx = -1;
		idx = -1;
		while (str[++idx])
		{
			if (str[idx] == '(')
			{
				check_small++;
				flag[++flag_idx] = 1;
			}
			else if (str[idx] == '[')
			{
				check_middle++;
				flag[++flag_idx] = 2;
			}
			else if (str[idx] == ')' && check_small > 0 && flag[flag_idx--] == 1)
				check_small--;
			else if (str[idx] == ']' && check_middle > 0 && flag[flag_idx--] == 2)
				check_middle--;
			else if (str[idx] == ')' || str[idx] == ']')
			{
				check = 0;
				break;
			}
		}
		if (check == 0)
			printf("no\n");
		else if (check_small == 0 && check_middle == 0)
			printf("yes\n");
		else
			printf("no\n");
	}

	return (0);
}
