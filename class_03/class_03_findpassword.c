#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pw
{
	char	addr[21];
	char	key[21];
}	password;

static int compare(const void *a, const void *b)
{
	password one = *(password *)a;
	password two = *(password *)b;
	
	return (strcmp(one.addr, two.addr));
}

static void search(password *pw, char *str, int addr_num)
{
	int min = 0, max = addr_num, mid, cmp;

	while (min <= max)
	{
		mid = (min + max) / 2;
		cmp = strcmp(str, pw[mid].addr);
		if (cmp > 0)
			min = mid + 1;
		else if (cmp < 0)
			max = mid - 1;
		else
			break;
	}
	printf("%s\n", pw[mid].key);
}
int	main()
{
	password	pw[100000];
	int	addr_num, find_num, idx;
	char	str[21];

	scanf("%d %d", &addr_num, &find_num);

	idx = -1;
	while (++idx < addr_num)
		scanf("%s %s", pw[idx].addr, pw[idx].key);

	qsort(pw, addr_num, sizeof(password), compare);

	while (find_num-- > 0)
	{
		scanf("%s", str);
		search(pw, str, addr_num - 1);
	}
	return (0);
}



/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hashmap
{
	char	key[21];
	char	addr[21];
	struct hashmap *next;
}	hash;

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
		temp = (temp * nb) % 100003;
		power--;
	}	
	return (temp);
}

static int	hashing(char *str)
{
	int	idx = -1, result;
	long long	temp;

	while (str[++idx])
	{
		temp = str[idx] * power(31, idx) + result;
		result = temp % 100003;
	}
	return (result);
}

int	main()
{
	int	addr_num, find_num, key, idx;
	hash *hashmap[100007];
	hash temp[100007];
	char addr[20], password[20];

	scanf("%d %d", &addr_num, &find_num);

	while (addr_num-- > 0)
	{
		scanf("%s %s", addr, password);
		key = hashing(addr);
	}

	while (find_num-- > 0)
	{
		scanf("%s", addr);
		key = hashing(addr);
		if (hashmap[key].count == 1)
			printf("%s\n", hashmap[key].map[0]);
		else
		{
			idx = -1;
			while(++idx < hashmap[key].count)
			{
				if (strcmp(addr, hashmap[key].addr[idx]))
				{
					printf("%s\n", hashmap[key].map[idx]);
					break;
				}
			}
		}
	}
	return (0);
}
*/