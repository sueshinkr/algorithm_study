#include <stdio.h>
#include <string.h>

void	plus(char *a, char *b)
{
	char	result[1003];
	int		a_len;
	int		b_len;
	int		result_len;
	int		sign;

	sign = 1;
	if (a[0] == '-' && b[0] == '-')
	{
		a[0] = '0';
		b[0] = '0';
		sign = -1;
	}
	a_len = strlen(a) - 1;
	b_len = strlen(b) - 1;
	if (a_len >= b_len)
		result_len = a_len + 2;
	else
		result_len = b_len + 2;

	memset(result, '0', sizeof(result));
	result[result_len] = 0;
	while (result_len-- > 0)
	{
		if (a_len >= 0 && b_len >= 0)
		{
			result[result_len] += (a[a_len--] + b[b_len--] - '0' * 2);
			if (result[result_len] > '9')
			{	
				result[result_len - 1] += 1;
				result[result_len] -= 10;
			}
		}
		else if (a_len < 0 && b_len < 0)
			break;
		else if (a_len < 0 && b_len >= 0)
			result[result_len] += (b[b_len--] - '0');
		else if (b_len < 0 && a_len >= 0)
			result[result_len] += (a[a_len--] - '0');
		
		if (result[result_len] > '9')
		{	
			result[result_len - 1] += 1;
			result[result_len] -= 10;
		}
	}
	if (result[result_len] == '0')
	{
		result_len++;
		if (sign == -1)
		{
			if (result[result_len] == '0')
				result_len++;
			printf("-");
		}
	}
	while (result[result_len])
		printf("%c", result[result_len++]);
}

int main()
{
	char	a[1003];
	char	b[1003];

	scanf("%s %s", a, b);
	plus(a, b);

	return (0);
}
