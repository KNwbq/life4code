#include<iostream>
#include<stdio.h>
#include<ctime>
#include<unordered_map>
using namespace std;

struct node {
    int v, r, s;
    node* c[2];
    int cmp(int x) {
        if (v == x) return -1;
        return x>v?1:0;
    }
    void update() {
        s = 1;
        if (c[0] != NULL) s += c[0]->s;
        if (c[1] != NULL) s += c[1]->s;
    }
    node(int x):v(x) { c[0] = c[1] = NULL; r = rand(); s = 1; } 
};

struct nodeft {
    int f, t;
    nodeft(int f, int )
};

void rotate(node*& o, int d) {
    node *k = o->c[d^1];
    o->c[d^1] = k->c[d];
    k->c[d] = o;
    o->update();
    k->update();
    o = k;
}

void insert(node*& o, int x) {
    if (o == NULL) o = new node(x);
    else {
        int d = o->cmp(x);
        if (d == -1) d = 0;
        insert(o->c[d], x);
        if (o->c[d]->r>o->r) rotate(o, d^1);
    }
    o->update();
}

void remove(node*& o, int x) {
    if (o == NULL) return;
    int d = o->cmp(x);
    if (d == -1) {
        if (o->c[0] == NULL) o = o->c[1];
        else if (o->c[1] == NULL) o = o->c[0];
        else {
            int d2 = (o->c[0]->r>o->c[1]->r?1:0);
            rotate(o, d2);
            remove(o, x);
        }
    }
    else remove(o->c[d], x);
    if (o != NULL) o->update();
}

int kth(node* root, int k) {
    if (root == NULL || k <= 0 || k > root->s) return -1;
    int s = root->c[0]==NULL?0:root->c[0]->s;
    if (k == s+1) return root->v;
    else if (k <= s) return kth(root->c[0], k);
    else return kth(root->c[1], k-s-1);
}

int rank_(node* root, int x) {
    if (root == NULL) return 0;
    int s = root->c[0]==NULL?0:root->c[0]->s;
    int d = root->cmp(x);
    if (d == -1) return s+1;
    int res = 0;
    if (d == 0) res += rank_(root->c[0], x);
    else res += s+1+rank_(root->c[1], x);
    return res;
}

int main() {
    int n, m, w, f, t;
    char o;
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0) return 0;
        unordered_map<int, node*> graph;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &w);
            node* buff = new node(w);
            graph[i] = buff;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &f, &t);

        }
    }
    return 0;
}
