#include <stdio.h>

int	num, arr[1000], count[1000];

static int	dp(int cur)
{
	int	idx = cur , check, temp;

	if (cur == num - 1)
		return (1);
	if (count[cur] != 1)
		return (count[cur]);

	check = arr[cur];
	while (++idx < num)
	{	
		if(arr[idx] > check)
		{
			temp = dp(idx) + 1;
			if (count[cur] < temp)
				count[cur] = temp;
		}
	}
	return (count[cur]);
}

int	main()
{
	int	idx, max = 0, temp;

	scanf("%d", &num);

	idx = -1;
	while (++idx < num)
	{
		scanf("%d", &arr[idx]);
		count[idx] = 1;
	}

	idx = -1;
	while (++idx < num)
	{
		if (count[idx] == 1)
		{
			temp = dp(idx);
			if (max < temp)
				max = temp;
		}
	}

	printf("%d\n", max);
	return (0);
}

/*
#include <string.h>
#include <stdio.h>

int main(void)
{
	int n, s[1001], biggest, c[1001];

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &s[i]);
		c[i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = (i - 1); j >= 1; j--) {
			if ((s[j] < s[i]) && (c[j] >= c[i])) {
				c[i] = c[j] + 1;
			}
		}
	}
	
	biggest = c[1];

	for (int i = 1; i <= n; i++)
		if (c[i] > biggest)
			biggest = c[i];

	printf("%d\n", biggest);

	return 0;
}
*/

/*
#include <stdio.h>
#define MAX(n1, n2) n1 > n2 ? n1 : n2;

int main()
{
    int N;
    int result = 0;
    int arr[1001];
    int dp[1001] = {0, };
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
    for (int cur = 1; cur <= N; cur++)
    {
        dp[cur] = 1;
        for (int i = cur - 1; i >= 1; i--)
        {
            if (arr[cur] > arr[i])
                dp[cur] = MAX(dp[cur], dp[i] + 1);
        }
        result = MAX(dp[cur], result);
    }
    printf("%d\n", result);
}
*/
