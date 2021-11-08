#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int v[maxn], w[maxn], f[maxn];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d %d", &v[i], &w[i]);
	for (int i = 0; i < n; ++i)
		for (int j = m; j >= v[i]; --j)
			f[j] = max(f[j], f[j-v[i]] + w[i]);
	printf("%d", f[m]);
	return 0;
}
