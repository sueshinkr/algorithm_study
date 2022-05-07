#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef struct queue
{
	int	front, rear;
	int	num[1000000];
} que;

static int	order_d(int a)
{
	return (a * 2 % 10000);
}

static int	order_s(int a)
{
	return (a == 0 ? 9999 : a - 1);
}

static int	order_l(int a)
{
	return (a % 1000 * 10 + a / 1000);
}

static int	order_r(int a)
{
	return (a / 10 + a % 10 * 1000);
}

static void bfs(int a, int b)
{
	int	cur;
	char	cur_order[100];
	bool	visited[10001] = {0, };
	char	order[10001][100];
	que q;

	q.front = 0, q.rear = 0; 
	q.num[q.rear++] = a;
	strcpy(order[a], "");
	
	while (q.rear > q.front)
	{
		cur = q.num[q.front++];
		strcpy(cur_order, order[cur]);

		if (cur != b)
		{
			q.num[q.rear] = order_d(cur);
			if (visited[q.num[q.rear]] != true)
			{
				visited[q.num[q.rear]] = true;
				if (q.num[q.rear] != cur)
				{
					strcpy(order[q.num[q.rear++]], strcat(cur_order, "D"));
					strcpy(cur_order, order[cur]);
				}
			}

			q.num[q.rear] = order_s(cur);
			if (visited[q.num[q.rear]] != true)
			{
				visited[q.num[q.rear]] = true;
				strcpy(order[q.num[q.rear++]], strcat(cur_order, "S"));
				strcpy(cur_order, order[cur]);
			}

			q.num[q.rear] = order_l(cur);
			if (visited[q.num[q.rear]] != true)
			{
				visited[q.num[q.rear]] = true;
				strcpy(order[q.num[q.rear++]], strcat(cur_order, "L"));
				strcpy(cur_order, order[cur]);
			}

			q.num[q.rear] = order_r(cur);
			if (visited[q.num[q.rear]] != true)
			{
				visited[q.num[q.rear]] = true;
				strcpy(order[q.num[q.rear++]], strcat(cur_order, "R"));
				strcpy(cur_order, order[cur]);
			}
		}
		else
		{
			printf("%s\n", cur_order);
			break;
		}
	}
}

int main()
{
	int	test_num, a, b;

	scanf("%d", &test_num);

	while (test_num-- > 0)
	{
		scanf("%d %d", &a, &b);
		bfs(a, b);
	}

	return (0);
}


/*
#include <stdio.h>
#include <string.h>
#define P 10000
#define Qsize 10001

typedef struct
{
    char order;
    int from, num;
} Q;

int T, A, B, wt, rd;
int visited[10001];
Q Queue[Qsize];

int BFS(void)
{
    Q cur, next;
    wt = rd = 0;

    cur.num = A;
    cur.from = -1;
    visited[A] = 1;
    Queue[wt++] = cur;

    while (wt != rd)
    {
        cur = Queue[rd++];
        next.from = rd - 1;

        int d, s, l, r;
        d = (cur.num << 1) % P;
        if (cur.num == 0)
            s = 9999;
        else
            s = cur.num - 1;
        l = cur.num / 1000 + (cur.num % 1000) * 10;
        r = cur.num / 10 + (cur.num % 10) * 1000;

        if (visited[d] == 0)
        {
            visited[d] = 1;
            next.num = d;
            next.order = 'D';
            Queue[wt++] = next;
            if (next.num == B)
                return wt - 1;
        }
        if (visited[s] == 0)
        {
            visited[s] = 1;
            next.num = s;
            next.order = 'S';
            Queue[wt++] = next;
            if (next.num == B)
                return wt - 1;
        }
        if (visited[l] == 0)
        {
            visited[l] = 1;
            next.num = l;
            next.order = 'L';
            Queue[wt++] = next;
            if (next.num == B)
                return wt - 1;
        }
        if (visited[r] == 0)
        {
            visited[r] = 1;
            next.num = r;
            next.order = 'R';
            Queue[wt++] = next;
            if (next.num == B)
                return wt - 1;
        }
    }

    return -1;
}

void PRT(int n)
{
    if (n <= 0)
        return;
    PRT(Queue[n].from);
    printf("%c", Queue[n].order);
}

int main(void)
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &A, &B);
        PRT(BFS());
        printf("\n");
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}
*/
