#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1e6 + 10;
const int mod = 998244353;
int dp[maxn][10];

int main() {
	int n; cin >> n;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= 9; ++i) dp[1][i] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= 9; ++j) {
			dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
			if (j - 1 >= 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
			if (j + 1 <= 9) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % mod;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= 9; ++i) {
		ans = (ans + dp[n][i]) % mod;
	}
	cout << ans;
	return 0;
}