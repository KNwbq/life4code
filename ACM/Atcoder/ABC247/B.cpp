#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

unordered_map<string, int> nick;
vector<pair<string, string> > name;

int main() {
	int n;
	string a, b;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		name.push_back({a, b});
		if (a == b) {
			if (nick.count(a) == 0) nick.insert({a, 1});
			else if (nick.count(a) > 0) nick[a] = 0;
			continue;
		}
		if (nick.count(a) == 0) nick.insert({a, 1});
		else if (nick.count(a) > 0) nick[a] = 0;
		if (nick.count(b) == 0) nick.insert({b, 1});
		else if (nick.count(b) > 0) nick[b] = 0;
	}
	for (const auto& [a, b]: name) {
		if (nick[a] > 0) nick[a] = 0;
		else if (nick[b] > 0) nick[b] = 0;
		else {
			cout << "No"; return 0;
		} 
	}
	cout << "Yes";
	return 0;
}