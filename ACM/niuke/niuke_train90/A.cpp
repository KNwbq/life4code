#include<iostream>
using namespace std;

int main() {
	int n, a, b, c, ans = 0;
	bool flag = false;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b >> c; ans += c;
		if (c != 1) flag = true;
	}
	if (flag) cout << ans + 1;
	else cout << -1;
	return 0;
}