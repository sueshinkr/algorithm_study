#include <stdio.h>
#include <stdlib.h>

static long long	power(int nb, int power)
{
	long long	temp;

	temp = nb;
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	while (power > 1)
	{
		temp = (temp * nb) % 1234567891;
		power--;
	}	
	return (temp);
}

int main()
{
	int		len, idx, temp, hash_result = 0;
	long long hash_temp = 0;
	char	*str;

	scanf("%d", &len);
	str = (char *)malloc((len + 1) * sizeof(char));
	scanf("%s", str);

	idx = -1;
	while (++idx < len)
	{
		temp = str[idx] - 'a' + 1;
		hash_temp = temp * power(31, idx) + hash_result;
		hash_result = hash_temp % 1234567891;
	}

	printf("%lld", hash_temp % 1234567891);
	free(str);
	return (0);
}
