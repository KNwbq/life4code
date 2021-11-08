#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[11][11], b[11][11], n, m, sum;
const int maxn = (1 << 20) + 5;
ll dp[2][maxn];
int vis[2][maxn];

ll dfs(int p, int state) {
    int xx=0, yy=n;
    ll ans; (p == 1) ? ans = -0x4f4f4f4f: ans = 0x4f4f4f4f;
//    cout << p << ' ' << state << ' ' << dp[p][state];
    if (vis[p][state] != 0) return dp[p][state];
    vis[p][state] = 1;
    if (state == ((1 << sum) - (1 << m))) return 0;
    for (int i = 0; i < sum-1; ++i) {
        ((state & (1 << i)) == 0) ? xx++ : yy--;
//        cout << xx << ' ' << yy << endl;
        if (state & (1 << i) && !(state & (1 << (i + 1)))) {
//            cout << state << ' ' << (state ^ (1 << i) ^ (1 << (i + 1))) << ' ' << xx << ' ' << yy << endl;
            if (p == 1) ans = max(ans, dfs(p ^ 1, state ^ (1 << i) ^ (1 << (i + 1))) + a[yy][xx]);
            else ans = min(ans, dfs(p ^ 1, state ^ (1 << i) ^ (1 << (i + 1))) - b[yy][xx]);
        }
    }
    dp[p][state] = ans;
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> b[i][j];
    sum = m + n;
    cout << dfs(1, (1 << n) - 1);
    return 0;
}