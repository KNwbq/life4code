#include<iostream>
using namespace std;

const int maxn = 2005;

struct node {
	int next;
	int to;
}edge[maxn];

int cnt, head[maxn];

void init() {
	memset(head, -1, sizeof(head));
}

void addedge(int u, int v) {
	edge[cnt].to = u;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}
