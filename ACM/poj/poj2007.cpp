#include<iostream>
#include<algorithm>
using namespace std;
const double eps = 1e-10;

struct point {
	double x, y;
}arry[55];

bool cmp(point a, point b)
{
	return a.x * b.y - a.y * b.x > eps;
}

int main()
{
	int tot = 0;
	while (cin >> arry[tot].x >> arry[tot].y)
	{
		tot++;
	}
	sort(arry + 1, arry + tot, cmp);
	for (int i = 0; i < tot; ++i)
		cout << '(' << arry[i].x << ',' << arry[i].y << ')' << endl;
	return 0;
}
