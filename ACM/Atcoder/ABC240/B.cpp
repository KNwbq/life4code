#include<iostream>
#include<set>
using namespace std;

const int maxn = 1050;
set<int> aset;

int main() {
	int n, a;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		aset.insert(a);
	}

	cout << aset.size();
	return 0;
}