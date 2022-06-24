/*
	백준 2206 벽부수고 이동하기 
	row, col (1000이하) 의 맵이 주어졌을때, 1,1 에서 시작하여 우측최하단으로 이동하는 최단경로 찾기.
	한번에 한해 벽을 부술 수 있다. 
	is_visited[][][0/1] 로 벽을 부술 수 있는 상태와 이미 부순 상태를 나눠 저장한다. 
	1을 벽을 부술 수 있는 상태, 0을 이미 부순 상태로 지정. 
*/
#include <stdio.h>
#define q_max 1000*1000*2

typedef struct P
{
	int y, x, t, w; // w : 1 = 벽 부술 수 있음 w : 0 = 벽을 이미 부숨
}P;

P que[q_max], temp;
int wp, rp;

int row, col;
char map[1000 + 10][1000 + 10];
char is_visited[1000 + 10][1000 + 10][2];
int yy[] = { -1, 0, 1, 0 };
int xx[] = { 0, 1, 0, -1 };

void get_input()
{
	scanf("%d%d", &row, &col);
	for (int i = 1; i <= row; i++)
	{
		scanf("%s", map[i] + 1);
	}
}

void enque(int y, int x, int t, int w)
{
	que[wp].y = y;
	que[wp].x = x;
	que[wp].t = t;
	que[wp++].w = w;
	wp %= q_max;
	is_visited[y][x][w] = 1;
}

void find_route()
{
	enque(1, 1, 0, 1);
	while (wp != rp)
	{
		temp = que[rp++];
		if (temp.y == row && temp.x == col)
		{
			printf("%d", temp.t + 1);
			return;
		}
		rp %= q_max;
		for (int i = 0; i < 4; i++)
		{
			if (temp.y + yy[i] < 1 || temp.y + yy[i] > row || temp.x + xx[i] < 1 || temp.x + xx[i] > col)continue;
			if (map[temp.y + yy[i]][temp.x + xx[i]] == '1')
			{
				if (temp.w == 0) continue;
				if (is_visited[temp.y + yy[i]][temp.x + xx[i]][0] == 1) continue;
				enque(temp.y + yy[i], temp.x + xx[i], temp.t + 1, 0);
			}
			else
			{
				if (is_visited[temp.y + yy[i]][temp.x + xx[i]][temp.w] == 1) continue;
				is_visited[temp.y + yy[i]][temp.x + xx[i]][temp.w] = 1;
				enque(temp.y + yy[i], temp.x + xx[i], temp.t + 1, temp.w);
			}
		}
	}
	printf("-1");
	return;
}

int main(void)
{
	get_input();
	find_route();
	return 0;
}
