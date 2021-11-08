#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6;

class Edge {
private:
    int v, w;
public:
    Edge(int v = 0, int w = 0): v(v), w(w) {}
    const int vertx() { return v; }
    const int weight() { return w; }
};

class Graph {
private:
    list<Edge>** vertx;
    int V;
    int* mark;
public:
    Graph(int v): V(v) {
        vertx = new list<Edge>*[v];
        mark = new int[v];
        for (int i = 0; i < v; ++i) mark[i] = 0;
        for (int i = 0; i < v; ++i) vertx[i] = new list<Edge>();
    }
    const int n() { return V; }

    int first(int v) {
        if (!vertx[v]->size()) return n();
        else return vertx[v]->front().vertx();
    }

    int next(int u, int v) {
        list<Edge>::iterator it;
        for (it = vertx[u]->begin();; ++it) {
            if (it->vertx() == v && (++it) != vertx[u]->end()) { return it->vertx(); }
            if (it == vertx[u]->end()) return n();
        }
    }

    void setEdge(int v1, int v2, int w) {
        Edge cur = Edge(v2, w);
        list<Edge>::iterator it;
        for (it = vertx[v1]->begin(); it != vertx[v1]->end(); ++it) {
            if (it->vertx() == v2) { vertx[v1]->erase(it); break; }
        }
        vertx[v1]->push_back(cur);
        return;
    }

    bool isEdge(int v1, int v2) {
        list<Edge>::iterator it;
        for (it = vertx[v1]->begin(); it != vertx[v1]->end(); ++it) {
            if (it->vertx() == v2) return true;
        }
        return false;
    }

    void print() {
        list<Edge>::iterator it;
        for (int i = 0; i < n(); ++i) {
            for (it = vertx[i]->begin(); it != vertx[i]->end(); ++it)
                cout << it->weight() << ' ';
            cout << endl; 
        }
    }

    int weight(int v1, int v2) {
        if (!isEdge(v1, v2)) return maxn;
        list<Edge>::iterator it;
        for (it = vertx[v1]->begin(); it != vertx[v1]->end(); ++it) {
            if (it->vertx() == v2) return it->weight();
        }
        return 0;
    }

    int getMark(int v) {
        return mark[v];
    }

    void setMark(int v, int val) {
        mark[v] = val;
    }
};

int minV(Graph* G, int* D) {
    int i = 0, j = G->n();
    for (i; i < G->n(); ++i)
        if (!G->getMark(i)) { j = i; break; }
    for (i; i < G->n(); ++i)
        if (!G->getMark(i) && D[i] < D[j]) { j = i; }
    return j;
}

void prim(Graph* G, int* D, int* V, int S) {
    for (int i = 0; i < G->n(); ++i) D[i] = maxn;
    D[S] = 0; V[S] = S; 
    while (true) {
        int vertx = minV(G, D);
        if (vertx == G->n()) return;
        G->setMark(vertx, 1);
        for (int i = G->first(vertx); i < G->n(); i = G->next(vertx, i))
            if (G->weight(vertx, i) < D[i] && !G->getMark(i)) { D[i] = G->weight(vertx, i); V[i] = vertx; }  
    }
}

int D[maxn], V[maxn];

int main() {
    clock_t start, finish;
    for (int i = 6; i < 10000; i += 500) {
        Graph A(i);
        for (int j = 0; j < i; ++j)
            for (int k = j; k < i; ++k) {
                if (k == j) { A.setEdge(k, j, 0); continue; }
                int dis = rand()%30;
                A.setEdge(k, j, dis);
                A.setEdge(j, k, dis);
        }
        start = clock();
        prim(&A, D, V, 0);
        finish = clock();
        cout << (double)(finish-start)/CLOCKS_PER_SEC << ',';
    }
    // cout << (double)(finish-start)/CLOCKS_PER_SEC;
    return 0;
}