#include<bits/stdc++.h>
#define LL long long
#define MP make_pair
#define PB push_back
#define X first
#define Y second
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

const LL maxn = 2e5 + 10, mod = 998244353;
LL ans = 0, n, arry[maxn];
string s;

LL qpow(LL a, LL b) {
	LL res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int main() {
	cin >> s;
	n = s.length();
	LL inv4 = qpow(4, mod - 2);
	for (int i = n - 1; i >= 0; --i) arry[n - 1 - i] = (LL)(s[i] - '0');
	LL wbq = qpow(2, n-1);
	for (int i = 0; i < n; ++i)	{
		ans = (ans + arry[i] * (wbq * (mod+1)/2%mod * (((qpow(5, i) - 1) * inv4) % mod)%mod + qpow(2, n-1-i)*qpow(10, i)%mod)%mod) % mod;
	}
	print(ans, '\n');
    return 0;
}