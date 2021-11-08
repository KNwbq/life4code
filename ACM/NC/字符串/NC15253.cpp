#include<iostream>
#include<cstring>
#include<unordered_map>
#define ULL unsigned long long
using namespace std;

const int maxn = 1e7 + 10;
unordered_map<ULL, bool> def;
ULL Hash[maxn << 1];
ULL p = 131, poww = 1;

int main()
{
    ios::sync_with_stdio(0);
    string T1, T2, T3; cin >> T1; T2 = T1 + T1;
    Hash[0] = T2[0] - 'a';
    int n, ans, len = T1.length();
    for (int i = 0; i < len; ++i) poww *= p;
    for (int i = 1; i < 2 * len; ++i) { 
        Hash[i] = Hash[i-1] * p + T2[i] - 'a'; 
        if (i >= len) {
            ULL buff = Hash[i] - Hash[i-len] * poww;
            def.insert(pair<ULL, bool> (buff, 1));
        }
    }
    cin >> n;
    while (n--)
    {
        ans = 0;
        cin >> T3;
        if (T3.length() < len) { cout << 0 << endl; continue; }
        Hash[0] = T3[0] - 'a';
        for (int i = 1; i < T3.length(); ++i) {
            Hash[i] = Hash[i-1] * p + T3[i] - 'a';
            if (i >= len && def[Hash[i] - Hash[i-len] * poww]) ++ans;
        }
        if (def[Hash[len-1]]) ++ans;
        cout << ans << endl;
    }
}