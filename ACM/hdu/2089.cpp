#include<iostream>
using namespace std;

const int maxn = 15;
long long a[maxn], b[maxn], c[maxn];

long long dfs(){

}

int sol(int x) {
	int cnt = 0;
	while (x) {
		a[++cnt] = x % 10;
		x /= 10;
		b[cnt] = a[cnt] * c[cnt-1] + b[cnt-1];
	}
	return dfs()	
}

int main() {
	int n, m;
	c[0] = 1ll;
	for (int i = 1; i < maxn; ++i) c[i] = c[i-1] * 10ll;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) return 0;
		cout << sol(m) - sol(n) << endl;
	}
}