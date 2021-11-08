#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e7;
int lc[maxn], rc[maxn], Sum[maxn], cnt = 0, rt[maxn];
vector<int> arry;
vector<int> arry2;


int build(int l, int r) {
	int root = ++cnt;
	if (l == r) return root;
	int mid = (l + r) >> 1;
	lc[root] = build(l, mid);
	rc[root] = build(mid+1, r);
	return rt[0] = root;
}

int update(int k, int l, int r, int root) {
	int dir = ++cnt;
	lc[dir] = lc[root], rc[dir] = rc[root], Sum[dir] = Sum[root] + 1;
	if (l == r) return dir;
	int mid = (l + r) >> 1;
	if (k <= mid)
		lc[dir] = update(k, l, mid, lc[dir]);
	else
		rc[dir] = update(k, mid+1, r, rc[dir]);
	return dir;
}

int query(int k, int u, int v, int l, int r) {
	int mid = (l + r) >> 1;
	int x = Sum[lc[v]] - Sum[lc[u]];
	if (l == r) return l;
	if (x < k) return query(k - x, rc[u], rc[v], mid+1, r);
	else return query(k, lc[u], lc[v], l, mid);

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		arry.push_back(a);
		arry2.push_back(a);
	}
	sort(arry.begin(), arry.end());
	unique(arry.begin(), arry.end());
	int len = arry.size();
	build(1, len);
	for (int i = 0; i < n; ++i) {
		int kk = lower_bound(arry.begin(), arry.end(), arry2[i]) - arry.begin() + 1;
		rt[i+1] = update(kk, 1, len, rt[i]);
	}
	for (int i = 0; i < m; ++i) {
		int u, v, kkk;
		cin >> u >> v >> kkk;
		cout << arry[query(kkk, rt[u-1], rt[v], 1, len) - 1] << '\n';
	}
	return 0;
}