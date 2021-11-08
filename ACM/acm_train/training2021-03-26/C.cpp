#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
const int maxn = 1e3;
LL f[maxn];

int main() {
    LL N; cin >> N;
    int cnt = 0;
    f[0] = 1; f[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        f[i] = f[i-1] + f[i-2];
        ++cnt;
        if (f[i-1] > N && N <= f[i]) { cout << cnt; return 0; }
    }

}