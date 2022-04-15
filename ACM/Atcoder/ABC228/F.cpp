#include<bits/stdc++.h>
using namespace std;
const int modu = 998244353, _ = 5, maxn = 1000;
using LL = long long;

int H, W, h1, w1, h2, w2;
LL a[maxn+_][maxn+_];
deque<int> q[maxn+_];

LL cal(int i, int j) {
	return a[i][j] - a[i-h2][j] - a[i][j-w2] + a[i-h2][j-w2];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> H >> W >> h1 >> w1 >> h2 >> w2;
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= H; ++i)
		for (int j = 1; j <= W; ++j) {
			cin >> a[i][j];
			a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
		}
	if (h1 <= h2 && w1 <= w2) cout << 0;
	else {
		LL ans = 0;
		w2 = min(w2, w1);
		h2 = min(h2, h1);
		for (int i = h2; i <= H; ++i) {
			for (int j = w2; j <= W; ++j) {
				while (!q[j].empty() && cal(q[j].back(), j) <= cal(i, j)) q[j].pop_back();
				q[j].push_back(i);
			}
			if (i >= h1) {
				deque<int> qq;
				for (int j = w2; j <= W; ++j) {
					while (!q[j].empty() && i-q[j].front() > h1-h2) q[j].pop_front();
					while (!qq.empty() && cal(q[qq.back()].front(), qq.back()) <= cal(q[j].front(), j)) qq.pop_back();
					qq.push_back(j);
					while (!qq.empty() && j - qq.front() > w1-w2) qq.pop_front();
					if (j >= w1)
						ans = max(ans, a[i][j] - a[i-h1][j] - a[i][j-w1] + a[i-h1][j-w1] - cal(q[qq.front()].front(), qq.front()));
				}
			}
		}
		cout << ans;
	}
	return 0;
}