#include<bits/stdc++.h>
#define LL long long
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define pii pair<int, int>
#define ms(x, a) memset(x, a, sizeof(x))
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

void debug() {
    cerr << endl;
}
 
template<typename Head, typename... Tail>
void debug(Head H, Tail... T) {
    cerr << " " << H;
    debug(T...);
}
 
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)

vector<double> F;
vector<int> A;
vector<int> B;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	double ans = 0;
	double a, b, tot=0; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b; A.PB(a); B.PB(b);
		F.PB(a / b); tot += a / b;
	}	
	for (int i = 0; i < n; ++i) {
		double it = F[i];
		if (tot - 2*it >= 1e-16) { tot -= 2*it; ans += A[i]; continue; }
		else {
			ans += (tot / 2) * (LL)B[i];
			break;
		}
	}
	cout << setprecision(15) << ans;
    return 0;
}