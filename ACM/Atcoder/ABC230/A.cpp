#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	if (n >= 42) ++n;
	cout << "AGC";
	if (n < 10) cout << "00";
	else cout << "0";
	cout << n;
	return 0;
}