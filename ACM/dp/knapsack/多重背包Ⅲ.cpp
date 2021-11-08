#include<stdio.h>
const int maxn = 20020;
int main()
{
	int N, V, v, w, s, f[maxn] = {0};
	scanf("%d%d", &N, &V);
	for (int i = 0; i < N; ++i)
	{	
		scanf("%d%d%d", &v, &w, &s);
		for (int j = 0; j < v; ++j)
		{
			int hh = 0, tt = -1, maxx[maxn], p[maxn];
			for (int z = j; z <= V; z += v)
			{
				while (hh <= tt && f[z] - (z - j) / v * w >= maxx[tt]) --tt;
				while (hh <= tt && (z - j) / v - p[hh] > s) ++hh;
				maxx[++tt] = f[z] - (z - j) / v * w; p[tt] = (z - j) / v;
				f[z] = maxx[hh] + (z - j) / v * w;
			}
		}
	}
	printf("%d", f[V]);
}
