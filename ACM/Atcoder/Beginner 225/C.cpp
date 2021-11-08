#include<iostream>
using namespace std;
const int maxn = 1e4 + 10, maxn2 = 10;
int mat[maxn][maxn2], buff[maxn][maxn2];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	bool flag = false;
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> mat[i][j];
			buff[i][j] = mat[i][j] / 7 - (mat[i][j] % 7 == 0);
			mat[i][j] %= 7;
			if (i == 1) {
				if (j > 1 && ((mat[i][j] - mat[i][j-1] + 7) % 7 != 1 || buff[i][j] != buff[i][j-1])) flag = true;
			}
			else {
				if ((j > 1 && ((mat[i][j] - mat[i][j-1] + 7) % 7 != 1 || buff[i][j] != buff[i][j-1])) || buff[i][j] - buff[i-1][j] != 1) flag = true;
			}
		}
	}
	if (flag) cout << "No";
	else cout << "Yes";
	return 0;
}

/*
1 2 3 4 5 6 7
8 9 10 11 12 13 14
*/