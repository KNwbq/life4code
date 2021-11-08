#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1050;
ll dp[maxn][maxn];
ll dp2[maxn][maxn];

ll arry[maxn];
ll prefix[maxn];

int main() {
	int a, n, tot = 0; cin >> n;
	for (int i = 1; i <= n; ++i)	cin >> arry[i]; 
	for (int i = n+1; i <= 2*n; ++i) arry[i] = arry[i - n];
	for (int i = 1; i <= 2*n; ++i) prefix[i] = prefix[i-1]+arry[i];

	for (int i = 1; i < n; ++i)
		for (int j = 1; j + i <= 2*n; ++j) {
			dp2[j][j+i] = 0x4f4f4f4f;
			ll tot = 0;
			for (int ii = j; ii <= j+i; ++ii) tot += arry[ii];
			for (int k = j; k + 1 <= j + i; ++k) {
				dp[j][j+i] = max(dp[j][i+j], dp[j][k] + dp[k+1][j+i] + tot);
				dp2[j][j+i] = min(dp2[j][i+j], dp2[j][k] + dp2[k+1][j+i] + tot);
			}
		}
	ll mina = 0x4f4f4f4f, maxa = 0;
	for (int i = 1; i <= n; ++i) {
		mina = min(mina, dp2[i][i+n-1]);
		maxa = max(maxa, dp[i][i+n-1]);
	}
	cout << mina << endl << maxa;
	return 0;
}