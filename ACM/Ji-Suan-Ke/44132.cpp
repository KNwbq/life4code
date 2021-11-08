#include<bits/stdc++.h>
using namespace std;

int main() {
	int w, h, g;
	while (cin >> w >> h >> g) {
		if (w - 2 * g <= 0 || h - 2 * g <= 0) cout << "0\n";
		else cout << (w - 2*g) * (h - 2*g) << endl;
	}
}