#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;

namespace FastIO{
    char print_f[105];
    void read() {}
    void readstr() {}
    void print() {putchar('\n');}
    template <typename T, typename... T2>
    inline void read(T &x, T2 &... oth){
        x = 0;
        char ch = getchar();
        ll f = 1;
        while (!isdigit(ch)) {
            if (ch == '-')
                f *= -1;
            ch = getchar();
        }
        while (isdigit(ch)) {
            x = x * 10 + ch - 48;
            ch = getchar();
        }
        x *= f;
        read(oth...);
    }
     
    template <typename T, typename... T2>
    inline void readstr(T &s, T2 &... oth){
        s = "";
        char ch = getchar();
        while (!isalpha(ch)) {
            ch = getchar();
        }
        while (isalpha(ch)) {
            s += ch;
            ch = getchar();
        }
        readstr(oth...);
    }
     
    template <typename T, typename... T2>
    inline void print(T x, T2... oth) {
        ll p3=-1;
        if(x<0)
            putchar('-'),x=-x;
        do{
            print_f[++p3] = x%10 + 48;
        }while(x/=10);
        while(p3>=0)
            putchar(print_f[p3--]);
        putchar(' ');
        print(oth...);
    }
} // namespace FastIO
using FastIO::print;
using FastIO::read;
using FastIO::readstr; // 加速读入字符

const int maxn = 1e6 + 10;
const int mod = 998244353;
int MIN = 0x3f3f3f3f;
string s[maxn];

int f[maxn << 1];

void getf(string s)
{
    int len = s.length();
    f[0] = 0;
    for (int i = 1; i < len; ++i) {
        int j = f[i - 1];
        while (s[j] != s[i] && j > 0) j = f[j - 1];
        if (s[j] == s[i]) f[i] = j + 1;
        else f[i] = 0;
    }
}

int kmp(string p, string t)
{
    int i = 0, j = 0, cnt = 0, len1 = t.length(), len2 = p.length();
    while (i < len1) {
        if (t[i] == p[j]) { ++i; ++j; }
        else if (j > 0) j = f[j - 1];
        else if (j == 0) ++i;
        if (j == len2) { ++cnt; j = f[j - 1]; }
    }
    return cnt;
}

void solve()
{
    int n, temp; read(n);
    long long ans = 1;
    for (int i = 0; i < n; ++i)
    {
        readstr(s[i]);
        if (s[i].length() < MIN) { temp = i; MIN = s[i].length(); }
    }
    getf(s[temp]);
    for (int i = 0; i < n; ++i) ans = (ans * kmp(s[temp], s[i])) % mod;
    for (int i = 0; i < n; ++i) {
        if (s[i].length() == MIN) print(ans);
        else print(0);
    }
}


int main()
{
    solve();
    return 0;
}