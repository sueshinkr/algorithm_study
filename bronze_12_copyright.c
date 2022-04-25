#include <stdio.h>

int main()
{
	int song_num, average;

	scanf("%d %d", &song_num, &average);

	printf("%d", song_num * (average - 1) + 1);
	return (0);
}