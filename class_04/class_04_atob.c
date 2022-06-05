#include <stdio.h>

#define MAX 2147483647

int	a, b, min_count = 100000;

static void	recur(int cur, int count)
{
	if (cur == b && count < min_count)
		min_count = count;
	if (cur > b)
		return;
	
	if (cur < MAX / 2)
		recur(cur * 2, count + 1);
	if (cur <= MAX / 10)
		recur(cur * 10 + 1, count + 1);

}
int	main()
{
	scanf("%d %d", &a, &b);
	recur(a, 1);
	
	if (min_count == 100000)
		printf("%d\n", -1);
	else
		printf("%d\n", min_count);
	return (0);
}

/*
#include <stdio.h>

long long int A, B;
int mint = 98765;

void process(int cnt, long long int now){
    if (now >= B){
        if (now == B && cnt < mint){
            mint = cnt;
        }
        return;
    }
    process(cnt+1, now*10+1);
    process(cnt+1, now*2);
}

int main(void){
    scanf("%lld %lld", &A, &B);
    process(0, A);
    if (mint == 98765) mint = -2;
    printf("%d", mint+1);
}
*/

/*
#include <stdio.h>

int main(void)
{
    int p, c, r;
    scanf("%d %d", &c, &p);
    for(r = 1; c < p; r++){
        if(p & 1){
            if((p-1) % 10) break;
            p = (p - 1) / 10;
        }
        else
            p = p / 2;
    }
    printf("%d", (c == p) ? r : -1);
    return 0;
}
*/