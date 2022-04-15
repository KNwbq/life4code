#include<bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int len = s.length(), tag = 0;
	for (int i = 0; i < len; ++i) {
		if (s[i] != 'o') { 
			++tag; 
			if (tag > 2) { cout << "No"; return 0; }
			continue; 
		}
		tag = 0;
		if ((i+1 < len && s[i+1] != 'x') || (i+2 < len && s[i+2] != 'x')) { cout << "No"; return 0; }
	}
	cout << "Yes";
	return 0;
}