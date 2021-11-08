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

int dp[1005][10005], a[1005], b[1005], c[1005], T, P, n;
const int inf = 0x4f4f4f4f;

void init() {
    for (int i = 0; i < 1005; ++i)
        for (int j = 0; j < 10005; ++j)
            dp[i][j] = inf;
    dp[1][0] = 0;
}

int main() {
    read(T);
    while (T--) {
        init();
        read(n); read(P);
        for (int i = 1; i <= n; ++i) read(a[i]);
        for (int i = 1; i <= n; ++i) read(b[i]);
        for (int i = 1; i <= n; ++i) read(c[i]);

        for (int i = a[1]; i <= b[1]; ++i) dp[1][i] = min(c[1], dp[1][i]); 
        for (int i = 2; i <= n; ++i) {
            deque<int> mq;
            deque<int> id;
            for (int p = 0; p <= P; ++p) {
                if (p < a[i]) { dp[i][p] = dp[i-1][p]; continue; } 
                while (mq.size() > 0 && dp[i-1][p-a[i]] <= mq.back()) { mq.pop_back(); id.pop_back(); }
                while (id.size() > 0 && p - id.front() > b[i]) { id.pop_front(); mq.pop_front(); }
                mq.push_back(dp[i-1][p-a[i]]); id.push_back(p-a[i]);
                dp[i][p] = min(dp[i-1][p], mq.front() + c[i]);
            }        
        }
        if (dp[n][P] != inf)print(dp[n][P], '\n');
        else cout << "IMPOSSIBLE!!!\n";
    }
    return 0;
}