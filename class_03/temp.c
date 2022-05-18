#include <iostream>
#include <cstring>

using namespace std;
void BFS();

int N = 0, vv = 0, hh = 0, et = 0, t = 0;;
int nq = 0, pq = 0;

int Map[20][21] = { 0, };
int vst[20][21] = { 0, };

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };


struct Shark
{
	int v=0, h=0;
	int sz=0;
	int eat = 0;
}Sk;

struct Fish
{
	int v=0, h=0;
	int sz=0;

}Fs[500];

struct QUEUE
{
	int sv=0, sh=0, fv=0, fh=0, t=0;

}q[1000 * 1000];


int main(void)
{

	int i, j;
	int res = 0, sum = 0;
	cin >> N;

	int fc = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> Map[i][j];

			if (Map[i][j] == 9)
			{
				Sk.v = i;
				Sk.h = j;
				Sk.sz = 2;
				Map[i][j] = 0;
			}
		}
	}


	while (res != 9999)
	{
		
		

		fc = 0;
		int big = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				big = big < Map[i][j] ? Map[i][j] : big;

				if (Map[i][j] != 0 && Map[i][j] < Sk.sz)
				{
					Fs[fc].v = i;
					Fs[fc].h = j;
					Fs[fc++].sz = Map[i][j];
					big = big < Map[i][j] ? Map[i][j] : big;

				}
			}
		}

		if (fc == 0) break;

		et = 1;
		struct Fish tmp;
		while (et)
		{
			et = 0;
			for (i = 0; i < fc - 1; i++)
			{
				if ((abs(Sk.v - Fs[i].v) + abs(Sk.h - Fs[i].h)) > (abs(Sk.v - Fs[i + 1].v) + abs(Sk.h - Fs[i + 1].h)))
				{
					tmp = Fs[i];
					Fs[i] = Fs[i + 1];
					Fs[i + 1] = tmp;
					et = 1;
				}
				else if ((abs(Sk.v - Fs[i].v) + abs(Sk.h - Fs[i].h)) == (abs(Sk.v - Fs[i + 1].v) + abs(Sk.h - Fs[i + 1].h)))
				{
					if (Fs[i].v > Fs[i + 1].v)
					{
						tmp = Fs[i];
						Fs[i] = Fs[i + 1];
						Fs[i + 1] = tmp;
						et = 1;

					}
					else if (Fs[i].v == Fs[i + 1].v)
					{
						if ((Fs[i].h > Fs[i + 1].h))
						{
							tmp = Fs[i];
							Fs[i] = Fs[i + 1];
							Fs[i + 1] = tmp;
							et = 1;

						}

					}
				}

			}

		}

		res = 9999;
		
		int mv = 0, mh = 0;
		
		for (i = 0; i < fc; i++)
		{
			
			pq = nq = 0;
			memset(q, 0, sizeof(q));

			if (Sk.sz >= big)
			{
				if (res > abs(Sk.v - Fs[i].v) + abs(Sk.h - Fs[i].h)) {
					res = abs(Sk.v - Fs[i].v) + abs(Sk.h - Fs[i].h);
					mv = Fs[i].v;
					mh = Fs[i].h;
				}


			}
			else
			{
				et = 9999;
				q[nq].t = 0;
				q[nq].sv = Sk.v;
				q[nq].sh = Sk.h;
				q[nq].fv = Fs[i].v;
				q[nq++].fh = Fs[i].h;
				memset(vst, 0, sizeof(vst));

				BFS();

				if (et != 9999)
				{
					if (res > et + 1) {
						res = et + 1;
						mv = Fs[i].v;
						mh = Fs[i].h;
					}
				}
			}	
		}

		if (res != 9999)
		{
			sum += res;
			Sk.eat++;
			if (Sk.eat == Sk.sz) {
				Sk.sz++;
				Sk.eat = 0;
			}
			Sk.v = mv;
			Sk.h = mh;
			Map[mv][mh] = 0;
		}



	}

	cout << sum;

	return 0;
}



void BFS()
{
	while (pq != nq)
	{
		int sv = q[pq].sv;
		int sh = q[pq].sh;
		int fv = q[pq].fv;
		int fh = q[pq].fh;
		int t = q[pq++].t;

		vst[sv][sh] = 1;


		for (int ii = 0; ii < 4; ii++)
		{
			vv = sv + dy[ii];
			hh = sh + dx[ii];

			if (vv < 0 || hh < 0 || vv >= N || hh >= N) continue;
			if (vst[vv][hh] == 1) continue;
			if (Map[vv][hh] > Sk.sz) continue;
			if (vv == fv && hh == fh)
			{
				et = et > t ? t : et;
				return;
			}

			q[nq].t = t + 1;
			q[nq].sv = vv;
			q[nq].sh = hh;
			q[nq].fv = fv;
			q[nq++].fh = fh;

			vst[sv + dy[ii]][sh + dx[ii]] = 0;
		}

	}

}
