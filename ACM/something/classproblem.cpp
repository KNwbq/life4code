#include<iostream>
#include<cmath>
using namespace std;
const int maxn_l = 10000;
const int maxn = 100;

double graph[maxn][maxn];
double lowcost[maxn];
int mst[maxn],  sise = 11;

void init() {
	for (int i = 0; i < maxn; ++i) 
		for (int j = 0; j < maxn; ++j)
			graph[i][j] = maxn_l;
}

void prime() {
	double minx;
	int minid;
	double ans = 0;
	for (int i = 2; i <= sise; ++i) {
		lowcost[i] = graph[1][i];
		mst[i] = 1;
	}
	mst[1] = 0;
	for (int i = 2; i <= sise; ++i) {
		minx = maxn_l;
		minid = 0;
		for (int j = 2; j <= sise; ++j) {
			if (lowcost[j] < minx && lowcost[j] != 0)
			{
				minx = lowcost[j];
				minid = j;
			}
		}
		ans += minx;
		cout << char(mst[minid]-1+'A') << ' ' << char(minid-1+'A') << endl;
		lowcost[minid] = 0;
		for (int j = 2; j <= sise; ++j)
		{
			if (graph[minid][j] < lowcost[j]) {
				lowcost[j] = graph[minid][j];
				mst[j] = minid;
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	init();
	int p1, p2; double x, xx, y, yy;
	while (cin >> p1 >> x >> y >> p2 >> xx >> yy) {
		
		graph[p1][p2] = sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy)); 
		graph[p2][p1] = sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
	}
	prime();
	system("pause");
	return 0;
}
