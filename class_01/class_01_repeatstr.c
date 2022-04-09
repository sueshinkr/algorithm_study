#include <stdio.h>

int	main()
{
	int		total;
	int		repeat;
	char	str[20];
	int		idx1;
	int		idx2;
	
	scanf("%d", &total);
	while (total-- > 0)
	{
		scanf("%d", &repeat);
		scanf("%s", str);
		idx1 = 0;
		while (str[idx1])
		{
			idx2 = 0;
			while (idx2++ < repeat)
				printf("%c", str[idx1]);
			idx1++;
		}
		printf("\n");
	}
}

//테스트케이스 하나를 받을때마다 바로 출력...
