#include<iostream>
using namespace std;

int main() {
	int a, b; cin >> a >> b;
	if (b >= a && b <= 6*a) cout << "Yes";
	else cout << "No";
	return 0;
}	