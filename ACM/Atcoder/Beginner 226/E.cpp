#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
 
const int _ = 5, maxn = 2e5;
int n, m, vis[maxn+_];
vector<int> g[maxn+_], bk;
using LL = long long;
 
void dfs(int x, int fa) {
	vis[x]++;
	if (vis[x] > 1) return;
	bk.push_back(x);
	for (int y: g[x])
		if (y != fa) dfs(y, x);
}
 
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(vis, 0, sizeof(vis));
	LL ans = 1;
	for (int i = 1; i <= n; ++i) if (!vis[i]) {
		bk.clear();
		dfs(i, 0);
		int cnt = 0;
		for (int j: bk)
			cnt += (vis[j] == 2);
		if (cnt != 2) {
			ans = 0;
			break;
		}
		ans = ans * 2 % 998244353;
	}
	cout << ans;
	return 0;
}