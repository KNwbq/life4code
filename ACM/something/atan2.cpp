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
}cp;

struct Line {
	point p1, p2;
	ld r;
}line1, line2, line3;

ld cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}

bool cmp(Line a, Line b)
{
	if (fabs(a.r - b.r) <= eps)
		return cross(a.p1 - b.p1, b.p2 - b.p1) >= eps;
	else return a.r < b.r;
}

point getcrosspoint(Line a, Line b)
{
	point base = b.p2 - b.p1;
	ld mul = fabs(cross(base, (a.p1 - b.p1))) / (fabs(cross(base, (a.p1 - b.p1))) + fabs(cross(base, (a.p2 - b.p1))));
	return (a.p2 - a.p1) * mul + a.p1;
}

bool onright(point a, Line b)
{
	return cross(a - b.p1, a - b.p2) <= eps;
}

int main()
{
	line1.p1.x = 10; line1.p1.y = 10; line1.p2.x = 0; line1.p2.y = 10;	
	line2.p1.x = 0; line2.p1.y = 5; line2.p2.x = 0; line2.p2.y = 5;
	cp = getcrosspoint(line1, line2);
	cout << cp.x << ' ' << cp.y;
} 
