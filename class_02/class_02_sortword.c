#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

static void quick_sort(char **word, int left, int right)
{
	int		low = left + 1, high = right, pivot = left;

	if (left < right)
	{
		while (low <= high)
		{
			while (strlen(word[low]) <= strlen(word[pivot]) && low < right)
			{
				if (strlen(word[low]) == strlen(word[pivot]) 
					&& strcmp(word[low], word[pivot]) > 0)
					break;
				low++;
			}

			while (strlen(word[high]) >= strlen(word[pivot]) && high > left)
			{
				if (strlen(word[high]) == strlen(word[pivot]) 
					&& strcmp(word[high], word[pivot]) < 0)
						break;
				high--;
			}

			if (low >= high)
				break;

			swap(&word[low], &word[high]);
			low++;
			high--;
		}

		swap(&word[left], &word[high]);
		quick_sort(word, left, high - 1);
		quick_sort(word, low, right);
	}
}

int main()
{
	int		num, idx = 0;
	char	**word;
	char	temp[50];

	scanf("%d", &num);
	word = (char **)malloc((num + 1) * sizeof(char *));
	
	while (idx < num)
	{	
		scanf("%s", temp);
		word[idx] = (char *)malloc((strlen(temp) + 1) * sizeof(char));
		strcpy(word[idx++], temp); 
	}
	word[idx] = NULL;

	quick_sort(word, 0, num - 1);

	idx = 0;
	while (word[idx])
	{
		if (idx == 0)
			printf("%s\n", word[idx]);
		else
		{
			if (strcmp(word[idx], word[idx - 1]))
				printf("%s\n", word[idx]);
		}
		idx++;
	}

	return (0);
}
