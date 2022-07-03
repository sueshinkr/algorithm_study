#include <stdio.h>
#include <stdbool.h>

bool	find = false;

static void	four(int first, int s4, int s3, int s2)
{
	int	s1, second;
	
	s1 = -1;
	while (++s1 < 10)
	{
		if (first * s1 % 10 == 6 && (first * s1 / 1000) % 10 == 6)
		{
			second = s4 + s3 * 10 + s2 * 100 + s1 * 1000;
			if (first * second / 1000000000 > 0)
			{
				if (((first * second) / 10000) % 100 == 66)
				{
					printf("%d * %d = %d", first, second, first * second);
					find = true;
				}
			}
		}
	}
}

static void	three(int first, int s4, int s3)
{
	int	s2;

	s2 = -1;
	while (++s2 < 10)
	{
		if ((first * s2 / 100) % 1000 == 666)
		{
			four(first, s4, s3, s2);
			if (find == true)
				return ;
		}
	}
}

static void	two(int first, int s4)
{
	int	s3;

	s3 = -1;
	while (++s3 < 10)
	{
		if (first * s3 / 100000 == 6)
		{
			three(first, s4, s3);
			if (find == true)
				return ;
		}
	}
}

static void	one()
{
	int	f1, f2, f3, f4, f5, f6, s4;
	int	first;

	f1 = 0;
	while (++f1 < 10)
	{
		f2 = -1;
		while (++f2 < 10)
		{
			f3 = -1;
			while (++f3 < 10)
			{
				f4 = -1;
				while (++f4 < 10)
				{
					f5 = -1;
					while (++f5 < 10)
					{
						f6 = -1;
						while (++f6 < 10)
						{
							s4 = -1;
							while (++s4 < 10)
							{
								first = (f1 * 100000 + f2 * 10000 + f3 * 1000 + f4 * 100 + f5 * 10 + f6) * s4;
								if (first / 10000 == 66) 
								{
									two(first, s4);
									if (find == true)
										return ;
								}
							}
						}
					} 
				}
			}
		}
	}
}




int main()
{
	one();
	return (0);
}
