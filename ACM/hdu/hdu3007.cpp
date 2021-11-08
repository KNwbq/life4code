#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
const int maxn = 520;
const double eps = 1e-8;

struct point {
	double x, y;
	point(){}
	point(double xx, double yy) :x(xx), y(yy) {};
	friend point operator +(point a, point b) {
		return point(a.x + b.x, a.y + b.y);
	}
	friend point operator /(point a, int m) {
		return point(a.x / m, a.y / m);
	}
}arry[maxn];

point geto(point a, point b, point c)
{
	point res;
	double a1 = 2 * (b.x - a.x), b1 = 2 * (b.y - a.y), c1 = b.x * b.x + b.y * b.y - a.x * a.x - a.y * a.y;
	double a2 = 2 * (c.x - b.x), b2 = 2 * (c.y - b.y), c2 = c.x * c.x + c.y * c.y - b.x * b.x - b.y * b.y;
	res.x = (c1 * b2 - b1 * c2) / (a1 * b2 - b1 * a2);
	res.y = (a1 * c2 - c1 * a2) / (a1 * b2 - b1 * a2);
	return res;
}

double dist(point a, point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int sgn(double x)
{
	if (fabs(x) <= eps) return 0;
	else if (x > eps) return 1;
	else if (x < eps) return -1;
}

int main()
{
	int N;
	while (cin >> N, N)
	{
		cout << fixed << setprecision(2);
		for (int i = 0; i < N; ++i) cin >> arry[i].x >> arry[i].y;
		point o = arry[0]; double r = 0;
		for (int i = 1; i < N; ++i)
		{
			if (sgn(dist(o, arry[i]) - r) > 0)
			{
				o = arry[i]; r = 0;
				for (int p = 0; p < i; ++p)
				{
					if (sgn(dist(o, arry[p]) - r) > 0) {
						o = (arry[i] + arry[p]) / 2; r = dist(arry[i], arry[p]) / 2;
						for (int j = 0; j < p; ++j)
						{
							if (sgn(dist(o, arry[j]) - r) > 0) {
								o = geto(arry[i], arry[p], arry[j]); r = dist(o, arry[i]) / 2;
							}
						}
					}
						
				}
			}
		}
		cout << o.x << ' ' << o.y << ' ' << r << endl;
	}
}

