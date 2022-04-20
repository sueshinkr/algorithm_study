#include <stdio.h>

static int check_ch(int ch_temp, int *broke_num)
{
	int	count = 0;

	if (ch_temp < 0)
		return (500000);
	while (ch_temp > 0 || (ch_temp == 0 && count == 0))
	{
		if (broke_num[ch_temp % 10])
			return (500000);
		ch_temp /= 10;
		count++;
	}
		
	return (count);	
}

int main()
{
	int	ch, num, idx, temp, ch_temp, temp_big, temp_small;
	int	broke_num[10] = {0, }, ans_100 = 0, ans = 0;

	scanf("%d %d", &ch, &num);

	idx = -1;
	while (++idx < num)
	{
		scanf("%d", &temp);
		broke_num[temp]++;
	}
	
	if (ch >= 100)
		ans_100 += ch - 100;
	else
		ans_100 += 100 - ch;

	ch_temp = 0;
	while (1)
	{	
		temp_big = check_ch(ch + ch_temp, broke_num);
		temp_small = check_ch(ch - ch_temp, broke_num);
		if (temp_big < 500000 || temp_small < 500000)
		{
			if (temp_big > temp_small)
				ans += temp_small;
			else
				ans += temp_big;
			break;
		}

		ans++;
		if (ans > ans_100)
			break;
		ch_temp++;
	}

	if (ans_100 <= ans)
		printf("%d", ans_100);
	else
		printf("%d", ans);

	return (0);
}
