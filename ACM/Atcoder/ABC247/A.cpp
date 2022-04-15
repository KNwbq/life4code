#include<iostream>
#include<cstring>
using namespace std;

int main() {
	string s;
	cin >> s;
	s = "0" + s.substr(0, s.length()-1);
	cout << s;
	return 0;
}