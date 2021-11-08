#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
struct point {
	double x, y;
};
point arry1[1020], arry2[1020];

double dis(point a, point b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool cmp1(point a, point b)
{
	if (a.x != b.x) return a.x < b.x;
	else return a.y < b.y;
}

double cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}

bool cmp2(point a, point b)
{
	a.x = a.x - arry1[0].x;
	a.y = a.y - arry1[0].y;
	b.x = b.x - arry1[0].x;
	b.y = b.y - arry1[0].y;
	if (fabs(cross(a, b)) <= eps)
		return dis(a, arry1[0]) < dis(b, arry1[0]);
	return cross(a, b) > eps;
}

int main()
{
	int N, L, tot = 0;
	double ans = 0;
	cin >> N >> L;
	for (int i = 0; i < N; ++i) cin >> arry1[i].x >> arry1[i].y;
	sort(arry1, arry1 + N, cmp1);
	sort(arry1 + 1, arry1 + N, cmp2); 
	arry2[tot++] = arry1[0];
	arry2[tot++] = arry1[1];
	for (int i = 2; i < N; ++i) {
		while(tot > 1){
		point m, n;
		m.x = arry1[i].x - arry2[tot-2].x;
		m.y = arry1[i].y - arry2[tot-2].y;
		n.x = arry1[i].x - arry2[tot-1].x;
		n.y = arry1[i].y - arry2[tot-1].y;	
		if (cross(m, n) <= 0) --tot;
		else break;
		}
		arry2[tot++] = arry1[i];
	}
	for (int i = 0; i < tot; ++i) ans += sqrt(dis(arry2[i], arry2[(i + 1) % tot]));
	ans += 2 * pi * L;
	cout << (int)(ans+0.5);
	return 0;
}
