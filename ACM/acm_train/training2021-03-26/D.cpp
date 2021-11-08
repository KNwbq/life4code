#include<bits/stdc++.h>
typedef unsigned long long ull;
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
 
const ull maxn = 1e7+20, base = 131;
ull ha[maxn], rha[maxn], pw[maxn];
int n, D, ans = 0;
char s[maxn];

ull geth(int l, int r) {
    return ha[r]-ha[l-1]*pw[r-l+1];
}

ull rgeth(int l, int r) {
    return rha[l]-rha[r+1]*pw[r-l+1];
}

bool check(int l, int r) {
    return geth(l, r) == rgeth(l, r);
}

int main() {
    //freopen("D:\\code\\VSCODE\\DataTest\\data.in.txt", "r", stdin);
    //freopen("D:\\code\\VSCODE\\DataTest\\data.out.txt", "w", stdout);

    read(n); read(D); scanf("%s", s+1);
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = pw[i-1]*base;
        ha[i] = ha[i-1]*base+s[i];
    }
    for (int i = n; i >= 1; --i)
        rha[i] = rha[i+1]*base+s[i];
    for (int i = 1, j = 1; i <= n; i = j + 1) {
        j = i + D - 2; 
        while (j < n && check(j + 1 - D + 1, j + 1)) ++j;
        ++ans;
    }
    print(ans);
    return 0;
}