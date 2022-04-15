#include<bits/stdc++.h>
#define LL long long
#define MP make_pair
#define PB push_back
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

const int maxn = 55;
int arry[maxn][maxn], h, w;
bool flag = true;

int main() {
	cin >> h >> w;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			cin >> arry[i][j];
	
	for (int i1 = 0; i1 < h; ++i1)
		for (int i2 = i1 + 1; i2 < h; ++i2)
			for (int j1 = 0; j1 < w; ++j1)
				for (int j2 = j1 + 1; j2 < w; ++j2)
					if (arry[i1][j1] + arry[i2][j2] > arry[i2][j1] + arry[i1][j2]) { cout << "No"; return 0; }
	cout << "Yes";	
	return 0;
}