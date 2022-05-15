#include<iostream>
#include<vector>
using namespace std;


vector<int> arr;
bool Contains(vector<int> &arr, int m, int k) {
	int len = arr.size();
	int tot = 0;
	bool flag = true;
	for (int i = 0; i < len - m; ++i) {
		tot = 0;
		for (int j = i; j < len - m; ++j) {
			flag = true;
			for (int z = 0; z < m; ++z) {
				if (arr[i] != arr[j + z]) { 
					flag = false; 
					break; 
				}
			}
			if (flag) tot += 1;
		}
		if (tot >= k) return true;
	}
	return false;
}

int main() {
	int n, m, k, num;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> num; 
		arr.push_back(num);
	}

	if(Contains(arr, m, k)) cout << "true";
	else cout << "false";
	return 0;
}