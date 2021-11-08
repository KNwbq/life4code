#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef long double ld;
const int maxn = 20020;
const ld eps = 1e-10;
struct point {
	ld x, y;
	point() {}
	point(ld _x, ld _y) :x(_x), y(_y) {}
	friend point operator -(point a, point b) {
		return point(a.x - b.x, a.y - b.y);
	}
	friend point operator +(point a, point b) {
		return point(a.x + b.x, a.y + b.y);
	}
	friend point operator *(point a, ld m) {
		return point(a.x * m, a.y * m);
	}
}cp[maxn];

int sign(ld x)
{
	if (fabs(x) <= eps)return 0;
	else if (x > eps)return 1;
	else if (x < eps)return -1;
}

struct Line {
	point p1, p2;
	ld r;
}line1[maxn], line2[maxn];

ld cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}

bool cmp(Line a, Line b)
{
	int res = sign(a.r - b.r);
	return res == 0 ? cross(a.p1 - b.p1, b.p2 - b.p1) <= eps : res < 0;
}

point getcrosspoint(Line a, Line b)
{
	ld t = cross(b.p1 - a.p1, b.p2 - b.p1);
	t /= cross(a.p2 - a.p1, b.p2 - b.p1);
	return a.p1 + (a.p2 - a.p1) * t;
}

bool onright(point a, Line b)
{
	return cross(a - b.p1, a - b.p2) <= eps;
}

int main()
{
	cout << fixed << setprecision(1);
	int N;
	while (cin >> N) {
		int lhead = 0, phead = 0, ltail = 0, ptail = 0;
		bool peg = true;
		ld ans = 0;
		for (int i = 0; i < N; ++i) cin >> line1[i].p1.x >> line1[i].p1.y >> line1[i].p2.x >> line1[i].p2.y;
		line1[N].p1.x = 0; line1[N].p1.y = 10000; line1[N].p2.x = 0; line1[N].p2.y = 0;
		line1[++N].p1.x = 0; line1[N].p1.y = 0; line1[N].p2.x = 10000; line1[N].p2.y = 0;
		line1[++N].p1.x = 10000; line1[N].p1.y = 0; line1[N].p2.x = 10000; line1[N].p2.y = 10000;
		line1[++N].p1.x = 10000; line1[N].p1.y = 10000; line1[N].p2.x = 0; line1[N].p2.y = 10000;
		for (int i = 0; i < N + 1; ++i)line1[i].r = atan2(line1[i].p2.y - line1[i].p1.y, line1[i].p2.x - line1[i].p1.x);
		sort(line1, line1 + N + 1, cmp);
		line2[ltail] = line1[0];
		for (int i = 1; i < N + 1; ++i)
		{
			if (sign(line1[i].r - line1[i - 1].r) == 0)continue;
			while (ltail > lhead && onright(cp[ptail], line1[i]))
			{
				--ptail;
				--ltail;
			}
			while (ltail > lhead && onright(cp[phead], line1[i]))
			{
				++phead;
				++lhead;
			}
			line2[++ltail] = line1[i];
			if (peg)
			{
				cp[ptail] = getcrosspoint(line2[ltail], line2[ltail - 1]);
				peg = false;
			}
			else cp[++ptail] = getcrosspoint(line2[ltail], line2[ltail - 1]);
		}
		while (ltail > lhead && onright(cp[ptail], line2[lhead]))
		{
			--ptail;
			--ltail;
		}
		while (ltail > lhead && onright(cp[phead], line2[ltail]))
		{
			++phead;
			++lhead;
		}
		cp[++ptail] = getcrosspoint(line2[ltail], line2[lhead]);
		if (ptail - phead < 2)
		{
			cout << 0.0 << endl;
			continue;
		}
		for (int i = 0; i < ptail - phead + 1; ++i) ans += cross(cp[phead + i], cp[phead + (i + 1) % (ptail - phead + 1)]);
		ans = fabs(ans) / 2;
		cout << ans << endl;
	}
	return 0;
}
