#include<bits/stdc++.h>
using namespace std;

set<string> A;

int main() {
	string s;
	cin >> s;
	int len = s.length();
	s = s + s;
	for (int i = 0; i < len; ++i) A.insert(string(s, i, len));
	set<string>::iterator it = A.begin();
	set<string>::iterator it2 = A.end();
	--it2;
	cout << *it << '\n' << *it2;
	return 0;
}