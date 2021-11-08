#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 3005;
LL dp[maxn][maxn], sum[maxn], w[maxn][maxn], arry[maxn];

int main() {
	int V, P, a;
	cin >> V >> P;
	for (int i = 1; i <= V; ++i) {
		cin >> arry[i]; sum[i] = sum[i-1] + arry[i];
	}
	for (int i = 1; i <= V; ++i) 
		for (int j = i; j <= V; ++j)
			w[i][j] = (((i+j)>>1) - i + 1)*arry[(i+j)>>1] - (sum[(i+j)>>1] - sum[i-1]) + sum[j] - sum[(i+j)>>1] - (j - ((i+j)>>1))*arry[(i+j)>>1];

	for (int i = 0; i < maxn; ++i)
		for (int j = 0; j < maxn; ++j)
			{ dp[i][j] = 0x4f4f4f4f; dp[0][i] = 0; }
	for (int j = 1; j <= P; ++j)
		for (int i = 1; i <= V; ++i)
			for (int k = 0; k < i; ++k)
				dp[i][j] = min(dp[i][j], dp[k][j-1] + w[k+1][i]);
	cout << dp[V][P];
}