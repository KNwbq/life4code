#include<iostream>
#include<algorithm>
#include<cmath>
#define debug(x) cerr<<#x<<":"<<x<<endl
using namespace std;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}
 
const double pi = acos(-1);
const double eps = 1e-8;

double cal(double x, double y, double l, double w, double theta) {
	return (y*sin(theta) - w + x*cos(theta)) / (sin(theta)*cos(theta));
}

int main() {
	double x, y, l, w, le, ri, lmid, rmid;
	while (cin >> x >> y >> l >> w) {
		le = 0; ri = pi/2;
		while (abs(le - ri) > eps) {
			lmid = (ri + le)/2;
			rmid = (ri + lmid)/2; 
			if (cal(x, y, l, w, lmid) > cal(x, y, l, w, rmid)) le = lmid;
			else ri = rmid;
		}
		if (cal(x, y, l, w, le) - l > eps) cout << "yes\n";
		else cout << "no\n";
	}
}