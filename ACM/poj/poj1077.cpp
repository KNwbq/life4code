#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#define Swap(a, b) { char x = a; a = b; b = x; }
using namespace std;
const int maxn = 1e6;
int p[] = {1,1,2,6,24,120,720,5040,40320,362880};
bool vis[maxn];
int to[4] = {-1, -3, 1, 3};
char o[4] = {'l', 'u', 'r', 'd'};

int cartor(char* arry) {
    int h = 0, cnt;
    for (int i = 0; i < 9; ++i) {
        cnt = 0;
        for (int j = 0; j < i; ++j) 
            if (arry[j] < arry[i]) ++cnt;
        h += (arry[i]-'0'-cnt)*p[8-i];
    }
    return h;
}
struct node
{
    char arry[9];
    int itshash;
    int pos0;
}eight, cur, temp;
struct op {
    int last;
    char opera;
}opp[maxn];
void dfs(int cur) {
    if (opp[cur].last != -1) {
        dfs(opp[cur].last);
        putchar(opp[cur].opera);
    }
}
void init() {
    for (int i = 0; i < maxn; ++i) {
        vis[i] = false;
        opp[i].last = -1;
    }
}
int main() {
    int car, cnt, def = false;
    char buff[50];
    while (gets(buff)) {
        cnt = 0; init(); queue<node> bfs; def = false;
        for (int i = 0; buff[i]; ++i) {
            if (buff[i] == ' ') continue;
            if (buff[i] == 'x') { eight.arry[cnt++] = '0'; eight.pos0 = cnt-1; }
            else eight.arry[cnt++] = buff[i];
        }
        for (int i = 0; i < maxn; ++i) vis[i] = false;
        car = cartor(eight.arry);
        eight.itshash = car;
        bfs.push(eight);
        vis[car] = true;

        while (!bfs.empty()) {
            cur = bfs.front(); bfs.pop();
            if (cur.itshash == 46233) { dfs(46233); putchar('\n'); def = true; break; }
            for (int i = 0; i < 4; ++i) {
                temp = cur;
                if ((i == 0 && cur.pos0%3) || (i == 1 && cur.pos0 > 2) || (i == 2 && (cur.pos0+1)%3) || (i == 3 && cur.pos0 < 6)) {
                    Swap(temp.arry[temp.pos0], temp.arry[temp.pos0+to[i]]);
                    car = cartor(temp.arry);
                    if (vis[car]) continue;
                    temp.pos0 += to[i];
                    temp.itshash = car;
                    bfs.push(temp);
                    vis[car] = true;
                    opp[car].last = cur.itshash;
                    opp[car].opera = o[i];
                }
            }
        }
        if(!def) puts("unsolvable");
    }
        return 0;
}