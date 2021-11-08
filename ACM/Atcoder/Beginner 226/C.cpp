#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 2e5 + 10;
vector<int> move_[maxn];
vector<int> T;
vector<bool> vis;
 
long long dfs(int fa) {
	long long ans = T[fa];
	vis[fa] = 1;
	for (auto it: move_[fa]) {
		if (!vis[it])
			ans += dfs(it);
	}
	return ans;
}
 
 
int main() {
	int n, t, k, a; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t; T.push_back(t);
		vis.push_back(0);
		cin >> k; move_[i].resize(k);
		for (int j = 0; j < k; ++j) {
			cin >> a; move_[i][j] = a-1;
		}
	}
	cout << dfs(n-1);
	return 0;
}