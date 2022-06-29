#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char b[1000001]; //b
	char pivot[37]; //pivot
	char a[1000001]; //a
	int top=-1;
	
	scanf("%s", b);
	scanf("%s", pivot);
	
	int b_len=strlen(b);
	int pivot_len=strlen(pivot);
	
	for (int i=0; i<b_len; i++) {
		top++;
		a[top]=b[i];
		if (a[top]==pivot[pivot_len-1]) {
			int flag=0;
			for (int j=1; j<pivot_len; j++) {
				if (a[top-j]!=pivot[pivot_len-1-j]) {
					flag=1;
					break;
				}
			}
			if (flag==0) {
				top-=pivot_len;
			}
		}
	}
	
	a[++top]='\0';
	if (a[0]=='\0') {
		printf("FRULA");
	}
	else {
		printf("%s", a);
	}
} 
