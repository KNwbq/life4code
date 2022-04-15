#include<iostream>
using namespace std;

void dfs(int n) {
	if (n == 1) { cout << n; return; }
	else {
		dfs(n-1);
		cout << ' ' << n << ' ';
		dfs(n-1); 
	}
	return;
}

int main() {
	int n; cin >> n;
	dfs(n);
	return 0;
}