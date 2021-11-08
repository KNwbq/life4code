#include<iostream>
using namespace std;
const int maxn = 1020;
int friends[maxn], h[maxn];

int find(int x) {
    int r = x;
    while (r != friends[r]) r = friends[r];
    int j;
    while (x != r) {
        j = friends[x];
        friends[x] = r;
        x = j;
    }
    return r;
}

void union_(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return;
    if (h[x] >= h[y]) { friends[y] = x; ++h[x]; }
    else { friends[x] = y; ++h[y]; }
}

int main() {
    ios::sync_with_stdio(0);
    int T; cin >> T;
    int n, m, x, y, cnt;
    while (T--) {
        cnt = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) { friends[i] = i; h[i] = 2; }
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            union_(x, y);
        }
        for (int i = 1; i <= n; ++i) {
            if (i == friends[i]) ++cnt;
        }
        cout << cnt << endl;
    }
    return 0;
}