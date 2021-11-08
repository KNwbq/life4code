#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int to[4] = {-8, 8, -1, 1};
short def[8][8][8][8][8][8][8][8];


struct node {
    int arry[4];
    int depth;
    node() {}
    node(int x, int* arry2) {
        depth = x;
        for (int i = 0; i < 4; ++i)
            arry[i] = arry2[i];
    }
}cur;

int gethash(int* arry) {
    int x[4], y[4];
    for (int i = 0; i < 4; ++i) {
        x[i] = arry[i]/8;
        y[i] = arry[i]%8;
    }
    return def[x[0]][y[0]][x[1]][y[1]][x[2]][y[2]][x[3]][y[3]];
}

void sethash(int* arry, int m) {
    int x[4], y[4];
    for (int i = 0; i < 4; ++i) {
        x[i] = arry[i]/8;
        y[i] = arry[i]%8;
    }
    def[x[0]][y[0]][x[1]][y[1]][x[2]][y[2]][x[3]][y[3]] = m;
}

inline bool find(int* arry, int x) {
    for (int i = 0; i < 4; ++i)
        if (arry[i] == x) return true;
    return false;
}

void func(node a, int x) {
    queue<node> bfs;
    if (x == 2 && gethash(a.arry) == 1) { puts("YES"); return; }
    sethash(a.arry, x);
    bfs.push(a);
    while (!bfs.empty()) {
        cur = bfs.front(); bfs.pop();
        int t, np, buff[4];
        for (int i = 0; i < 4; ++i) buff[i] = cur.arry[i];

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                t = cur.depth;
                np = cur.arry[i]+to[j]; 
                if (find(cur.arry, np)) np = np+to[j];
                if ((j == 0 && np >= 0) || (j == 1 && np < 64) || (j == 2 && !((np+2)%8==0 || (np+1)%8==0)) || (j == 3 && !(np%8==0 || (np-1)%8==0))) {
                    buff[i] = np;
                    if (x == 2 && gethash(buff) == 1) { puts("YES"); return; }
                    else if (gethash(buff) == 0) {
                        ++t; sethash(buff, x);
                        if (t < 4) bfs.push(node(t, buff));
                    }
                    buff[i] = cur.arry[i];
                }
            }
        }
    }
    if (x == 2) { puts("NO"); return; }
}

int main() {
    int arry[16], a[4];
    memset(def, 0, sizeof(def));
    while (cin >> arry[0]) {
        memset(def, 0, sizeof(def));
        for (int i = 1; i < 16; ++i) cin >> arry[i];
        for (int i = 0; i < 4; ++i) a[i] = (arry[2*i]-1)*8+arry[2*i+1]-1;
        func(node(0, a), 1);
        for (int i = 0; i < 4; ++i) a[i] = (arry[2*i+8]-1)*8+arry[2*i+9]-1;
        func(node(0, a), 2);
    }
    return 0;
}