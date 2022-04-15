#include<bits/stdc++.h>
#define LL long long
#define MP make_pair
#define PB push_back
#define X first
#define pii pair<int, int>
#define ms(x, a) memset(x, a, sizeof(x))
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

void debug() {
    cerr << endl;
}
 
template<typename Head, typename... Tail>
void debug(Head H, Tail... T) {
    cerr << " " << H;
    debug(T...);
}
 
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)

const int maxn = 2e5 + 10;
vector<int> to[maxn];
vector<int> ans;
priority_queue<int, vector<int>, greater<int> > q;
int deg[maxn];

int main() {
	int n, m, a, b;
    read(n); read(m);
    for (int i = 0; i < m; ++i) {
        read(a); read(b);
        to[a].PB(b); ++deg[b];
    }
    for (int i = 1; i <= n; ++i) 
        if (deg[i] == 0) q.push(i);
    
    while (!q.empty()) {
        int a = q.top(); q.pop();
        ans.PB(a);
        for (auto it: to[a]) {
            --deg[it];
            if (deg[it] == 0) q.push(it);
        }
    }
    if (ans.size() != n) cout << -1;
    else for (auto it: ans) print(it, ' ');
    return 0;
}