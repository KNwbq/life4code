#include<stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		if (l == r) printf("1\n");
		else printf("%d\n", k);	
	}	
	return 0;
} 
