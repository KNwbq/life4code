#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 2e5+20;

struct node{
	int id, a;
	node() {}
	node(int x, int y): id(x), a(y) {};
}cit[maxn];

bool cmp(node A, node B) {
	return A.a < B.a;
}

ll rank_[maxn];
ll ans[maxn];

int main() {
	ll n, k, A;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> A;
		cit[i] = node(i, A);
	}
	sort(cit+1, cit+n+1, cmp);
	for (int i = 1; i <= n; ++i) rank_[i] = cit[i].id;
	ll a = k / n;
	k -= a*n;
	for (int i = 1; i <= n; ++i) ans[i] += a;
	for (int i = 1; i <= k; ++i) ans[rank_[i]] += 1;
	for (int i = 1; i <= n; ++i) cout << ans[i] << endl;
}