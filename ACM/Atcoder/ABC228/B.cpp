#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 20;

int vis[maxn];
int arry[maxn];
int ans = 0;

void dfs(int x) {
	if (!vis[x]) {
		// cout << x;
		vis[x] = 1; ans += 1;
		if (arry[x]) dfs(arry[x]);
		else return;
	}
	else return;
}

int main() {
	memset(vis, 0, sizeof(vis));
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n ; ++i) cin >> arry[i];
	// for (int i = 1; i <= n ; ++i) cout << arry[i];
	dfs(x);
	cout << ans;
	return 0;
}