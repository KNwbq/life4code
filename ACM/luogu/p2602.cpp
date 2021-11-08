#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 20;
ll a[maxn], dp[maxn];
ll powL[20], now[20];

ll dfs(int pos, int lead, int limit, int digit) {
    ll ans = 0;
    if (pos == 0) return 0;
    if (dp[pos] != -1 && !limit && !lead) return dp[pos];
    ll up = ((limit == 1) ? a[pos] : 9);
    for (int i = 0; i <= up; ++i) {
        if (lead && !i) ans += dfs(pos-1, 1, limit && (i == up), digit);
        else if (limit && i == digit && i == up) ans +=  now[pos-1] + 1 + dfs(pos-1, 0, 1, digit);
        else if (i == digit) ans += powL[pos-1] + dfs(pos-1, 0, 0, digit);
        else ans += dfs(pos-1, 0, limit && (i == up), digit);
    }
    if (!limit && !lead) dp[pos] = ans;
    return ans;
}

ll solve(ll x, int i) {
    int len = 0;
    memset(dp, -1, sizeof(dp));
    while (x) { a[++len] = x % 10, x /= 10; now[len] = a[len] * powL[len-1] + now[len-1]; }

    return dfs(len, 1, 1, i);
}

int main() {
    ll aa, bb; cin >> aa >> bb;
    powL[0] = 1;
    for (int i = 1; i <= 12; ++i) powL[i] = powL[i-1] * 10LL;
    for (int i = 0; i <= 9; ++i) cout << solve(bb, i) - solve(aa-1, i) << ' ';
    return 0;
}
