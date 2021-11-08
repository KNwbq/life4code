#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1e5 + 20;
char arry[maxn];
int dp[maxn];

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; ++i) {
		memset(arry, '\0', sizeof(arry));
		memset(dp, -1, sizeof(dp));
		cin >> arry;
		if (strlen(arry) == 1) {
			if (arry[0] = '1') cout << 'T' << endl;
			else cout << 'X' << endl;
		}
		dp[0] = (arry[0] == '1' ? 1 : 0);
		for (int i = 1; i < strlen(arry); ++i) {
			if (arry[i] == '0') dp[i] = dp[i-1];
			else {
				if (dp[i-1] == 1) {
					dp[i] = i % 2;
				}
				else {
					dp[i] = 1 - (i % 2);
				}
			}	
		}
		if (dp[strlen(arry)-1]) cout << 'T' << endl;
		else cout << 'X' << endl;
	}
	return 0;
}