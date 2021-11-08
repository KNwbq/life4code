#include<iostream>
#include<vector>
#include <set>
using namespace std;

const int maxn = 2e5 + 10;
set<vector<int>> S;

int main() {
	int n, l, a; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> l;
		vector<int> aa;
		for (int i = 0; i < l; ++i) {
			cin >> a; aa.push_back(a);
		}
		S.insert(aa);
	}
	cout << S.size();
	return 0;
}