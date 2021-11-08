#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define debug(x) cerr<<#x<<":"<<x<<endl
using namespace std;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int maxn = 4e4+20;
int cnt = 0, head[maxn], dis[maxn], dep[maxn], fa[maxn][25];
bool vis[maxn];

struct edge {
    int t, w, next;
}edges[maxn << 1];

void init() {
    cnt = 0;
    memset(head, -1, sizeof(head)); 
    memset(fa, 0, sizeof(fa));
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    memset(dep, 0, sizeof(dep));
}

void addEdge(int u, int v, int w) {
    edges[cnt].t = v;
    edges[cnt].w = w;
    edges[cnt].next = head[u];
    head[u] = cnt++; 
}

void dfs(int x) {
    for (int i = 1; i < 20; ++i)
        if (fa[x][i-1]) fa[x][i] = fa[fa[x][i-1]][i-1];
        else break;
    for (int j = head[x]; j != -1; j = edges[j].next) {
        if (!vis[edges[j].t]) {
            vis[edges[j].t] = true;
            fa[edges[j].t][0] = x;
            dis[edges[j].t] = dis[x] + edges[j].w;
            dep[edges[j].t] = dep[x] + 1;
            dfs(edges[j].t);
        }
    } 
}

int LCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int c = dep[u] - dep[v];
    for (int i = 0; (1 << i) <= c; ++i) 
        if ((1 << i) & c)   u = fa[u][i]; 
    if (u == v) return u;
    for (int i = 20; i >= 0; --i) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    u = fa[u][0], v = fa[v][0];
    return u;
}

int main() {
    int T, n, m, i, j, k; read(T);
    while (T--) {
        init();
        read(n), read(m);
        for (int ii = 0; ii < n-1; ++ii) {
            read(i), read(j), read(k);
            addEdge(i, j, k); addEdge(j, i, k);
        }
        dfs(1);
        // debug(LCA(1, 2));
        for (int ii = 0; ii < m; ++ii) {
            read(i), read(j);
            print(dis[i] + dis[j] - 2 * dis[LCA(i, j)], '\n');
        }
    }
}