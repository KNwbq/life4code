#include<iostream>
#include<string>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 100;
int cnt[maxn][maxn];

void dp(string s)
{
    int len = s.length();
    cnt[1][(s[0]-'0')%3] = 1;
    for (int i = 1; i < len; ++i) {
        cnt[i+1][(s[i]-'0')%3] = (cnt[i+1][(s[i]-'0')%3]+1)%mod;
        for (int r = 0; r <= 2; ++r) {
            cnt[i+1][(r+s[i]-'0')%3] = (cnt[i+1][(r+s[i]-'0')%3] + cnt[i][r])%mod;
            cnt[i+1][r] = (cnt[i+1][r]+cnt[i][r])%mod;
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    for (int i = 0; i < maxn; ++i)
        for (int j = 0; j < maxn; ++j)
            cnt[i][j] = 0;
    dp(s);
    cout << cnt[s.length()][0];
    return 0;
}