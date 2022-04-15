// #include <bits/stdc++.h>
// using namespace std;

// int n;
// string ans;

// int qpow(int a, int b) {
// 	int res = 1;
// 	for (a %= 7; b; b >>= 1, a = a*a%7)
// 		if (b & 1) res = res * a % 7;
// 	return res;
// }

// int main() {
// 	cin >> n;
// 	const int inv[7] = {0, 1, 4, 5, 2, 3, 6};
// 	int tmp = (1 + sqrt(1 + 8*n)) / 2;
// 	if (tmp * (tmp - 1) / 2 == n) {
// 		for (int i = 1; i < tmp; ++i) cout << "7";
// 		return 0;
// 	}
// 	for (int i = 2000; i >= 1; --i) if (n >= i*(i-1)/2) {
// 		for (int j = i; j >= 1; --j) if (n >= i*(i-1)/2 + j*(j-1)/2) {
// 			int k = (1 + sqrt(1+8*(n - i*(i-1)/2 - j*(j-1)/2))) / 2;
// 			if (n == i*(i-1)/2 + j*(j-1)/2 + k*(k-1)/2) {
// 				if (k > 1) {
// 					ans.append(k-1, '7');
// 					ans.append(1, char('0'+inv[qpow(10, i+j-1)]%7));
// 				}
// 				ans.append(j-1, '7');
// 				ans.append(1, char('0'+inv[qpow(10, i-1)]));
// 				ans.append(i-1, '7');
// 				// cerr << i << " " << j << " " << k <<  " " << i*(i-1)/2 + j*(j-1)/2 + k*(k-1)/2 << endl;
// 				break;
// 			}
// 		}
// 		if (ans.size()) break;
// 	}
// 	cout << ans << endl;
// }

#include <bits/stdc++.h>
using namespace std;

int n;
string ans;

int main() {
	cin >> n;
	int tmp = (1 + sqrt(1 + 8*n)) / 2;
	if (tmp * (tmp - 1) / 2 == n) {
		for (int i = 1; i < tmp; ++i) cout << "7";
		return 0;
	}
	for (int i = 2000; i >= 2; --i) if (n >= i*(i-1)/2) {
		for (int j = i; j >= 2; --j) if (n >= i*(i-1)/2 + j*(j-1)/2) {
			int k = (1 + sqrt(1+8*(n - i*(i-1)/2 - j*(j-1)/2))) / 2;
			if (n == i*(i-1)/2 + j*(j-1)/2 + k*(k-1)/2) {
				ans.append(i-1, '7');
				ans.append(1, '1');
				ans.append(j-1, '7');
				if (k > 1) {
					if ((j-1)%6 == 2) {
						ans.append(1, '2');
						ans.append(k-1, '7');

					}
					else {
					ans.append(1, '1');
					ans.append(k-1, '7');}
				}
				// cerr << i << " " << j << " " << k <<  " " << i*(i-1)/2 + j*(j-1)/2 + k*(k-1)/2 << endl;
				break;
			}
		}
		if (ans.size()) break;
	}
	cout << ans << endl;
}