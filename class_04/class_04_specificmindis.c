#include<stdio.h>
#define INF 2147483647

int v1, v2, N;
int map[801][801];
long long dist[801];
int visit[801];

int getSmallIndex(void)
{
	int i, j;
	int min = INF;
	int index = 1;
	for(i = 1; i <= N; i++)
	{
		if(dist[i] < min && !visit[i])
		{
			min = dist[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start)
{
	int i, j, index;
	
	for(i = 1; i <= N; i++)
	{
		visit[i] = 0;
		dist[i] = map[start][i];
	}
	visit[start] = 1;
	
	for(i = 1; i <= N; i++)
	{
		index = getSmallIndex();
		visit[index] = 1;
		
		for(j = 1; j <= N; j++)
		{
			if(!visit[j])
			{
				if(dist[j] > dist[index] + map[index][j])
				{
					dist[j] = dist[index] + map[index][j];
				}
			}
		}
	}
}

int main(void)
{
	int edge, from, to, cost, i, j;
	long long res1 = 0, res2 = 0;
	scanf("%d %d", &N, &edge);
	
	for(i = 1; i <= N; i++)
	{
		for(j = 1; j <= N; j++)
		{
			if(i == j)
				map[i][j] = 0;
			else
				map[i][j] = INF;
		}
	}
	
	for(i = 0; i < edge; i++)
	{
		scanf("%d %d %d", &from, &to, &cost);
		
		map[from][to] = cost;
		map[to][from] = cost; 
	}
	
	scanf("%d %d", &v1, &v2);
	
	dijkstra(v1);
	res1 = res1 + dist[1] + dist[v2];
	res2 = res2 + dist[N];
	dijkstra(v2);
	res1 = res1 + dist[N];
	res2 = res2 + dist[1] + dist[v1];
	
	if(res1 >= INF || res2 >= INF)
		printf("-1");
	else if(res1 > res2)
		printf("%lld", res2);
	else
		printf("%lld", res1);
}
