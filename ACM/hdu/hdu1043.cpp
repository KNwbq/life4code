#include<bits/stdc++.h>
#define Swap(a, b) { char c = a; a = b; b = c; }
using namespace std;

const int maxn = 400000;
int fac[] = {1,1,2,6,24,120,720,5040,40320,362880};
bool vis[maxn];
int to[4] = {-1, 1, -3, 3}; // left, right, up, down
char oper[4] = {'r', 'l', 'd', 'u'};

struct node {
    char arry[9];
    int itshash;
    int xpos;
}des, buffer, tmp;

struct node2 {
    int far;
    char ope;
}Node[maxn];

int cantor(char* cstr) {
    int ans = 0, cnt;
    for (int i = 0; i < 9; ++i) {
        cnt = 0;
        for (int j = 0; j < i; ++j)
            if (cstr[j] < cstr[i]) ++cnt;
        ans += (cstr[i] - '0' - cnt) * fac[8-i];
    }
    return ans;
}

void func() {
    queue<node> bfs;
    for (int i = 0; i < 8; ++i) des.arry[i] = char('1' + i);
    des.arry[8] = '0';
    des.xpos = 8;
    int hash = cantor(des.arry);
    des.itshash = hash; vis[hash] = true; bfs.push(des);
    while (!bfs.empty()) {
        buffer = bfs.front(); bfs.pop();
        for (int i = 0; i < 4; ++i) {
            tmp = buffer;
            int pos = buffer.xpos + to[i];
            if ((i == 0 && (pos+1)%3) || (i == 1 && pos%3) || (i == 2 && pos >= 0) || (i == 3 && pos < 9)) {
                Swap(tmp.arry[pos], tmp.arry[tmp.xpos]);
                int itshash = cantor(tmp.arry);
                if (!vis[itshash]) {
                    vis[itshash] = true;
                    tmp.itshash = itshash;
                    tmp.xpos = pos;
                    Node[itshash].far = buffer.itshash;
                    Node[itshash].ope = oper[i];
                    bfs.push(tmp);
                }
            }
        }
    }
}

void dfs(int leaf) {
    if (Node[leaf].far) {
        putchar(Node[leaf].ope);
        dfs(Node[leaf].far);
    }
}

int main() {
    memset(vis, 0, sizeof(vis));
    char c[50];
    char orig[9];
    func();
    while (fgets(c, sizeof(c), stdin)) {
        int cnt = 0;
        for (int i = 0; c[i]; ++i) {
            if (c[i] == ' ') continue;
            else if (c[i] == 'x') orig[cnt++] = '0';
            else orig[cnt++] = c[i];
        }
        int ohash = cantor(orig);
        if (!vis[ohash]) puts("unsolved");
        else { dfs(ohash); putchar('\n'); }
    }
    return 0;
}