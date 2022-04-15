#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k, a; cin >> n >> k >> a;
	cout << (a + k - 2) % n + 1;
	return 0;
}