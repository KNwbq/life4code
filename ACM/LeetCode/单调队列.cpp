#include<stdio.h>
const int maxn = 1000020;
long long ary[maxn], maxx[maxn], minn[maxn], px[maxn], pn[maxn];

int main()
{
	int n, k, head = 0, tail = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) scanf("%lld", &ary[i]);
	minn[0] = ary[0]; pn[0] = 0;	
	if (k == 1) printf("%d ", minn[head]);
	for (int i = 1; i < n; ++i){
		while (tail >= head && minn[tail] >= ary[i]) --tail;
		minn[++tail] = ary[i]; pn[tail] = i;
		while (tail >= head && i - pn[head] > k - 1) ++head;
		if (i >= k - 1) printf("%d ", minn[head]);  
	}
	printf("\n"); head = 0, tail = 0;
    maxx[0] = ary[0]; px[0] = 0;
    if (k == 1) printf("%lld ", maxx[head]);  
	for (int i = 1; i < n; ++i){ 
		while (tail >= head && maxx[tail] <= ary[i]) --tail;
		maxx[++tail] = ary[i]; px[tail] = i;
		while (tail >= head && i - px[head] > k - 1) ++head;
		if (i >= k - 1) printf("%lld ", maxx[head]);  
	}
	return 0;
}
