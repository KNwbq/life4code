#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn = 1010;
int ans[maxn] = {0}, v, w, s, N, V;

int main()
{
    scanf("%d%d", &N, &V);
    for (int m = 0; m < N; ++m)
    {
        scanf("%d%d%d", &v, &w, &s);
        if (s == -1) for (int i = V; i >= v; --i) ans[i] = max(ans[i], ans[i - v] + w);
        else if (s == 0) for (int i = v; i <= V; ++i) ans[i] = max(ans[i], ans[i - v] + w);
        else {
           for (int i = 0; i < v; ++i)
           {
               int hh = 0, tt = -1, maxx[maxn], p[maxn];
               for (int j = i; j <= V; j += v)
               {
                   while (hh <= tt && ans[j] - (j - i) / v * w >= maxx[tt]) --tt;
                   while (hh <= tt && (j - i) / v - p[hh] > s) ++hh;
                   maxx[++tt] = ans[j] - (j - i) / v * w; p[tt] = (j - i) / v;
                   ans[j] = maxx[hh] + (j - i) / v * w;
               }
           }
        }
    }
    printf("%d", ans[V]);
    system("pause");
}