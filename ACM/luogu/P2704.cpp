#include<bits/stdc++.h>
using namespace std;

char c;
const int maxn = 400;
int map_[105];
long long dp[2][maxn][maxn];
int sta[maxn], sum[maxn];
int cnt = 0;

int getSum(int x) {
	int cnt = 0;
	while(x > 0) {
		++cnt;
		x -= x&(-x);
	}
	return cnt;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> c, map_[i] = (map_[i]<<1) + (c=='H'?1:0);
	
	// for (int i = 0; i < n; ++i) cout << map_[i] << ' ';


	for (int i = 0; i <= (1<<m)-1; ++i) {
		if (!(i&(i<<1)) && !(i&(i<<2)) && !(i&(i>>1) && !(i&(i>>2)))) {
			// cout << i << ' ';
			sta[++cnt] = i;
			sum[cnt] = getSum(i);
			if (!(i&map_[0])) dp[0][0][cnt] = sum[cnt];
		}
	}

	for (int i = 1; i <= cnt; ++i)
		for (int j = 1; j <= cnt; ++j)
			if (!((sta[i]&sta[j]) | (sta[i]&map_[1]))) dp[1][j][i] = dp[0][0][j] + sum[i];
	
	for (int i = 2; i < n; ++i) {
		for (int j = 1; j <= cnt; ++j)
			for (int k = 1; k <= cnt; ++k) {
				if (!((sta[j] & sta[k]) | (sta[j] & map_[i]))) {
					for (int z = 1; z <= cnt; ++z) {
						if (!(sta[z] & sta[j])) {
							dp[i%2][k][j] = max(dp[i%2][k][j], dp[(i-1)%2][z][k] + sum[j]);
						}
					}
				}
			}
	}
	long long ans = 0;
	for (int i = 1; i <= cnt; ++i)
		for (int j = 1; j <= cnt; ++j)
			ans = max(ans, dp[(n-1)%2][i][j]);
	cout << ans;
	return 0;
}