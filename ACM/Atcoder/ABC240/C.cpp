#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 120;
const int maxc = 10050;
int arry[maxn];
bool noflag[maxc];
bool vis[maxn];
int n, x, a, b;

bool rec_subset(int* arr, int i, int s) {
	if (s == 0) return true;
	else if (s < 0) return false;
	else if (i == 0) return arr[i] == s;
	else {
		int A = rec_subset(arr, i - 1, s);
		int B = rec_subset(arr, i - 1, s - arr[i]);
		return A || B;
	}
}

int main() {
	memset(vis, 0, sizeof(vis));
	memset(noflag, 0, sizeof(noflag));
	cin >> n >> x;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		x -= a;
		arry[i] = b - a;
	}
	if (rec_subset(arry, n-1, x)) cout << "Yes";
	else cout << "No";
	return 0;
}