#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
// void debug() {
// 	cerr << endl;
// }
 
// template<typename Head, typename... Tail>
// void debug(Head H, Tail... T) {
// 	cerr << " " << H;
// 	debug(T...);
// }
 
// #define dbg(args...) cerr << "[" << #args << "]: ", debug(##args)

#define LL long long

const int maxn = 2e5 + 20;
LL cnt[4 * maxn], ans[4 * maxn], nums[4 * maxn];
int a[maxn], b[maxn];
vector<LL> ab;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin  >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		b[i] += (a[i] - 1);
		ab.push_back(a[i]); ab.push_back(b[i]);
	}
	sort(ab.begin(), ab.end());
	ab.erase(unique(ab.begin(), ab.end()), ab.end());
	int len = ab.size();

	for (int i = 1; i < len; ++i) {
		nums[2 * i] = ab[i] - ab[i-1] - 1;
	}

	for (int i = 0; i < n; ++i) {
		int aa = lower_bound(ab.begin(), ab.end(), a[i]) - ab.begin();
		int bb = lower_bound(ab.begin(), ab.end(), b[i]) - ab.begin();
		cnt[2 * aa + 1]++; cnt[2 * bb + 2]--;
	}

	for (int i = 1; i <= 2 * len; ++i) cnt[i] += cnt[i-1];
	for (int i = 0; i < len; ++i) {
		ans[cnt[2*i + 1]] += 1;
		ans[cnt[2*i]] += nums[2*i];
	}
	for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
	return 0;
}