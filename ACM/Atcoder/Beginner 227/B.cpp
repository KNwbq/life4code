#include<bits/stdc++.h>
using namespace std;

set<int> ta;

int main() {

	for (int a = 1; a <= 1000; ++a)
		for (int b = 1; b <= 1000; ++b)
			ta.insert(4*a*b+3*a+3*b);
	
	int n; cin >> n;
	int ans = 0, s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		if (ta.count(s) == 0) ans += 1;
	}
	cout << ans;
	return 0;
}