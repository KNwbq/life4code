#include<bits/stdc++.h>
using namespace std;
const int maxb = 1e5 + 10;
int arry[maxb];
int cnt[1205];

int main() {
	int n, k; cin >> n >> k;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++i) {
		int a, b, c; cin >> a >> b >> c;
		arry[i] = a + b + c;
		cnt[arry[i]]++;
	}
	for (int i = 1200; i >= 0; --i)
		cnt[i] += cnt[i+1];
	for (int i = 0; i < n; ++i) {
		if (cnt[arry[i]+301] >= k) cout << "No" << '\n';
		else cout << "Yes" << '\n';
	}
	return 0;
}