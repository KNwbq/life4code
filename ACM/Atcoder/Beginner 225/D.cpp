#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int n, q, a, b, c; cin >> n >> q;
	vector<int>front(n+1, -1);
	vector<int>behind(n+1, -1);
	while (q--) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			front[c] = b;
			behind[b] = c;
		}
		else if (a == 2) {
			cin >> b >> c;
			front[c] = -1;
			behind[b] = -1;
		}
		else if (a == 3) {
			cin >> b;
			int head = b;
			while (front[head] != -1) {
				head = front[head];
			}
			vector<int> ans;
			for (int i = head; i != -1; i = behind[i]) {
				ans.push_back(i);
			}
			cout << ans.size() << ' ';
			for (int i = 0; i < ans.size(); ++i) {
				cout << ans[i] << (i == (ans.size()-1)?'\n':' ');
			}
		}
	}
	return 0;
}