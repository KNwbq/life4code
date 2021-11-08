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


const int maxn = 500020;
LL arry[maxn];
LL d[maxn << 2], b[maxn << 2];
LL n, m, buffer;
int oper, a, bb, c;

void update(int l, int r, int c, int s, int t, int p) {
	if (l <= s && t <= r) {
		d[p] += (t - s + 1) * c;
		b[p] += c;
		return; 
	}
	int mid = (s+t) >> 1;
	if (b[p] && s != t) {
		d[p<<1] += (mid - s + 1)*b[p];
		d[(p<<1)|1] += (t - mid)*b[p];
		b[(p<<1)] += b[p]; b[(p<<1)|1] += b[p];
		b[p] = 0;
	}
	if (l <= mid) update(l, r, c, s, mid, (p<<1));
	if (r > mid) update(l, r, c, mid + 1, t, (p<<1)|1);
	d[p] = d[(p<<1)] + d[(p<<1)|1];
}

LL getsum(int l, int r, int p, int s, int t) {
	if (l <= s && t <= r) return d[p];
	int mid = (s+t) >> 1;
	if (b[p] && s != t) {
		d[(p<<1)] += (mid - s + 1)*b[p];
		d[(p<<1)|1] += (t - mid)*b[p];
		b[(p<<1)] += b[p]; b[(p<<1)|1] += b[p];
		b[p] = 0;
	}
	LL sum = 0;
	if (l <= mid) sum += getsum(l, r, p<<1, s, mid);
	if (r > mid) sum += getsum(l, r, (p<<1)|1, mid+1, t);
	return sum;
}

void build(int l, int r, int p) {
	if (l == r) {
		d[p] = arry[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, p<<1);
	build(mid+1, r, (p<<1)|1);
	d[p] = d[p<<1] + d[(p<<1)|1];
}

int main() {
	read(n); read(m);
	for (int i = 1; i <= n; ++i) { read(buffer); update(i, i, buffer, 1, n, 1); }
	for (int i = 0; i < m; ++i) {
		read(oper);
		switch (oper)
		{
		case 1:
			read(a); read(bb); read(c);
			update(a, bb, c, 1, n, 1);
			break;
		case 2:
			read(a); read(bb);
			print(getsum(a, bb, 1, 1, n), '\n');	
		default:
			break;
		}
	}
}