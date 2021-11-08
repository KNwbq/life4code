#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps = 1e-10;
const int maxn = 50020;
struct point{
	double x, y;
	point(){}
	point(double _x,double _y):x(_x),y(_y){}
	friend point operator -(point a,point b){
		return point(a.x-b.x,a.y-b.y);
	}
}arry1[maxn], arry2[maxn];

double dist(point a, point b)
{
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

double cross(point a, point b)
{
	return a.x*b.y - a.y*b.x;
}

bool cmp1(point a, point b)
{
	if (a.x != b.x)return a.x < b.x;
	else return a.y < b.y;	
} 

bool cmp2(point a, point b)
{
	if (fabs(cross(a - arry1[0], b - arry1[0])) <= eps)
    	return dist(a, arry1[0]) < dist(b, arry1[0]);
    else return cross(a - arry1[0], b - arry1[0]) > eps;
}

int main()
{
	int N, tot = 0, j = 2;
	double ans = 0;
	cin >> N;
	if (N > 2){
		for (int i = 0; i < N; ++i) cin >> arry1[i].x >> arry1[i].y;
	sort(arry1, arry1 + N, cmp1);
	sort(arry1 + 1, arry1 + N, cmp2);
	arry2[tot++] = arry1[0];
	arry2[tot++] = arry1[1];
	for(int i = 2; i < N; ++i)
	{
		while(tot > 1 && cross(arry1[i] - arry2[tot - 2], arry1[i] - arry2[tot - 1]) <= eps)--tot;
		arry2[tot++] = arry1[i];
	}
	for(int i = 0; i < N; ++i)
	{
		while(cross(arry2[i] - arry2[j], arry2[(i+1)%tot] - arry2[j]) < cross(arry2[i] - arry2[(j+1)%tot], arry2[(i+1)%tot] - arry2[(j+1)%tot]))
		j = (j+1)%tot;
		ans = max(ans, dist(arry2[j], arry2[i]));
		ans = max(ans, dist(arry2[j], arry2[(i+1)%tot]));
	}
	cout << (int)ans;
	}
	else {
		for (int i = 0; i < N; ++i) cin >> arry1[i].x >> arry1[i].y;
		ans = dist(arry1[0], arry1[1]);
		cout << (int)ans;
	}
	return 0;
}

