#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct	human_info
{
	int		age;
	int		order;
	char	name[101];
};

/*
static void	int_swap(int *num1, int *num2)
{
	int	temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

static void	char_swap(char **str1, char **str2)
{
	char	temp[100];
	strcpy(temp, *str1);
	strcpy(*str1, *str2);
	strcpy(*str2, temp);
}
*/

static void swap_struct(struct human_info *one, struct human_info *two)
{
	int		temp, order_temp;
	char	str[101];

	temp = one->age;
	one->age = two->age;
	two->age = temp;

	strcpy(str, one->name);
	strcpy(one->name, two->name);
	strcpy(two->name, str);

	order_temp = one->order;
	one->order = two->order;
	two->order = order_temp;
}

static void	quick_sort(struct human_info *human, int left, int right)
{
	int	low = left + 1, high = right, pivot = left;
	
	if (left < right)
	{
		while (low <= high)
		{	
			while (human[low].age <= human[pivot].age && low < right)
			{
				if (human[low].age == human[pivot].age 
					&& human[low].order > human[pivot].order)
					break;
				else
					low++;
			}
			while (human[high].age >= human[pivot].age && high > left)
			{
				if (human[high].age == human[pivot].age 
					&& human[high].order < human[pivot].order)
					break;
				else
					high--;
			}
			if (low >= high)
				break;

			swap_struct(&human[low], &human[high]);
			low++;
			high--;
		}
		swap_struct(&human[left], &human[high]);
		quick_sort(human, left, high - 1);
		quick_sort(human, low, right);
	}
}


int main()
{
	int		num, idx;
	struct human_info	*human;

	
	scanf("%d", &num);
	human = (struct human_info *)malloc(num * sizeof(struct human_info));

	idx = -1;
	while (++idx < num)
	{
		scanf("%d %s", &human[idx].age, human[idx].name);
		human[idx].order = idx;
	}

	quick_sort(human, 0, num - 1);

	idx = -1;
	while (++idx < num)
		printf("%d %s\n", human[idx].age, human[idx].name);
	
	free(human);
	return (0);
}

//안정정렬 불안정정렬
