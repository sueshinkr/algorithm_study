#include <stdio.h>

typedef struct queue
{
	int	front, rear;
	int	data[100001];
}	que;

static int bfs(int *check, int point, int hide)
{
	int	cur, idx, is_next_line = 0, cur_line = 1, togo[3];
	int	count_before = 1, count_after = 0;
	que q;

	if (point >= hide)
		return (point - hide);

	q.front = 0;
	q.rear = 0;
	q.data[q.rear++] = point;

	while (q.rear > q.front)
	{
		cur = q.data[q.front++];

		if (check[cur] < 2)
		{
			check[cur]++;
			togo[0] = cur - 1;
			togo[1] = cur + 1;
			togo[2] = cur * 2;

			idx = -1;
			while (++idx <= 2)
			{
				if (togo[idx] == hide)
					return (cur_line);
				if (togo[idx] >= 0 && togo[idx] <= 100000 && check[togo[idx]] < 1)
				{
					check[togo[idx]]++;
					q.data[q.rear++] = togo[idx];
					count_after++;
				}
			}
			is_next_line++;

			if (count_before == is_next_line)
			{
				is_next_line = 0;
				count_before = count_after;
				count_after = 0;
				cur_line++;
			}
		}
	}
	return (0);
}

int main()
{
	int	n, k, check[100001] = {0, };
	
	scanf("%d %d", &n, &k);
	printf("%d\n", bfs(check, n, k));

	return (0);
}

/*

효율적인 답안

int min(int a, int b) {
    if(a>b) return b;
    else return a;
}

int value(int K, int N) {
    if(K <= N)
        return N-K;
    else if(K == 1) 
        return 1;
    else if(K%2 == 1)
        return (1 + min(value(K-1,N),value(K+1,N)));
    else
        return min(K-N, 1 + value(K/2,N));
}

int main(void) {
    int N,K;
    scanf("%d %d",&N,&K);
    printf("%d\n",value(K,N));
    return 0;
}
*/