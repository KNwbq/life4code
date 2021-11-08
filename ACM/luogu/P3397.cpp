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

const int maxn = 1020;
int carpet[maxn][maxn];

int main() {
    int n, m, x1, y1, x2, y2;
    cin >> n >> m;
    for (int ii = 0; ii < m; ++ii) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i <= x2; ++i)  {
            ++carpet[i][y1]; --carpet[i][y2+1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        int cur = carpet[i][1];
        print(cur);
        for (int j = 2; j <= n; ++j) {
            putchar(' ');
            cur += carpet[i][j];
            print(cur);
        }
        putchar('\n');
    }
    return 0;
}