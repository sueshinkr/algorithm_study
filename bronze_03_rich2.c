#include <stdio.h>
#include <string.h>

int	subtract(char *money, char *life, int m_idx)
{
	int	len;
	int	l_idx;
	int temp;

	len = strlen(life);
	l_idx = 0;
	temp = m_idx;
	while (len-- > 0)
	{
		if (money[m_idx] < life[l_idx])
		{
			if (temp != 0)
			{
				if (money[temp - 1] != '0')
					break;
			}
			return (-1);
		}
		else if (money[m_idx] > life[l_idx])
			break;
		m_idx++;
		l_idx++;
	}
	m_idx = temp;
	len = strlen(life);
	while (len-- > 0)
	{
		money[m_idx + len] -= (life[len] - '0');
		if (money[m_idx + len] < '0' && m_idx + len != 0)
		{
			money[m_idx + len] += 10;
			money[m_idx + len - 1]--;
		}
	}
	return (1);
}


int	main()
{
	char	money[1000];
	char	life[1000];
	int		count;
	int		m_idx;
	int		flag;

	count = 0;
	m_idx = 0;
	flag = 0;
	scanf("%s %s", money, life);

	while (m_idx != strlen(money) - strlen(life) + 1)
	{
		if (subtract(money, life, m_idx) == 1)
			count++;
		else
		{	
			if (count == 0 && flag == 0)
				;
			else
			{
				printf("%d", count);
				flag = 1;
			}
			count = 0;
			m_idx++;
		}
	}
	printf("\n");
	m_idx = 0;
	count = 0;
	while(money[m_idx])
	{
		if (money[m_idx] == '0' && flag == 1)
		{
			count++;	
			if (count == strlen(money))
			{
				printf("0");
				break;
			}
		}
		else
		{
			printf("%c", money[m_idx]);
			flag = 0;
		}
		m_idx++;
	}
	return (0);
}
