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


const int maxn = 520;
bool s[maxn];
long long minn, maxx, mid, ans, arry[maxn], cnt, cnts;

void init() {
	memset(s, false, sizeof(s));
	minn = 0; maxx = 0; cnt = 0; cnts = 0; 
}

bool check(long long x, int a, int b) {
	long long cnt2 = 0;
	int cntp = 0, i;
	for (i = a - 1; i >= 0; --i) {
		cnt2 += arry[i];
		if (cnt2 > x) {
			cnt2 = arry[i]; ++cntp;
		}	
	}
	if (cntp > b - 1) return false;
	return true;
} 

int main() {
	int cases, a, b;
	read(cases);
	while (cases--) {
		init();
		read(a); read(b);
		for (int i = 0; i < a; ++i) {
			read(arry[i]);
			minn = max(minn, arry[i]);
			maxx += arry[i];
		}
		while (minn < maxx) {
			mid = (minn + maxx) >> 1;
			if (!check(mid, a, b)) minn = mid + 1;
			else {maxx = mid; ans = mid; }
		}

		for (int i = a - 1; i >= 0; --i) {
			cnt += arry[i];
			if (cnt > ans) { ++cnts; s[i] = 1; cnt = arry[i]; }
		}

		for (int i = 0; b - cnts > 1; ++i) {
			if (!s[i]) { s[i] = 1; ++cnts; }
		}

		print(arry[0]); if (s[0]) cout << " /";
		for (int i = 1; i < a; ++i) {
			putchar(' ');
			print(arry[i]);
			if (s[i]) cout << " /";
		}
		putchar('\n');
	}  
	return 0;
}