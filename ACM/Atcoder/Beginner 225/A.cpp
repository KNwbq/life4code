#include<iostream>
#include<string>
using namespace std;

int main() {
	int cnt = 0;
	string s; cin >> s;
	for (int i = 0; i < 3; ++i) {
		for (int j = i + 1; j < 3; ++j)
			if (s[i] == s[j]) ++cnt;
	}
	if (cnt == 0) cout << 6;
	else if (cnt == 1) cout << 3;
	else cout << 1;
}