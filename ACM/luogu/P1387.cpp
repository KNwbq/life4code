#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int arry[maxn][maxn], sumPre[maxn][maxn], n, m, l = 0;

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
    read(n), read(m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            read(arry[i][j]);
            if (i == 0 && j == 0) sumPre[i][j] =  arry[i][j];
            else if (i == 0) sumPre[i][j] = sumPre[i][j-1] + arry[i][j];
            else if (j == 0) sumPre[i][j] = sumPre[i-1][j] + arry[i][j];
            else sumPre[i][j] = sumPre[i-1][j] + sumPre[i][j-1] + arry[i][j] - sumPre[i-1][j-1];
        }
    int minD = min(n, m);
    for (int i = 0; i < n && l < minD; ++i) {
        for (int j = 0; j < m && l < minD; ++j) {
            if (i == 0 && j == 0) {
                while (l < minD) 
                    if (sumPre[l][l] == (l+1)*(l+1)) ++l;
                    else break;
            }
            else if (i == 0) {
                while (l < minD && i+l < n && j+l < m)
                    if (sumPre[l][j+l] - sumPre[i+l][j-1] == (l+1)*(l+1)) ++l;
                    else break;
            }
            else if (j == 0) {
                while (l < minD && i+l < n && j+l < m)
                    if (sumPre[i+l][l] - sumPre[i-1][l] == (l+1)*(l+1)) ++l;
                    else break;
            }
            else {
                while (l < minD && i+l < n && j+l < m)
                    if (sumPre[i+l][j+l] - sumPre[i+l][j-1] - sumPre[i-1][j+l] + sumPre[i-1][j-1] == (l+1)*(l+1)) ++l;
                    else break;
            }
        }
    }
    print(l);
    return 0;
}