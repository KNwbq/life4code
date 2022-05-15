// vector
// #include<vector>
// #include<iostream>
// #include<algorithm>
// using namespace std;

// const int maxn = 10;

// void func(vector<int> v0) {
// 	for (vector<int>::iterator it = v0.begin(); it != v0.end(); ++it) 
// 		cout << *it << ' ';
// 	cout << endl;
// }

// int main() {
// 	vector<int> v1(maxn, 1);
// 	vector<int> v0(maxn, 0);
// 	// cout << v0.end() - v0.begin() << endl;
// 	int new_size = unique(v0.begin(), v0.end()) - v0.begin();
// 	cout << new_size << endl;
// 	v0.insert(v0.begin(), 1);
// 	// func(v0);
// 	// v0.insert(v0.begin(), 2, 1);
// 	// func(v0);
// 	// v0.insert(v0.end(), v1.begin(), v1.end());
// 	// func(v0);
// 	v0.insert(v0.end(), {10, 56});
// 	// func(v0);
// 	// v0.pop_back();
// 	v0.erase(v0.end()-1);
// 	// v0.erase(v0.begin(), v0.end());
// 	v0.erase(remove(v0.begin(), v0.end(), 0), v0.end());
// 	func(v0);
// 	v0.insert(v0.begin(), 3, 5);
// 	func(v0);
// 	cout << find(v0.begin(), v0.end(), 10) - v0.begin();
// 	return 0;
// }

// set
// #include<set>
// #include<iostream>
// #include<algorithm>
// using namespace std;

// int main() {
// 	set<int, greater<int> > s0;
// 	s0.insert(1);
// 	s0.insert(2);
// 	s0.insert(0);
// 	for (set<int, greater<int> >::iterator it = s0.begin(); it != s0.end(); ++it)
// 		cout << *it << ' ';
// 	cout << endl;
// 	auto it = s0.find(-1);
// 	if (it != s0.end()) cout << '*' << endl;
// 	cout << s0.count(-1);
// 	return 0;
// }

// map
// #include<map>
// #include<iostream>
// using namespace std;

// int main() {
// 	map<pair<int, int>, int> m0;
// 	map<string, int> m1;
// 	m0.insert({{1, 1}, 1});
// 	m0.insert({{2, 1}, 2});
// 	m0.insert({{3, 1}, 3});
// 	m0.insert({{1, 2}, 0});
// 	m0.insert({{1, 0}, 0});
// 	m1.insert({"a", 2});
// 	m0.erase(m0.find({1, 1}));
// 	m0.erase({2, 1});
// 	for (const auto& [x, y]: m0) {
// 		cout << x.first << ' ' << x.second << ' ' << y << endl;
// 	}
// 	return 0;
// }

// unordered_map
// #include<unordered_map>
// #include<iostream>
// using namespace std;

// int main() {
// 	unordered_map<string, int> u0{
// 		{"abc", 2},
// 		{"aaa", 3}
// 	};
// 	u0.insert({"aaaa", 4});
// 	u0.emplace("bbb", 4);
// 	u0.erase("aaa");
// 	u0.erase(u0.find("abc"));
// 	++u0["bbb"];
// 	for (const auto& [k, v]: u0) {
// 		cout << k << ' ' << v << endl;
// 	} 
// 	return 0;
// }

//stack
// #include<stack>
// #include<iostream>
// using namespace std;

// int main() {
// 	stack<int> s0;
// 	s0.push(1);
// 	s0.push(1);
// 	s0.push(2);
// 	s0.push(1);
// 	while (!s0.empty()) {
// 		cout << s0.top() << ' ';
// 		s0.pop();
// 	}
// 	return 0;
// }

//queue
// #include<iostream>
// #include<queue>
// using namespace std;

// int main() {
// 	queue<int> q0;
// 	q0.push(2);
// 	q0.push(1);
// 	q0.push(3);
// 	q0.push(4);
// 	while (!q0.empty()) {
// 		cout << q0.back() << ' ';
// 		q0.pop();
// 	}
// 	return 0;
// }

//priority_queue
// #include<queue>
// #include<iostream>
// #include<string>
// using namespace std;

// priority_queue<string, vector<string>, greater<string> > p0;
// priority_queue<string, vector<string>, greater<string> > p0;

// int main() {
// 	p0.push("a");
// 	p0.push("aa");
// 	p0.push("b");
// 	p0.push("bbb");
// 	while (!p0.empty()) {
// 		cout << p0.top() << ' ';
// 		p0.pop();
// 	}
// 	return 0;
// }

#include<bits/stdc++.h>
using namespace std;

vector<int> alg{12, 13, 14, 2, 3, 20, 18,  1, 7, 16};
vector<int> name{23, 2, 17};

int main() {
	int ans = 10000, pos = 0;
	for (int i = 0; i <= alg.size() - 3; ++i) {
		int res = pow(alg[i] - name[0], 2) + pow(alg[i+1] - name[1], 2) + pow(alg[i+2] - name[2], 2);
		if (res < ans) {
			ans = res;
			pos = i;
		}
	}
	cout << pos;

}

