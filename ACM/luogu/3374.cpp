#include<bits/stdc++.h>
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

const int maxn = 500020;
int c[maxn], n, m, buffer, ope, a, b;

int lowbit(int x) {
	return x&(-x);
}

void update(int x, int k) {
	while (x <= n) {
		c[x] += k;
		x += lowbit(x);
	}
}

int getsum(int x) {
	int cnt = 0;
	while (x >= 1) {
		cnt += c[x];
		x -= lowbit(x);
	}
	return cnt;
}

int main() {
	read(n); read(m);
	for (int i = 1; i <= n; ++i) {
		read(buffer);
		update(i, buffer);
	}
	for (int i = 0; i < m; ++i) {
		read(ope); read(a); read(b);
		if (ope == 1) update(a, b);
		else {
			cout << getsum(b) - getsum(a-1) << endl;
		}
	}
}