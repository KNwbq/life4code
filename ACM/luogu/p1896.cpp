#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<":"<<x<<endl
using namespace std;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int maxn = 100;
const int maxm = 2000;
long long dp[maxn][maxm][maxn];
long long sit[maxm];
long long gs[maxm];
int n, k, cnt=0;

void dfs(int he, int sum, int node) {
	if(node >= n) {
		gs[cnt] = sum;
		sit[cnt++] = he;
		return;
	}
	dfs(he, sum, node+1);
	dfs(he + (1<<node), sum+1, node+2);
}

int main() {
	read(n); read(k);
	dfs(0, 0, 0);
	for (int i = 0; i < cnt; ++i) dp[1][i][gs[i]] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < cnt; ++j) {
			for (int kk = 0; kk < cnt; ++kk) {
				if ((sit[j]&sit[kk]) == 0 && ((sit[j]<<1) & sit[kk]) == 0 && (sit[j] & (sit[kk]<<1)) == 0) 
					for (int s = k; s >= gs[j]; --s) dp[i][j][s] += dp[i-1][kk][s-gs[j]];
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < cnt; ++i) ans += dp[n][i][k];
	print(ans);
	return 0;
}