#include<iostream>
#include<stack>
using namespace std;

stack<int> cow;

int main() {
	long long ans = 0;
	int n, a; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		while (!cow.empty() && cow.top() <= a) cow.pop();
		ans += cow.size();
		cow.push(a);
	}
	cout << ans;
	return 0;
}