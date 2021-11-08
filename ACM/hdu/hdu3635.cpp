#include<iostream>
#include<stdio.h>
using namespace std;
const int maxn = 10020;
int s[maxn], cnt[maxn], h[maxn];

int find(int x) {
    int j;
    if (x != s[x]) {
        j = s[x];
        s[x] = find(s[x]);
        h[x] += h[j];
    }
    return s[x];
}

void union_(int a, int b) {
    int x = find(a);
    int y = find(b);
    if (x == y) return;
    s[x] = y;
    ++h[x]; 
    cnt[y] += cnt[x]; 
}

int main() {
    ios::sync_with_stdio(0);
    int T, n ,q, x, y, TT, m, i; scanf("%d", &T); TT = T;
    char c;
    while (T--) {
        printf("Case %d:\n", TT-T);
        scanf("%d %d", &n, &q); getchar();
        for (i = 1; i <= n; ++i) { s[i] = i; cnt[i] = 1; h[i] = 0; }
        for (i = 1; i <= q; ++i) {
            scanf("%c", &c);
            if (c == 'T') {
                scanf("%d%d", &x, &y);
                union_(x, y);
            }
            else {
                scanf("%d", &x); m = find(x);
                printf("%d %d %d\n", m, cnt[m], h[x]);
            }
        }
    }
    return 0;
}