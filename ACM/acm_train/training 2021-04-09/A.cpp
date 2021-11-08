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

const int maxn = 1000200;
int cnt1[maxn], arry[maxn], cnt, n, ans;
char c;
bool flag = false;

int main() {
    while (c = getchar()) {
        if (c == '\n') break;
        if (c == '1') arry[n++] = 1;
        else arry[n++] = 0;
    }
    for (int i = 0; i < n; ++i) {
        if (i+2 < n && arry[i] == 1 && arry[i+1] == 0 && arry[i+2] == 1) flag = true;
    }
    for (int i = 0; i < n; ++i) {
        if (arry[i] == 1) ++cnt;
        else cnt = 0;
        cnt1[i] = cnt;
    }
    
    for (int i = 0; i < n-1; ++i) {
        if (cnt1[i+1] != 0) cnt1[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        if (cnt1[i] != 0) ++ans;
        if (cnt1[i] == 1) flag = true;
    }
    if (flag) ans = max(0, ans-1);
    print(ans);
    return 0;
}