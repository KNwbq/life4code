#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1020;

int main() {
    int n, m;
    while (cin >> n >> m) {
        int num[maxn];
        for (int i = 1; i <= n; ++i) {
            num[i-1] = i;
        }
        while (--m) next_permutation(num, num+n);
        cout << num[0];
        for (int i = 1; i < n; ++i) cout << ' ' << num[i];
        cout << endl;
    }
}