#include<bits/stdc++.h>
using namespace std;

const int maxn = 6020;

struct node {
	int to, next;
}edge[maxn];

int inf = 0x4f4f4f4f;
int head[maxn], r[maxn], cnt = 0, is_h[maxn], rem[2][maxn];

void addE(int f, int t) {
	edge[cnt].to = t;
	edge[cnt].next = head[f];
	head[f] = cnt++;
}

long long  dfs(int si, int cur) {
	if (rem[si][cur] != inf) return rem[si][cur];
	if (head[cur] == -1 && si == 0) return 0;
	if (head[cur] == -1 && si == 1) return r[cur];
	long long ans = 0;
	if (si == 1) {
		ans += r[cur];
		for (int i = head[cur]; i != -1; i = edge[i].next) 
			ans += dfs(0, edge[i].to);
	}
	else if (si == 0) 
		for (int i = head[cur]; i != -1; i = edge[i].next) 
			ans += max(dfs(1, edge[i].to), dfs(0, edge[i].to));
	return rem[si][cur] = ans;	
}

int main() {
	freopen("D:\\VSCODE\\DataTest\\data.in.txt", "r", stdin);
	freopen("D:\\VSCODE\\DataTest\\data.out.txt", "w", stdout);


	int n, f, t, boss = -1; cin >> n;
	for (int i = 0; i < maxn; ++i) head[i] = -1;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < maxn; ++j) rem[i][j] = inf;
	}
	for (int i = 1; i <= n; ++i) cin >> r[i];
	for (int i = 0; i < n - 1; ++i) {
		cin >> t >> f;
		is_h[t] = 1;	
		addE(f, t);
	}	
	for (int i = 1; i <= n; ++i) 
		if (!is_h[i]) {
			cout << max(dfs(1, i), dfs(0, i));
			return 0;
		}
}