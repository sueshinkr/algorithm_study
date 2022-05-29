#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct str
{
	char	*str;
} arr;

arr string[101][101];

static char	*string_sum(char *a, char *b)
{
	int	a_len = strlen(a), b_len = strlen(b), temp_idx = 40, temp_sum;
	char *temp;

	temp = (char *)malloc(41 * sizeof(char));
	memset(temp, '0', 40);
	temp[40] = 0;

	while (a_len > 0 && b_len > 0)
	{
		temp_sum = temp[--temp_idx] - '0' + a[--a_len] - '0' + b[--b_len] - '0';
		if (temp_sum > 9)
		{
			temp[temp_idx--] = temp_sum - 10 + '0';
			temp[temp_idx++] = '1';
		}
		else
			temp[temp_idx] = temp_sum + '0';
	}
	while (a_len > 0 || b_len > 0)
	{
		if (a_len > 0)
			temp_sum = temp[--temp_idx] - '0' + a[--a_len] - '0';
		else
			temp_sum = temp[--temp_idx] - '0' + b[--b_len] - '0';
		if (temp_sum > 9)
		{
			temp[temp_idx--] = temp_sum - 10 + '0';
			temp[temp_idx++] = '1';
		}
		else
			temp[temp_idx] = temp_sum + '0';
	}
	return (temp);
}

static char	*cal(int n, int m)
{
	char *temp;

	if (string[n][m].str)
		return (string[n][m].str);
	if (m == 0 || n == m)
		string[n][m].str = strdup("1");
	else if (n >= 2)
	{
		temp = string_sum(cal(n - 1, m - 1), cal(n - 1, m));
		string[n][m].str = temp;
	}
	return (string[n][m].str);
}

int	main()
{
	int		n, m;
	char	*temp;

	scanf("%d %d", &n, &m);
	temp = cal(n, m);

	while (*temp == '0')
		temp++;
	printf("%s\n", temp);
	return (0);
}
