#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<":"<<x<<endl
#define LL long long
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

const int maxn = 100020;
LL d[maxn << 2], b[maxn << 2], z[maxn << 2];
LL n, m, buffer;
LL oper, a, bb, c, pp;

void pushdown(int l, int r, int p) {
	int mid = (l + r) >> 1;
	d[p<<1] = ((d[p<<1] * z[p]) % pp + (mid - l + 1)*b[p]) % pp;
	d[(p<<1)|1] = ((d[(p<<1)|1] * z[p]) % pp + (r - mid)*b[p]) % pp;
	b[p<<1] = (b[p<<1] * z[p] + b[p]) % pp; b[(p<<1)|1] = (b[(p<<1)|1] * z[p] + b[p]) % pp; 
	z[p<<1] = (z[p<<1] * z[p]) % pp; z[(p<<1)|1] = (z[(p<<1)|1] * z[p]) % pp;
	b[p] = 0; z[p] = 1;
}

void update(int l, int r, int c, int s, int t, int p) {
	if (l <= s && t <= r) {
		d[p] = (d[p] + (t - s + 1) * c) % pp;
		b[p] = (b[p] + c) % pp;
		return; 
	}
	int mid = (s+t) >> 1;
	if ((b[p] != 0 || z[p] != 1) && s != t) pushdown(s, t, p); 
	if (l <= mid) update(l, r, c, s, mid, p<<1);
	if (r > mid) update(l, r, c, mid + 1, t, (p<<1)|1);
	d[p] = (d[p<<1] + d[(p<<1)|1]) % pp;
}

void update2(int l, int r, int c, int s, int t, int p) {
	if (l <= s && t <= r) {
		d[p] = (d[p] * c)%pp;
		z[p] = (z[p] * c) % pp; b[p] = (b[p] * c) % pp;
		return; 
	}
	int mid = (s+t) >> 1;
	if ((b[p] != 0 || z[p] != 1) && s != t) pushdown(s, t, p); 
	if (l <= mid) update2(l, r, c, s, mid, p<<1);
	if (r > mid) update2(l, r, c, mid + 1, t, (p<<1)|1);
	d[p] = (d[p<<1] + d[(p<<1)|1]) % pp;
}

LL getsum(int l, int r, int p, int s, int t) {
	if (l <= s && t <= r) return d[p]%pp;
	int mid = (s+t) >> 1;
	if ((b[p] != 0 || z[p] != 1) && s != t) pushdown(s, t, p); 
	LL sum = 0;
	if (l <= mid) sum = (sum + getsum(l, r, p<<1, s, mid)) % pp;
	if (r > mid) sum = (sum + getsum(l, r, (p<<1)|1, mid+1, t)) % pp;
	return sum;
}

int main() {
	// freopen("D:\\VSCODE\\DataTest\\P3373_2.in", "r", stdin);
	// freopen("D:\\VSCODE\\DataTest\\data.out.txt", "w", stdout);
	read(n); read(m); read(pp);	
	for (int i = 0; i < 4*maxn; ++i) z[i] = 1;
	for (int i = 1; i <= n; ++i) { read(buffer); update(i, i, buffer, 1, n, 1); }
	for (int i = 0; i < m; ++i) {
		read(oper);
		switch (oper)
		{
		case 1:
			read(a); read(bb); read(c);
			update2(a, bb, c, 1, n, 1);
			break;
		case 2:
			read(a); read(bb); read(c);
			update(a, bb, c, 1, n, 1);
			break;
		case 3:
			read(a); read(bb);
			print(getsum(a, bb, 1, 1, n), '\n');	
		}
	}
}