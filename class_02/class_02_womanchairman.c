#include <stdio.h>
#include <stdlib.h>

/*
int main()
{
	int	num, floor, room, idx = 0;
	int **arr, temp_floor, temp_room, i, j;

	scanf("%d", &num);

	while (idx < num)
	{
		scanf("%d %d", &floor, &room);
		arr = (int **)malloc((floor + 1) * sizeof(int *));

		temp_floor = 0;
		while (temp_floor <= floor)
		{	
			arr[temp_floor] = (int *)malloc(room * sizeof(int));
			temp_room = 0;	
			if (temp_floor == 0)
			{
				while (temp_room++ < room)
					arr[temp_floor][temp_room - 1] = temp_room;
			}
			else
			{
				i = 0;
				while (i < room)
					arr[temp_floor][i++] = 0;
				
				temp_room = 0;
				while (temp_room < room)
				{
					i = temp_floor - 1;
					while (i < temp_floor)
					{
						j = 0;
						while (j <= temp_room)
							arr[temp_floor][temp_room] += arr[i][j++];
						i++;
					}
					temp_room++;
				}
			}
			temp_floor++;
		}		
		printf("%d\n", arr[temp_floor - 1][temp_room - 1]);
		
		temp_floor = 0;
		while (temp_floor <= floor)
			free(arr[temp_floor++]);
		free(arr);
		
		idx++;
	}

	return (0);
}

*/

/*
0 1 2 3 4 5 6
1 1 3 6 10 15 21
2 1 4 10 20 35 56
3 1 5 15 35 70
4 1 6 21 56 126
*/

int	main()
{
	int	test_num, floor, room, **arr, temp_floor, temp_room;
	
	scanf("%d", &test_num);

	while(test_num-- > 0)
	{
		scanf("%d %d", &floor, &room);
		arr = (int **)malloc((floor + 1) * sizeof(int *));

		temp_floor = -1;
		while (++temp_floor <= floor)
		{
			arr[temp_floor] = (int *)malloc((room + 1) * sizeof(int));

			if (temp_floor == 0)
			{
				temp_room = -1;
				while (++temp_room <= room)
					arr[temp_floor][temp_room] = temp_room;
			}
			else
			{
				arr[temp_floor][1] = 1;
				temp_room = 1;
				while (++temp_room <= room)
					arr[temp_floor][temp_room] = arr[temp_floor - 1][temp_room] + arr[temp_floor][temp_room - 1];
			}
		}
		printf("%d\n", arr[floor][room]);
		
		temp_floor = -1;
		while (++temp_floor <= floor)
			free(arr[temp_floor]);
		free(arr);
	}
	return (0);
}