#include <stdio.h>
#include <stdlib.h>
#define MAX 2147483647

struct	node
{
	int	to, cost;
	struct node	*next;
};

struct	heap
{
	int	cur, cost;
};

struct node	*nd[20001];
struct heap	que[30000];
int	n, e, idx = 1;
int	min_dis[20001];

static void	swap(struct heap *a, struct heap *b)
{
	int	temp_cur, temp_cost;

	temp_cost = a->cost;
	a->cost = b->cost;
	b->cost = temp_cost;

	temp_cur = a->cur;
	a->cur = b->cur;
	b->cur = temp_cur;
}

static void	push_que(int to, int cost)
{
	int	temp_idx = ++idx;
	if (min_dis[to] < cost)
		return ;
	que[temp_idx].cur = to;
	que[temp_idx].cost = cost;
	while(temp_idx > 1)
	{
		if (que[temp_idx].cost < que[temp_idx / 2].cost)
		{
			swap(&que[temp_idx], &que[temp_idx / 2]);
			temp_idx /= 2;
		}
		else
			break;
	}
	
}

static void	pop_que()
{
	int new_idx = 1;

	if (idx == 1)
	{
		que[idx].cur = 0;
		return ;
	}
	que[new_idx].cur = que[idx].cur;
	que[new_idx].cost = que[idx].cost;
	while (new_idx * 2 < idx)
	{
		if (que[new_idx].cost > que[new_idx * 2].cost || que[new_idx].cost > que[new_idx * 2 + 1].cost)
		{
			if (que[new_idx * 2].cost < que[new_idx * 2 + 1].cost)
			{
				swap(&que[new_idx], &que[new_idx * 2]);
				new_idx = new_idx * 2;
			}
			else
			{
				swap(&que[new_idx], &que[new_idx * 2 + 1]);
				new_idx = new_idx * 2 + 1;
			}
		}
		else
			break;
	}
	idx--;
}

static void	dijkstra(int start)
{
	int	from;

	min_dis[start] = 0;
	que[1].cur = start;
	while (que[1].cur != 0)
	{
		from = que[1].cur;
		if (min_dis[que[1].cur] < que[1].cost)
		{
			pop_que();
			continue;
		}
		while (nd[from])
		{
			if (min_dis[nd[from]->to] > min_dis[from] + nd[from]->cost)
			{
				min_dis[nd[from]->to] = min_dis[from] + nd[from]->cost;
				push_que(nd[from]->to, min_dis[nd[from]->to]);
			}
			nd[from] = nd[from]->next;
		}
		pop_que();
	}
}

int	main()
{
	int	idx, start, from, to, cost;

	scanf("%d %d", &n, &e);
	scanf("%d", &start);

	struct node *temp_node;

	idx = -1;
	while (++idx < e)
	{
		scanf("%d %d %d", &from, &to, &cost);

		temp_node = (struct node *)malloc(sizeof(struct node));
		temp_node->to = to;
		temp_node->cost = cost;
		temp_node->next = nd[from];
		nd[from] = temp_node;
	}

	idx = 0;
	while (++idx <= n)
		min_dis[idx] = MAX;

	dijkstra(start);

	idx = 0;
	while(++idx <= n)
	{
		if (min_dis[idx] == MAX)
			printf("INF\n");
		else
			printf("%d\n", min_dis[idx]);
	}
}


/*
#define MXN 20000
#define MXM 300000

typedef struct {
	int dist, to;
	int next;
} Edge;
Edge E[MXM];
int Ecnt;

int Adj[MXN];

void init(int n) {
	for (int i = 0; i < n; i++) {
		Adj[i] = -1;
	}
	Ecnt = 0;
}

void pushEdge(int a, int b, int w) {
	int eid = Ecnt++;
	E[eid].to = b;
	E[eid].dist = w;
	E[eid].next = Adj[a];
	Adj[a] = eid;
}

typedef struct {
	int to;
	int dist;
} QEntry;
QEntry PQ[MXM * 2];
int Qlen;

#define SWAP(t, x, y)	{ t=(x); (x)=(y); (y)=t; }

void inline swapQ(int a, int b) {
	int t;
	SWAP(t, PQ[a].to, PQ[b].to);
	SWAP(t, PQ[a].dist, PQ[b].dist);
}

void pushQ(int to, int dist) {
	int i = Qlen++;
	PQ[i].to = to;
	PQ[i].dist = dist;
	while (i > 0) {
		int p = (i - 1) / 2;
		if (PQ[p].dist > PQ[i].dist) {
			swapQ(p, i);
			i = p;
		}
		else
			break;
	}
}

QEntry* popQ() {
	QEntry* ret = NULL;
	if (Qlen > 0) {
		swapQ(0, --Qlen);
		ret = &PQ[Qlen];
		int i = 0;
		while (i * 2 + 1 < Qlen) {
			int l = i * 2 + 1, r = l + 1;
			if (r < Qlen && PQ[r].dist < PQ[l].dist && PQ[r].dist < PQ[i].dist) {
				swapQ(r, i); i = r;
			}
			else if (PQ[l].dist < PQ[i].dist) {
				swapQ(l, i); i = l;
			}
			else
				break;
		}
	}
	return ret;
}

#define INF (1<<30)

int D[MXN];
int Vdone[MXN];

void spf(int n, int s)
{
	for (int i = 0; i < n; i++) {
		D[i] = INF;
		Vdone[i] = 0;
	}
	D[s] = 0;
	Qlen = 0;
	pushQ(s, 0);
	QEntry *qe;
	while ((qe = popQ()) != NULL) {
		int i = qe->to;
		if (Vdone[i]) continue;
		Vdone[i] = 1;
		for (int eid = Adj[i]; eid >= 0; eid = E[eid].next) {
			int to = E[eid].to;
			if (D[to] > D[i] + E[eid].dist) {
				D[to] = D[i] + E[eid].dist;
				pushQ(to, D[to]);
			}
		}
	}
}
int main()
{
	int N, M, S; scanf("%d %d %d", &N, &M, &S);
	init(N);
	for (int i = 0; i < M; i++) {
		int A, B, C; scanf("%d %d %d", &A, &B, &C);
		pushEdge(A - 1, B - 1, C);
	}
	spf(N, S-1);
	for (int i = 0; i < N; i++) {
        if (D[i] == INF) printf("INF\n");
		else printf("%d\n", D[i]);
	}
    return 0;
}
*/
