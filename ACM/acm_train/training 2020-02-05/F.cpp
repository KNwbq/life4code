#include<iostream>
#include<string>
#define ll long long
using namespace std;

const int maxn = 1e6 + 10;
string s[maxn], buff;

int main()
{
	ios::sync_with_stdio(0);
	int n, tot = 0; cin >> n;
	bool pzo = false, findu = false;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		if (s[i][0] == '0') pzo = true;

		else if(!findu) {
			int cnt = 0;
			for (int j = 0; j < s[i].length(); ++j) 
				{ if(s[i][j] == '1') ++cnt; if(cnt > 1 || (s[i][j] != '1' && s[i][j] != '0')) { buff = s[i]; findu = true; break; } }
			if(!findu) tot += s[i].length() - 1;
		}
		else { tot += s[i].length() - 1; }
	}
	if(pzo) { cout << 0; cout << endl; }
	else if(findu) { cout << buff; for (int i = 0; i < tot; ++i) cout << 0; cout << endl; }
	else { cout << 1; for (int i = 0; i < tot; ++i) cout << 0; cout << endl; }
	return 0;
}