#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 110;
int f[maxn];

int main()
{
	int N, M ,v, w, s;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d %d", &v, &w, &s);
		for (int j = M; j >= v; --j)
			for (int n = 1; n <= s && n*v <= j; ++n)
				f[j] = max(f[j], f[j - n*v] + w*n);	
	} 
	printf("%d", f[M]);
	return 0;
}
