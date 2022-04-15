#include<bits/stdc++.h>
#define LL long long
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define ms(x, a) memset(x, a, sizeof(x))
#define pii pair<int, int>
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

const int maxn = 2e5 + 10;
int h, w, n, a;
int dp[maxn], r[maxn], c[maxn], rmax[maxn], cmax[maxn];

map<int, vector<int>, greater<int> > grid;

int main() {
	ms(dp, 0);
	ms(rmax, 0);
	ms(cmax, 0);
	read(h); read(w); read(n);
	for (int i = 0; i < n; ++i) {
		read(r[i]); read(c[i]); read(a);
		grid[a].PB(i);
	}
	for (auto it: grid)	{
		for (auto id: it.Y) {
			dp[id] = max(dp[id], rmax[r[id]]);
			dp[id] = max(dp[id], cmax[c[id]]);
		}
		for (auto id: it.Y) {
			rmax[r[id]] = max(rmax[r[id]], dp[id] + 1);
			cmax[c[id]] = max(cmax[c[id]], dp[id] + 1);
		}
	}
	for (int i = 0; i < n; ++i) print(dp[i], '\n');
    return 0;
}