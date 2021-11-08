#include<bits/stdc++.h>
using namespace std;
const int maxn = 20;
const int inf = 0x4f4f4f4f;
int dp[maxn];
vector<int> far[maxn];  

class edge {
public:    
    int v, w;
    edge(int v, int w): v(v), w(w) {}
};

class graph {
public:
    list<edge>** vertex;
    int n;
    graph(int N):n(N) {
        vertex = new list<edge>*[N];
        for (int i = 0; i < N; ++i) vertex[i] = new list<edge>();
    }
    int first(int v) {
        if (!vertex[v]->size()) return n;
        return vertex[v]->front().v;
    }
    int next(int v, int x) {
        list<edge>::iterator it;
        for (it = vertex[v]->begin();; ++it) {
            if (it->v == x && (++it) != vertex[v]->end()) return it->v;
            if (it == vertex[v]->end()) return n;
        }
    }
    int weight(int v, int x) {
        list<edge>::iterator it;
        for (it = vertex[v]->begin(); it != vertex[v]->end(); ++it) {
            if (it->v == x) return it->w;
        }
        return n;
    }
    void setweight(int v, int x, int w) {
        list<edge>::iterator it;
        for (it = vertex[v]->begin(); it != vertex[v]->end(); ++it) {
            if (it->v == x) vertex[v]->erase(it);
        } 
        edge ne(x, w);
        vertex[v]->push_back(ne);
    }
};

int farN[maxn];
int cnt[maxn];

void dfs(int x) {
    if (farN[x]){
        dfs(farN[x]);
        cout << farN[x] << endl;
    }
    else cout << farN[x] << endl;
}

int main() {
    clock_t start, end;
    freopen("D:\\VSCODE\\DataTest\\data.out.txt", "w", stdout);
    freopen("D:\\VSCODE\\DataTest\\data.in.txt", "r", stdin);
    memset(dp, inf, sizeof(dp));
    memset(farN, 0, sizeof(farN));
    dp[0] = 0;  
    int v, x, w; graph G(7);
    while (cin >> v >> x >> w) {
        ++cnt[x];
        far[x].push_back(v);    
        G.setweight(v, x, w);
    }



    cout << "Foreward\n";
    for (int i = 0; i < 7; ++i) { 
        for (int j = 0; j < cnt[i]; ++j) {
            int buf = dp[i];
            dp[i] = min(dp[i], dp[far[i][j]]+G.weight(far[i][j], i));
            if (buf != dp[i]) farN[i] = far[i][j];
        }
        cout << i << ':' << dp[i] << endl;
    }
    dfs(6);
    
    memset(dp, inf, sizeof(dp));
    dp[6] = 0;
    cout << "\nBackward\n";
    for (int i = 6; i >= 0; --i) {
        for (auto it: far[i]) {
            dp[it] = min(dp[it], dp[i]+G.weight(it, i));
        }
        cout << i << ':' << dp[i] << endl;
    }

}