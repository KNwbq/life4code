#include<bits/stdc++.h>
using namespace std;

int main() {
	int arry[3] = {1, 2, 3};
	cout << lower_bound(arry, arry+3, 2.5) - arry;
}