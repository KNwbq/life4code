#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 10000;
struct point{
	double x, y;
}arry[maxn];

double cross(point a, point b)
{
	return a.x*b.y-a.y*b.x;
}

int main()
{
	int n, res;
	double ans;
	while (cin >> n, n)
	{
		ans = 0;
		for (int i = 0; i < n; ++i)cin >> arry[i].x >> arry[i].y;
		if (n == 1 || n == 2) cout << 0 << endl;
		else {
			for(int i = 0; i < n; ++i)ans += cross(arry[i], arry[(i+1)%n]);
			res = (int)(fabs(ans/2)+0.5);
			cout << res<< endl;
		}
	}
}
