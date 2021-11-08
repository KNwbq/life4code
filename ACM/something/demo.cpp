/*#include<iostream>
using namespace std;
const int maxn = 1e6;
const int INF = 0x4f4f4f4f;

class maxHeap
{
public:
	int node[maxn];
	int size;
	maxHeap() { node[0] = INF; size = 0; }
};

void sift_down(maxHeap *root, int idx)
{
	int data = root->node[idx], p, c; 
	for (p = idx; 2 * p <= root->size; p = c)
	{
		c = 2 * p;
		if (c != root->size && root->node[c] < root->node[c+1]) 
			++c;
		if (data > root->node[c]) break;
		else root->node[p] = root->node[c];
	}
	root -> node[p] = data;
}

void sift_up(maxHeap *root)
{
	int p = root->size, data = root->node[p];
	for (p; root->node[p/2] < data; p /= 2)
		root->node[p] = root->node[p/2];
	if (p != 0)root->node[p] = data;
}

void insert_(maxHeap *root, int x)
{
	root->node[++root->size] = x;
	sift_up(root);
}

void Build_mH(maxHeap *root)
{
	int size = root->size;
	for (int i = size/2; i >= 1; --i) sift_down(root, i);
}

int getM(maxHeap *root)
{
	int ans = root->node[1];
	root->node[1] = root->node[root->size--];
	sift_down(root, 1);
	return ans;
}


#include<iostream>
using namespace std;

template<class elem>
class BinNode
{
public:
	virtual elem value() = 0;
	virtual void setval(elem val) = 0;
	virtual	void setl(BinNode<elem> *p) = 0;
	virtual void setr(BinNode<elem> *p) = 0;
	virtual BinNode<elem>* left() = 0;
	virtual BinNode<elem>* right() = 0;
	virtual bool isLeaf() = 0;
};

template<class elem>
class BinNodePtr : public BinNode<elem>
{
private:
	elem it;
	BinNodePtr<elem> *lc, *rc;
public:
	BinNodePtr(elem val, BinNodePtr<elem> *lcc = NULL, BinNodePtr<elem> *rcc = NULL) : it(val), lc(lcc), rc(rcc) {}
	elem value() { return it; }
	void setval(elem val) { it = val; }
	void setl(BinNode<elem> *p) { lc = (BinNodePtr<elem>*)p; }
	void setr(BinNode<elem> *p) { rc = (BinNodePtr<elem>*)p; }
	BinNode<elem>* left() { return lc; }
	BinNode<elem>* right() { return rc; }
	bool isLeaf() { return (left() == NULL && right() == NULL); }
};

template<class elem>
void preorder(BinNodePtr<elem>* subroot)
{
	if(subroot == NULL) return;
	cout << subroot->value();
	preorder(subroot->left());
	preorder(subroot->right());
}

enum NodeType {leaf, internode};
template<class elem>
class VarBinNode
{
	NodeType MyType;
	union {
		struct {
			VarBinNode<elem> *lc, *rc;
			elem opx;
		}intl;
		elem var;
	}
	VarBinNode(elem val) { MyType = leaf; var = val; }
	VarBinNode(elem val, VarBinNode<elem>* lc, VarBinNode<elem>* rc) { MyType = internode; intl.opx = val; intl.lc = lc; intl.rc = rc; }
	bool isLeaf() { return MyType == leaf; }
};*/




#include<iostream>
#include<iomanip>
#include<windows.h>
#include<algorithm>
using namespace std;

void insert(int* a, int cnt) {
    for (int i = 0; i < cnt; ++i) {
        int j = i;
        while (j > 0 && a[j] < a[j-1]) {
            swap(a[j], a[j-1]); --j;
        }
    }
}

// void shell(int *a, int cnt, int gap) {
//     for (int x = gap; x > 0; x /= 2) {
//         for (int z = 0; z < x; ++z) {
//             for (int i = z; i < cnt; i += x) {
//                 int j = i;
//                 while (j >= x && a[j] < a[j-x]) { swap(a[j], a[j-x]); j -= x; }
//             }
//         }
//     }
// }

// int bsearch(int* a, int cnt, int x) {
//     int l = -1, r = cnt;
//     while (l < r) {
//         int mid = (l+r)/2;
//         if (a[mid] == x) { return mid; }
//         if (a[mid] < x) l = mid;
//         else r = mid;
//     }
//     return -1;
// }

void quick_sort(int* a, int l, int r) {
    if (l >= r) return;
    int mid = (l+r)/2, ll = l, rr = r, tag = a[mid];
    swap(a[r], a[mid]);
    while (ll < rr) {
        while (ll < r && a[ll] <= tag) ++ll;
        while (rr > l && a[rr] >= tag) --rr;
        swap(a[ll], a[rr]);
    }
    swap(a[ll], a[rr]);
    swap(a[r], a[ll]);
    quick_sort(a, l, rr);
    quick_sort(a, ll+1, r);
}

struct node {
    double x, y;
    int rank;
    node(double x, double y, int rank=0): x(x), y(y), rank(rank) {}
};

bool cmp1(node a, node b) {
	if (a.x < b.x) return true;
	else return false;
}

bool cmp2(node a, node b) {
	if (a.y < b.y) return true;
	else return false;
}

void rsort(node* a, int l, int r) {
    if (l >= r) return;
    sort(a+l, a+r, cmp1);
    int mid = (l+r)<<1;
    rsort(a, l, mid);
    rsort(a, mid+1, r);
    sort(a+l, a+mid+1, cmp2);
    sort(a+mid+1, a+r+1, cmp2);
    int j = l;
    for (int i = mid+1; i <= r; ++i)
        for (j; j <= r+1; ++j)
            if (a[j].y >= a[i].y) { a[i].rank += j-l; }
}

int main() {
    // int arry[11] = {2, 4, 1, 2, 3, 4, 5, 349238, 234, -1212, 0};
    // // shell(arry, 5, 2);
    // // cout << bsearch(arry, 5, 2);
    // quick_sort(arry, 0, 10);
    // for (auto it: arry) cout << it << ' ';
    // return 0;
    node ary[6] = {node(2, 1), node(3, 2), node(10, 10), node(8, 2), node(5, 3), node(2, 4)};
    rsort(ary, 0, 5);
    for (auto it: ary) cout << it.rank << ' ';

}