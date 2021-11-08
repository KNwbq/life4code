#include<iostream>
#include<algorithm>
#define endl '\n'


using namespace std;
const int maxn = 1e6 + 10;
long long arry[maxn];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, s, cnt, p; cin >> n >> s;
	for (int i = 1; i <= n; ++i) cin >> arry[i];
	sort(arry + 1, arry + n + 1, greater<long long>());
	for (int i = 1; i <= n; ++i) arry[i] += arry[i-1];
	for (int i = 1; i <= n; ++i) {
		cnt = 0; p = i;
		while (p <= n && arry[p] - arry[p - i] > s) { ++cnt; p += i; } 
		if (p > n) cout << arry[p - i] - s * cnt + max(0ll, arry[n] - arry[p - i] - s) << endl;
		else cout << arry[p - i] - s * cnt << endl;
	}
	return 0;
}