#include<bits/stdc++.h>
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

int main() {
    int N, numer, domin, flag = 1;
    read(N);
    while (N-flag > 0) { N -= flag; ++flag; }
    if (flag&1) domin = N;
    else domin = flag + 1 - N;
    cout << flag + 1 - domin << '/' << domin;
    return 0;
}