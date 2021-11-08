#include<iostream>
#define ll long long 
using namespace std;

const int maxn = 3005;
const ll mod = 1e9+7;
ll a, ans = 0, sum[maxn], g[maxn][maxn], dp[maxn][maxn];

int main() {
	int N; cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> a; sum[i] = a + sum[i-1];
	}

	g[0][0] = 1;
	for (int j = 1; j <= N; ++j)
		for (int i = 1; i <= N; ++i) {
			dp[i][j] += g[sum[i]%j][j-1];
			g[sum[i]%j][j-1] = (dp[i][j-1] + g[sum[i]%j][j-1]) % mod;
		}

	for (int i = 1; i <= N; ++i) ans = (ans + dp[N][i])%mod;
	cout << ans;
}