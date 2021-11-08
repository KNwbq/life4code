#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, T, a, ans = 0;
    cin >> T;
    while (T--) {
        cin >> n; ans = 0;
        while (cin >> a) {
            if (a%2) ++ans;
        }
        cout << ans << endl;
    }
}