#include<bits/stdc++.h>
using namespace std;
const int maxb = 1e5 + 10;

set<int> A;
set<pair<int, long long> > B;
int q;

const int n = 1<<20;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < n; ++i) A.insert(i);
	cin >> q;
	while (q--) {
		int t;
		long long x;
		cin >> t >> x;
		if (t == 1) {
			auto it = A.upper_bound(x%n-1);
			if (it == A.end()) it = A.begin();
			B.insert(make_pair(*it, x));
			A.erase(it);
		}
		else {
			auto it = B.upper_bound(make_pair(x%n, -1));
			if (it == B.end() || it->first != x%n) cout << "-1\n";
			else cout << it->second << "\n";
		}
	}
	return 0;
}