#include<iostream>
using namespace std;

int main() {
	int n, l = 0, r = 0x4f4f4f4f, a, b;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		l = max(l, a);
		r = min(r, b);
		if (l <= r) cout << 0 << '\n';
		else cout << int((l - r) / 2. + 0.5) << '\n';
	}
	return 0;
}