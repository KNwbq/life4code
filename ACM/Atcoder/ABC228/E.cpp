#include<bits/stdc++.h>
using namespace std;
const int maxb = 1e5 + 10;

set<int> A;
set<pair<int, long long> > B;
int q;

const int modu = 998244353;
using LL = long long;

LL n, k, m;
LL powmod(LL a, LL b, LL modu) {
	LL res = 1;
	for (a %= modu; b; b >>= 1, a = a * a % modu)
		if (b&1) res = res * a % modu;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> m;
	cout << powmod(m, powmod(k, n, modu-1) + (log(log(modu)) <= log(log(m)) + log(k)*n)*(modu-1), modu);
	return 0;
}