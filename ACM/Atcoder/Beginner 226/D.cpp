#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
 
const int _ = 5, maxn = 500;
int n;
using pp = pair<int, int>;
pp p[maxn+_];
set<pp> S;
 
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d%d", &p[i].X, &p[i].Y);
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j) {
			int g = __gcd(abs(p[i].X-p[j].X), abs(p[i].Y-p[j].Y));
			int a = (p[i].X-p[j].X), b = (p[i].Y-p[j].Y);
			if (g == 0) {
				if (a) a /= abs(a);
				if (b) b /= abs(b);
			}
			else {
				a /= g;
				b /= g;
			}
			S.insert(pp(a, b));
			S.insert(pp(-a, -b));
		}
	cout << S.size();
	return 0;
}