#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	double a, b, c, x; cin >> a >> b >> c >> x;
	double ans;
	if (x <= a) ans = 1;
	else if (x > b) ans = 0;
	else ans = c / (b - a);
	cout << fixed << setprecision(12) << ans;
	return 0;
}