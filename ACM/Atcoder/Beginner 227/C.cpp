#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
	LL ans = 0;
	LL n; cin >> n;
	for (LL a = 1; a <= min(n, LL(10001)); ++a) {
		for (LL b = a; a * b * b <= n; ++b) {
			ans += (LL(n / (a*b)) - b + 1);
		}
	}
	cout << ans;
	return 0;
}