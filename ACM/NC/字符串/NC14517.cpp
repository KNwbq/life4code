#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 20;

int manacher (string s)
{
    int index = 0, len = s.length();
    int l = 2 * len + 1, ans = -1;
    char* ms = new char[l];
    int* pArr = new int[l];
    for (int i = 0; i < l; ++i)
        ms[i] = i & 1 ? s[index++] : '#';
    int r = -1, c = -1;
    for (int i = 0; i < l; ++i) {
        pArr[i] = r > i ?  min(r - i, pArr[2 * c - i]) : 1;
        while (i + pArr[i] < l && i - pArr[i] > -1) 
            { if (ms[i + pArr[i]] == ms[i - pArr[i]]) ++pArr[i]; else break; }
        ans = max(ans, pArr[i]);
        if (i + pArr[i] > r) {
            r = i + pArr[i]; c = i;
        }
    }
    delete [] ms; delete [] pArr; 
    return ans - 1;
}

int main()
{
    ios::sync_with_stdio(0);
    string s;
    while (cin >> s) {
        cout << manacher(s) << endl;
    }
}