#include<bits/stdc++.h>
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

const int maxn = 100005;
const int mod = 998244353;
long long a[maxn], b[maxn], c[maxn], cnta, cntb;
int n;

int main() {
    read(n);
    for (int i = 0; i < n; ++i) { read(a[i]); cnta += a[i]; }
    for (int i = 0; i < n; ++i) { read(b[i]); cntb += b[i]; }
    c[1] = (a[0]*(cntb-b[0]-b[1])%mod+b[0]*(cnta-a[0]-a[1])%mod+a[0]*b[0]%mod)%mod;
    c[2] = (a[0]*b[1]%mod+a[1]*b[0]%mod)%mod;
    c[0] = ((cntb-b[0])%mod*(cnta-a[0])%mod)%mod;
    for (int i = 0; i < n; ++i)
        print(c[i], ' ');
}