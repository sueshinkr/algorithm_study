#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	test_num, arr_num, *arr, idx, temp;
	char	order[100000], temp_arr;

	scanf("%d", &test_num);

	idx = -1;
	while (++idx < test_num)
	{
		scanf("%s", order);
		scanf("%d", &arr_num);
		arr = (int *)malloc(arr_num * sizeof(int));
		temp = -1;
		while (++temp < arr_num)
			arr[temp] = order[temp * 2 + 1];
	}


}