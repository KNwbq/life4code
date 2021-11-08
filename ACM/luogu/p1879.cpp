#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = (1<<12) + 5, mod = 1e8;
int aa, map_[15], m, n, cnt=0;
int sta[maxn];
// int sum[maxn];
ll dp[15][maxn];

int getSum(int x) {
	ll ans = 0;
	while (x) {
		ans += 1;
		x -= x&(-x);
	}
	return ans;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> aa, map_[i] <<= 1, map_[i] += (1-aa);

	for (int i = 0; i < (1 << n); ++i) {
		if (!(i&(i<<1)) && !(i&(i>>1))) {
			sta[++cnt] = i;
			// sum[cnt] = getSum(i);
			if (!(i&(map_[0]))) dp[0][cnt] = 1;
		}
	}

	for (int i = 1; i < m; ++i)
		for (int j = 1; j <= cnt; ++j) {
			if (!(sta[j]&map_[i])) {
				for (int k = 1; k <= cnt; ++k) {
					if (!(sta[j]&sta[k]))
						dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
				}
			}
		}
	
	ll ans = 0;
	for (int i = 1; i <= cnt; ++i)
		ans = (ans + dp[m-1][i]) % mod;
	
	cout << ans;
	return 0;
}