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

const int maxn = 100010;
int root;
int rev[maxn], pre[maxn], Size[maxn];
int tree[maxn][2];

struct node {
    int val, id;
    bool operator < (node& a) {
        if (val == a.val) return id < a.id;
        return val < a.val;
    }
}node[maxn];

int pushup(int x) {
   return Size[tree[x][0]] + Size[tree[x][1]] + 1; 
}

void update_rev(int x) {
    if (!x) return;
    swap(tree[x][0], tree[x][1]);
    rev[x] ^= 1;
}

void Rotate(int x, int c) {
    
}





