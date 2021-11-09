#include<bits/stdc++.h>
#define LL long long
#define MP make_pair
#define PB push_back
#define ms(x, a) memset(x, a, sizeof(x))
using namespace std;

void debug() {
    cerr << endl;
}
 
template<typename Head, typename... Tail>
void debug(Head H, Tail... T) {
    cerr << " " << H;
    debug(T...);
}
 
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)

const int maxn = 40;
int ans[maxn], w[maxn], buff[maxn], V[maxn], vv[maxn];
int n, m, u, v, cc;
vector<int> c[maxn];
vector<int> ancest[maxn];

void dfs(int k) {
	if (k == n) {
		V[0] = vv[0];
		ans[0] = max(ans[0], V[0]);
		for (int i = 1; i < n; ++i) {
			V[i] = 0;
			for (auto acs: ancest[i])
				V[i] = max(V[i], V[acs] + vv[i]);
			ans[i] = max(ans[i], V[i]);
		}
		return;
	}
	if (c[k].size() == 0) dfs(k + 1);
	for (auto it: c[k]) {
		vv[it] = w[k];
		dfs(k + 1);
		vv[it] = 0;
	}
}

int main() {
	LL buff; cin >> n >> m;
	for (int i = 0; i < n; ++i) { cin >> cc; c[cc-1].push_back(i); }
	for (int i = 0; i < n; ++i) cin >> w[i];
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		ancest[v-1].push_back(u-1);
	}
	ms(ans, 0);
	ms(vv, 0);
	ms(V, 0);

	dfs(0);

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << '\n';
	}
	return 0;
}