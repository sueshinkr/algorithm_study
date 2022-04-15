#include <stdio.h>

int main()
{
	char	str[51];
	int		num, test_idx, idx, check, check_small;

	scanf("%d", &num);

	test_idx = -1;
	while(++test_idx < num)
	{
		scanf("%s", str);

		check = 1;
		check_small = 0;
		idx = -1;
		while (str[++idx])
		{
			if (str[idx] == '(')
				check_small++;
			else if (str[idx] == ')' && check_small > 0)
				check_small--;
			else
			{
				check = 0;
				break;
			}
		}
		if (check == 0 || check_small != 0)
			printf("NO\n");
		else if (check_small == 0)
			printf("YES\n");
	}

	return (0);
}
