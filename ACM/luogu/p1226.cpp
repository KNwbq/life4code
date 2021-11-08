#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<":"<<x<<endl
using namespace std;


long long binbow(long long a, long long b, long long c) {
	if (b == 0 && c == 1) return 0;
	long long res = 1;
	while (b) {
		if (b & 1) res = (res * a) % c;
		b >>= 1;
		// debug(b);
		a = (a * a) % c;
	}
	return res;
}

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	cout << a << '^' << b << " mod " << c << '=' << binbow(a, b, c) << endl;
	return 0;
}