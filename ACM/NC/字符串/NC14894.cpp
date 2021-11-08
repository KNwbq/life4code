#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 20;
int pa[maxn];
int pb[maxn];
char ca[maxn];
char cb[maxn];
int len;
string a, b;

void manacher (string s, int* pArr, char* ms)
{
    int index = 0;
    int l = 2 * len + 1;
    for (int i = 0; i < l; ++i)
        ms[i] = i & 1 ? s[index++] : '#';
    int r = -1, c = -1;
    for (int i = 0; i < l; ++i) {
        pArr[i] = r > i ?  min(r - i, pArr[2 * c - i]) : 1;
        while (i + pArr[i] < l && i - pArr[i] > -1) 
            { if (ms[i + pArr[i]] == ms[i - pArr[i]]) ++pArr[i]; else break; }
        
        if (i + pArr[i] > r) {
            r = i + pArr[i]; c = i;
        }
    }
    return;
}

int solve ()
{
    int ans = -1; int l = 2 * len + 1;
    for (int i = 2; i < l; ++i) {
        int buff = max(pa[i], pb[i - 2]);
        while (i - buff > -1 && i - 2 + buff < l && ca[i - buff] == cb[i - 2 + buff]) ++buff;
        ans = max(ans, buff);
    }
    return ans - 1;
}


int main()
{
    ios::sync_with_stdio(0);
    cin >> len >> a >> b;
    manacher(a, pa, ca); manacher(b, pb, cb);
    cout << solve();
}