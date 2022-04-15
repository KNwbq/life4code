#include<bits/stdc++.h>
using namespace std;
const int modu = 998244353, _ = 5, maxn = 1000;
using LL = long long;

LL n, L, R;

LL f(LL x) {
	if (x == 0) return 0;
	int len = 0;
	for (len = 0; (1ll << len) <= x; len++);
	len--;
	LL res = 0;
	bool flag = 0;
	for (int i = len; i >= 0; --i)
		if (!flag) {
			if (x >> i & 1) {
				if (n >> i & 1) res += x - (x >> i << i) + 1;
				flag = 1;
			}
		}
		else {
			if (n >> i & 1) res += 1ll << i;
		}
	return res;
	// LL res = 0;
	// for (LL i = n; i > 0; i -= i & -i)
	// 	if ((i & -i) <= x) res += (i & -i) - 1;
	// return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> L >> R;
	cout << f(R) - f(L-1);
	return 0;
}