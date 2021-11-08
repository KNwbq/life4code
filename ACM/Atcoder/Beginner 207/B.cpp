#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
const double eps = 1e-8;
 
int main() {
	long double a, b, c, d;
	cin >> a >> b >> c >> d;
	if (d*c-b < eps) cout << -1;
	else cout << ceil(a/(d*c-b));
	return 0;	
}