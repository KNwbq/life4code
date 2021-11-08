#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

struct node {
    node *lc, *rc;
    int val;
    node(int x) { lc = rc = NULL; val = x; }
    node() { lc = rc = NULL; }
};

node* insert(node*& root, int val) {
    if (root == NULL) return root = new node(val);
    if (val < root->val) root->lc = insert(root->lc, val);
    else if (val > root->val) root->rc = insert(root->rc, val);
    return root;
}

void postorder(node* root, node* p) {
    if (root == NULL) return;
    if (root != p) putchar(' ');
    printf("%d", root->val);
    postorder(root->lc, p);
    postorder(root->rc, p);
}

void remove(node* head) {
    if (head == NULL) return;
    remove(head->lc);
    remove(head->rc);
    delete head;
}

int main() {
    node* head = NULL;
    int n, m;
    while (cin >> n) {
        head = NULL;
        for (int i = 0; i < n; ++i) { scanf("%d", &m); insert(head, m); }
        postorder(head, head);
        putchar('\n');
        remove(head);
    }
    return 0;
}