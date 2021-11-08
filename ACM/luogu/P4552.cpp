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
LL arry[maxn], diff[maxn], cnt = 0;

int main() {
    LL n, pos = 0, neg = 0; read(n);
    memset(arry, 0, sizeof(arry));
    memset(diff, 0, sizeof(diff));
    for (int i = 1; i <= n; ++i) 
        read(arry[i]);
    for (int i = 1; i <= n; ++i)    
        diff[i] = arry[i] - arry[i-1];    
    for (int i = 2; i <= n; ++i) {
        if (diff[i] > 0) pos += diff[i];
        else neg -= diff[i];
    }
    LL Diff = arry[1] - arry[n];
    if (Diff >= 0) {
        print(Diff + pos, '\n');
        print(Diff + 1);
    }
    else {
        print(neg - Diff, '\n');
        print(1 - Diff);
    }
    return 0;
}