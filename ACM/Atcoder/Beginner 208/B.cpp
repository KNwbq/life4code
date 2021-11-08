#include<iostream>
using namespace std;

int buff[10] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};


int main() {
	int cur = 9, p, ans = 0;
	cin >> p;
	while (p > 0) {
		if (buff[cur] > p)  { --cur; continue; }
		if (buff[cur]*100 < p) { ans += 100; --cur; continue; }
		int a = p/buff[cur];
		ans += a; 
		p -= buff[cur]*a;
		--cur; 
	}
	cout << ans;
}