#include<bits/stdc++.h>
using namespace std;
using LL = long long;

const int maxn = 2e5 + 10;
LL A[maxn];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	LL n, k, ans; cin >> n >> k;
	for (LL i = 0; i < n; ++i) cin >> A[i];
	LL lf = 0, rf = 1e18;
	while (lf != rf) {
		ans = (lf + rf) / 2 + 1;

		LL buff = 0;
		for (LL i = 0; i < n; ++i) 
			buff += min(ans, A[i]);
		
		if (buff / k >= ans)
			lf = ans;
		else rf = ans - 1;
	}
	cout << lf;
	return 0;
}