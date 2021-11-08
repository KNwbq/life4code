#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn = 1020;
int pre[maxn];
int in[maxn];
int p;

struct  node
{
    node *lc, *rc;
    int val;
    node() { lc = rc = NULL; }
};

node* build(node* root, int l, int r) {
    if (root == NULL) root = new node();
    int pos;
    for (pos = l; l <= r; ++pos) if (in[pos] == pre[p]) break;
    root->val = in[pos];
    if (l <= pos-1) { ++p; root->lc = build(root->lc, l, pos-1); }
    if (pos+1 <= r) { ++p; root->rc = build(root->rc, pos+1, r); }
    return root;
}

void remove(node* head) {
    if (head == NULL) return;
    remove(head->lc);
    remove(head->rc);
    delete head;
}

void postorder(node* root, node* p) {
    if (root == NULL) return;
    postorder(root->lc, p);
    postorder(root->rc, p);
    printf("%d", root->val);
    printf("%c", (root==p)?'\n':' ');
}

int main() {
    int n;
    while (cin >> n) {
        p = 1;
        for (int i = 1; i <= n; ++i) scanf("%d", pre+i);
        for (int i = 1; i <= n; ++i) scanf("%d", in+i);
        node* head = new node();
        build(head, 1, n);
        postorder(head, head);
        remove(head);
    }
    return 0;
}