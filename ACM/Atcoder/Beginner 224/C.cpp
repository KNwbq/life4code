#include<bits/stdc++.h>
#define LL long long
#define MP make_pair
#define PB push_back
#define X first
#define Y second
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

vector<pair<LL, LL> > points;
LL x, y, n, Size, ans = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		points.push_back(MP(x, y));
	}
	Size = points.size();
	for (int i = 0; i < Size; ++i)
		for (int j = i + 1; j < Size; ++j)
			for (int z = j + 1; z < Size; ++z) {
				LL x1 = points[j].X - points[i].X;
				LL y1 = points[j].Y - points[i].Y;
				LL x2 = points[z].X - points[j].X;
				LL y2 = points[z].Y - points[j].Y;
				if (y1 * x2 - y2 * x1) ans += 1;
			}
	cout << ans;
	return 0;
}