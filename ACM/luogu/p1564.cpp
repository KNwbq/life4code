// #include<bits/stdc++.h>
// #define debug(x) cerr<<#x<<":"<<x<<endl
// using namespace std;

// const int maxn =3005;
// const int INF = 0x4f4f4f4f;
// int n ,m, arry[maxn], one[maxn], two[maxn], mem[maxn];

// int dfs(int tot) {
// 	if (mem[tot]) return mem[tot];
// 	if (tot == n) return 0;
// 	int ans = INF;
// 	for (int i = tot + 1; i <= n; ++i)
// 		if (abs(abs((two[i]-two[tot]))-abs(one[i]-one[tot]))<=m||!(one[i]-one[tot])||!(two[i]-two[tot])) ans = min(ans, dfs(i) + 1);
// 	return mem[tot] = ans;
// }

// int main() {
// 	// freopen("D:\\VSCODE\\DataTest\\P1564_4.in", "r", stdin);
// 	// freopen("D:\\VSCODE\\DataTest\\data.out.txt", "w", stdout);
// 	cin >> n >> m;
// 	for (int i = 1; i <= n; ++i) {
// 		cin >> arry[i]; 
// 		if (arry[i] == 1) { one[i] = one[i-1] + 1; two[i] = two[i-1]; }
// 		else if (arry[i] == 2) { two[i] = two[i-1] + 1; one[i] = one[i-1]; }

// 	}
// 	int ans = dfs(0);
// 	cout << ans << endl;
// 	return 0;
// }

#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<":"<<x<<endl
using namespace std;

const int maxn =3005;
const int INF = 0x4f4f4f4f;
int n ,m, a, one[maxn], two[maxn], dp[maxn];

int main() {
	for (int i = 0; i < maxn; ++i) dp[i] = maxn;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a; 
		if (a == 1) { one[i] = one[i-1] + 1; two[i] = two[i-1]; }
		else if (a == 2) { two[i] = two[i-1] + 1; one[i] = one[i-1]; }

	}
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j)
			if (abs(abs((two[i]-two[j]))-abs(one[i]-one[j]))<=m||!(one[i]-one[j])||!(two[i]-two[j])) dp[i] = min(dp[j] + 1, dp[i]);
	}
	cout << dp[n] << endl;
	return 0;
}