#include<iostream>
using namespace std;
const int maxn = 1e5 + 10;
int cnt[maxn];

int main() {
	int a, b, n, nb; cin >> n; nb = n;
	while (n > 1) {
		cin >> a >> b;
		++cnt[a]; ++cnt[b];
		--n;
	}
	for (int i = 1; i <= nb; ++i) {
		if (cnt[i] == nb - 1) {
			cout << "Yes"; return 0;
		}
	}
	cout << "No";
	return 0;
}