#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; ++i) {
		vector<int> tag;
		string a, b;
		cin >> a >> b;
		int s = a.length();
		tag.resize(s, 0);
		for (int j = s - 1; j >= 1; --j) 
			if (a[j] != b[j]) tag[j-1] = tag[j] + 1;
			else tag[j-1] = tag[j];
		int flag = 0;
		cout << "Case " << i + 1 << ": ";
		for (int j = 0; j < s; ++j) {
			if (a[j] == b[j]) cout << 'a';
			else if (abs(flag) > tag[j]) {
				if (flag < 0) {cout << b[j]; ++flag; }
				else if (flag > 0) {cout << a[j]; --flag; }
			}
			else {
				if (!(a[j] == 'a' || b[j] == 'a')) cout << 'a';
				else if (a[j] == 'a' && abs(flag - 1) <= tag[j]) { cout << 'a'; --flag; }
				else if (a[j] == 'a') { 
					char ss;
					if (b[j] == 'b' && abs(flag + 1) <= tag[j]) ss = b[j];
					else if (b[j] == 'b') ss = 'c';
					else ss = 'b';
					cout << ss; flag += (b[j] == ss); }
				else if (b[j] == 'a' && abs(flag + 1) <= tag[j]) { cout << 'a'; ++flag; }
				else if (b[j] == 'a') { 
					char ss;
					if (a[j] == 'b' && abs(flag - 1) <= tag[j]) ss = a[j];
					else if (a[j] == 'b') ss = 'c';
					else ss = 'b';
					cout << ss; flag -= (a[j] == ss); }
			}
		}
		// cout << ' ' << flag;
		cout << '\n';
	}
}