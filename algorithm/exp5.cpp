#include<iostream>
#include<queue>
#define Swap(a, b) { char c = a; a = b; b = c; }
using namespace std;

const int maxs = 400000;
int fac[] = {1,1,2,6,24,120,720,5040,40320,362880};
int to[4] = {-3, 3, -1, 1}; // up, down, left, rigth
char direc[4] = {'u', 'd', 'l', 'r'};
bool vis[maxs];

struct nodel {
    int far;
    char oper;
}Node[maxs];

struct Anode {
    int hashv;
    int xpos;
    char arry[9];
    int f, g, h;
    bool operator<(const Anode& a) const {
        return f > a.f;
    }
}origg, tempp, bufferr;

int geth(char* cstr) {
    int cnt = 0;
    for (int i = 0; i < 9; ++i) {
        if (cstr[i] == '0') continue;
        int x = i/3, y = i%3;
        int xx = (cstr[i]-'0'-1)/3, yy = (cstr[i]-'0'-1)%3;
        cnt += abs(xx-x) + abs(yy-y);
    }
    return cnt;
}

int cantor(char* cstr) {
    int ans = 0, cnt;
    for (int i = 0; i < 9; ++i) {
        cnt = 0;
        for (int j = 0; j < i; ++j)
            if (cstr[j] < cstr[i]) ++cnt;
        ans += (cstr[i]-'0'-cnt)*fac[8-i];
    }
    return ans;
}

bool check(char* cstr) {
    int cnt = 0;
    for (int i = 0; i < 9; ++i) {
        if (cstr[i] == '0') continue;
        for (int j = 0; j < i; ++j)
            if (cstr[j] > cstr[i]) ++cnt;
    }
    if  (cnt%2 == 0) return true;
    return false;
}

char c[50] = {'7', '6', '5', '0', '3', '2', '8', '1', '4'};
char a[50] = {'1', '2', '3', '4', '5', '6', '7', '8', '0'};

void init() {
    for (int i = 0; i < maxs; ++i) Node[i].far = 399999;
}

void dfs(int hashv) {
    if (vis[Node[hashv].far]) {
        dfs(Node[hashv].far);
        putchar(Node[hashv].oper);
    }
}

void funca() {
    priority_queue<Anode> bfs;
    for (int i = 0; i < 9; ++i) origg.arry[i] = c[i];

    origg.xpos = 3; origg.hashv = cantor(origg.arry); vis[origg.hashv] = true;
    origg.g = 0; origg.h = geth(origg.arry); origg.f = origg.g + origg.h;
    bfs.push(origg);

    while (!bfs.empty()) {
        tempp = bfs.top(); bfs.pop();
        int npos, itshash;
        if (tempp.hashv == 46233) { cout << "Find the solution!" << tempp.f << endl; return; }
        for (int i = 0; i < 4; ++i) {
            npos = tempp.xpos + to[i];
            bufferr = tempp;
            if (i == 0 && npos >= 0 || i == 1 && npos < 9 || i == 2 && (npos+1)%3 || i == 3 && npos%3) {
                Swap(bufferr.arry[npos], bufferr.arry[bufferr.xpos]);
                itshash = cantor(bufferr.arry);
                if (!vis[itshash] && check(bufferr.arry)) {
                    vis[itshash] = true;
                    bufferr.g = tempp.g+1;
                    bufferr.h = geth(bufferr.arry);
                    bufferr.f = bufferr.g + bufferr.h;
                    bufferr.hashv = itshash;
                    bufferr.xpos = npos;
                    Node[itshash].far = tempp.hashv;
                    Node[itshash].oper = direc[i];
                    bfs.push(bufferr);
                }
            }
        } 
    }
} 

int main() {
    init();
    funca();
    dfs(46233);
    cout << geth(a);
}