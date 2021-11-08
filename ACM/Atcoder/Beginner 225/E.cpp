#include<bits/stdc++.h>
using namespace std;

#define double long long
#define X first
#define Y second

vector<pair<double, double> > point;
const double inf = 0x4f4f4f4f;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		double x, y; cin >> x >> y;
		point.push_back(make_pair(x, y));
	}	
	sort(point.begin(), point.end(), [&](pair<double, double> x, pair<double, double> y) { return x.Y * (y.X - 1) < y.Y * (x.X - 1); } );
	stack<pair<double, double> > ans;
	ans.push(point[0]);
	for (int i = 1; i < point.size(); ++i) {
		// if (point[i].first >= ans.top().second) ans.push(point[i]);
		if ((point[i].Y - 1) * (ans.top().X - 1) >= (ans.top().Y) * (point[i].X)) ans.push(point[i]);
	}
	cout << ans.size();
	return 0;
}

/*
(x-1, y) (x, y-1)
(y - 1) / x, y / (x - 1)
*/