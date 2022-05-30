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


/*
#include <stdio.h>

#define SIZE (50)
#define DIVIDE (1000000000000000)

int num[SIZE];
int den[SIZE];

int getgcd(int n1, int n2)
{
    if (n2 == 0) return n1;
    else return getgcd(n2, n1 % n2);
}

void combi(int n, int m)
{
    int i, j, k;

    m = (m < n-m)? m: n-m;

    for(i = 0; i < m; i++){
        num[i] = n-i;
        den[i] = i+1;
    }

    int gcd;
    for (i = 0; i < m; i++){
        for(j = 0; j < m; j++){

            if (num[i] > 1 && den[j] > 1){
                gcd = getgcd(num[i], den[j]);

                if (gcd > 1){
                    num[i] /= gcd;
                    den[j] /= gcd;
                }
            }
        }
    }

    long long nCm[2] = {1, 0};
    for(i = 0; i < m; i++){
        nCm[0] *= num[i];
        nCm[1] *= num[i];
        if (nCm[0] >= DIVIDE){
            nCm[1] += nCm[0] / DIVIDE;
            nCm[0] %= DIVIDE;
        }
    }

    if (nCm[1] != 0) printf("%lld", nCm[1]);    
    printf("%lld\n", nCm[0]);
}

int main(void)
{
    int i, j;
    int N, M;
    scanf("%d %d", &N, &M);

    combi(N, M);

    return 0;
}
*/