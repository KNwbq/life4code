#include<bits/stdc++.h>
using namespace std;
const int maxn = 20;
const int inf = 0x4f4f4f4f;
int bfs[maxn];
int V[maxn];

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

void init() {
    for (int i = 0; i < maxn; ++i) 
        bfs[i] = inf;
    bfs[0] = 0; 
    V[0] = 0;
}

void BFS(graph G) {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = G.first(cur); i < G.n; i = G.next(cur, i)) {
            if (bfs[cur]+G.weight(cur, i) < bfs[i]) {
                bfs[i] = bfs[cur]+G.weight(cur, i); q.push(i); V[i] = cur;
            }
        }
    }    
}

int main() {
    clock_t start, end;
    // freopen("D:\\code\\VSCODE\\DataTest\\data.out.txt", "w", stdout);
    freopen("D:\\code\\VSCODE\\DataTest\\data.in.txt", "r", stdin);
    int v, x, w; graph G(7);
    while (cin >> v >> x >> w) {
        G.setweight(v, x, w);
    }
    init();
    BFS(G);
    cout << "The shortest path is " << bfs[6] << endl;
    int arry[maxn], cnt = 0;
    int T = 6;
    while (V[T] != T) {
        arry[cnt++] = T;
        T = V[T];
    }
    cout << V[T];
    for (int i = cnt-1; i >= 0; --i)
        cout << "->" << arry[i];
}