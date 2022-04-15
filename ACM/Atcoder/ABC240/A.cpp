#include<iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (b == a % 10 + 1 || a == b % 10 + 1) cout << "Yes";
	else cout << "No";
	return 0;
}