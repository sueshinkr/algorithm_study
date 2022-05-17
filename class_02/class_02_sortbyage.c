#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	human
{
	int		age;
	int		order;
	char	name[101];
} human_info;

/*
static void swap_struct(human_info *one, human_info *two)
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

static void	quick_sort(human_info *human, int left, int right)
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
*/

static int compare(const void *a, const void *b)
{
	human_info *one = (human_info *)a;
	human_info *two = (human_info *)b;

	if (one->age > two->age)
		return (1);
	else if (one->age < two->age)
		return (-1);
	else
	{
		if (one->order > two->order)
			return (1);
		else if (one->order < two->order)
			return (-1);
	}
	return (0);
}

int main()
{
	int		num, idx;
	human_info	*human;

	
	scanf("%d", &num);
	human = (human_info *)malloc(num * sizeof(human_info));

	idx = -1;
	while (++idx < num)
	{
		scanf("%d %s", &human[idx].age, human[idx].name);
		human[idx].order = idx;
	}

	//quick_sort(human, 0, num - 1);
	qsort(human, num, sizeof(human_info), compare);

	idx = -1;
	while (++idx < num)
		printf("%d %s\n", human[idx].age, human[idx].name);
	
	free(human);
	return (0);
}

//안정정렬 불안정정렬


/*
#include <stdio.h>

int intMax(int* arr, int size) {
    int max=0;
    for(int i=0; i<size; i++){
        if(max < arr[i])
            max = arr[i];
    }
    return max;
}

int sorted_idx[100000] = {0,};
void count_sort(int* age, int size) {
    int max = intMax(age, size);
    int idx[201]={0,};

    for(int k=0; k<size; k++)
        idx[age[k]]++;
    for(int i=1; i<=max; i++)
        idx[i] += idx[i-1];
    
    for(int i=size-1; i>=0; i--){
        sorted_idx[--idx[age[i]]] = i;
    }
}

int main() {
    int N;
    int age[100000];
    char name[100000][101];
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d %s", age+i, name[i]);
    }
    count_sort(age, N);
    
    for(int i = 0; i < N; i++) {
        printf("%d %s\n", age[sorted_idx[i]], name[sorted_idx[i]]);
    }
    return 0;
}
*/