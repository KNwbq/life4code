#include<bits/stdc++.h>
#define LL long long
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define pii pair<int, int>
#define ms(x, a) memset(x, a, sizeof(x))
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

void debug() {
    cerr << endl;
}
 
template<typename Head, typename... Tail>
void debug(Head H, Tail... T) {
    cerr << " " << H;
    debug(T...);
}
 
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
const int maxn = 105;
const int maxx = 1000020;
int dp[maxn][maxx];

int main() {
	int n, x, a, b;
	ms(dp, 0);
	cin >> n >> x;

	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		if (i == 0) {
			dp[i][a] = 1;
			dp[i][b] = 1;
			continue;
		}
		for (int j = 10000; j > 0; --j) {
			if (j-a > 0) dp[i][j] = dp[i][j] || dp[i-1][j-a];
			if (j-b > 0) dp[i][j] = dp[i][j] || dp[i-1][j-b];
		}
	}

	cout << (dp[n-1][x] == 1? "Yes": "No");

    return 0;
}