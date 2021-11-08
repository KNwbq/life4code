#include<iostream>
#define ll long long 
using namespace std;
 
const int maxn = 3005;
 
struct node{
	double l, r;
	node() {}
	node(double l, double r): l(l), r(r) {}
}arry[maxn];
 
bool check(node a, node b) {
	if ((b.l <= a.r && b.r >= a.l) || (a.l <= b.r && a.r >= b.l)) {return true; }
	return false;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, cnt = 0; cin >> N;
	ll lll, rrr, t;
	for (int i = 0; i < N; ++i) {
		cin >> t >> lll >> rrr;
		if (t == 1) arry[cnt++] = node(lll, rrr);
		else if (t == 2) arry[cnt++] = node(lll, rrr-0.1);
		else if (t == 3) arry[cnt++] = node(lll+0.1, rrr);
		else if (t == 4) arry[cnt++] = node(lll+0.1, rrr-0.1);
	}
	ll ans = 0;
	for (int i = 0; i < N; ++i)
		for (int j = i+1; j < N; ++j)
			if (check(arry[i], arry[j])) ++ans;
	cout << ans;
	return 0;
}