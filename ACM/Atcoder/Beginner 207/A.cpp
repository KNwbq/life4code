#include<bits/stdc++.h>
using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	long long ans = a + b;
	ans = max(ans, a+c);
	ans = max(ans, b+c);
	cout << ans << endl;
	return 0;
}