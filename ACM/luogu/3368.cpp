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
int c[maxn], ope, a, b, cc, n, m;

int lowbit(int x) {
	return x&(-x);
}

void update(int i, int k) {
	while (i <= n) {
		c[i] += k;
		i += lowbit(i);
	}
}

int getsum(int k) {
	int cnt = 0;
	while (k >= 1) {
		cnt += c[k];
		k -= lowbit(k);
	}
	return cnt;
}

int main() {
	read(n); read(m);
	for (int i = 1; i <= n; ++i) {
		read(a);
		if (i == 1) { update(i, a); cc = a; }
		else { update(i, a - cc); cc = a; }
	}
	for (int i = 0; i < m; ++i) {
		read(ope);
		if (ope == 1) {
			read(a); read(b); read(cc);
			update(a, cc); update(b+1, -cc);
		}
		else {
			read(a);
			print(getsum(a), '\n');
		}
	}
}