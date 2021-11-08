#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iterator>
using namespace std;

const int maxn = 200;
bool f[maxn][maxn];

void init() {
    for (int i = 0; i < maxn; ++i)
        for (int j = 0; j < maxn; ++j) {
            f[i][j] = 0;
        }
}

int main() {
    ios::sync_with_stdio(0);
    init();
    string s, t;
    cin >> s >> t;
    int sl = s.length(), tl = t.length();
    f[0][0] = 1;
    for (int i = 1; i <= sl; ++i)
        for (int j = 1; j <= tl; ++j) {
            if (s[i-1] == t[j-1]) f[i][j] |= f[i-1][j-1];
            if (s[i-1] == ')') {
                int cnt = 1, pos = i-1;
                while (cnt > 0) {
                    if (s[pos-1] == ')') ++cnt;
                    else --cnt;
                    --pos;
                }
                f[i][j] |= f[pos][j];
            }
        }
    if (f[sl][tl]) cout << "Possible";
    else cout << "Impossible";
    return 0;
}