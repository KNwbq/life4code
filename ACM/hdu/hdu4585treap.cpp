#include<iostream>
#include<stdio.h>
#include<ctime>
using namespace std;
const int maxn = 5000020;
int id[maxn];

struct node {
    node* c[2];
    int v, r, s;
    node(int value):v(value) { c[0] = c[1] = NULL; r = rand(); s = 1; }
    int cmp(int x) {
        if(v == x) return -1;
        return v < x ? 1 : 0;
    }
    void maintain() {
        s = 1;
        if (c[0] != NULL) s += c[0]->s;
        if (c[1] != NULL) s += c[1]->s;
    }
};

void rotate(node*& o, int d) {
    node* k = o->c[d^1];
    o->c[d^1] = k->c[d];
    k->c[d] = o;
    o->maintain();
    k->maintain();
    o = k;
}

void insert(node*& o, int v_) {
    if (o == NULL) o = new node(v_);
    else {
        int k = o->cmp(v_);
        if (k == -1) k = 0;
        insert(o->c[k], v_);
        if (o->c[k]->r > o->r) 
            rotate(o, k^1);
    }
    o->maintain();
}

void remove(node*& o, int x) {
    if (o == NULL) return;
    int d = o->cmp(x);
    if (d == -1) {
        if (o->c[0] == NULL) o = o->c[1];
        else if (o->c[1] == NULL) o = o->c[0];
        else {
            int d2 = (o->c[0]->r > o->c[1]->r?1:0);
            rotate(o, d2);
            remove(o->c[d2], x);
        }
    }
    else remove(o->c[d], x);
    if (o != NULL)o->maintain();
}

int kth(node* o, int k) {
    if (o == NULL || k > o->s || k <= 0) return -1;
    int s = (o->c[0] == NULL?0:o->c[0]->s);
    if (k == s+1) return o->v;
    else if (k <= s) return kth(o->c[0], k);
    else return kth(o->c[1], k-s-1);
}

int rank_(node* o, int x) {
    if (o == NULL) return 0;
    int res = 0;
    int s = (o->c[0] == NULL?0:o->c[0]->s);
    if (x <= o->v) {
        res += rank_(o->c[0], x);
        if (x == o->v) res += 1; 
    }
    else
    {
        res += s + 1;
        res += rank_(o -> c[1], x);
    }
    return res;
}

int main() {
    int n, x, y, r, ss, bb; 
    while (cin >> n) {
        srand(time(NULL));
        if (n == 0) return 0;
        node* head = new node(1000000000);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &x, &y);
            insert(head, y);
            id[y] = x;
            r = rank_(head, y);
            if (r == 1) {
                if (i == 0) printf("%d %d\n", x, 1);
                else printf("%d %d\n", x, id[kth(head, r+1)]);
            }
            else {
                ss = kth(head, r-1), bb = kth(head, r+1);
                if (ss <= 0) printf("%d %d\n", x, id[bb]);
                else if (y-ss > bb-y) printf("%d %d\n", x, id[bb]);
                else printf("%d %d\n", x, id[ss]);
            }
        }
    }
    return 0;
}