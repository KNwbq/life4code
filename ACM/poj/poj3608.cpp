#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
const int maxn = 10010;
const double eps = 1e-8;
struct point{
	double x, y;
	point(){}
	point(double xx, double yy):x(xx), y(yy){}
	friend point operator -(point a, point b)
	{
		return point(a.x - b.x, a.y - b.y);
	}
}arry1[maxn], arry2[maxn];

double cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}

double dot(point a, point b)
{
	return a.x * b.x + a.y * b.y;
}

double dist(point a, point b)
{
	return (a - b).x * (a - b).x + (a - b).y * (a - b).y;
}

bool cmp(point a, point b)
{
	if(a.x != b.x)return a.x < b.x;
	else return a.y < b.y;	
} 

bool cmp1(point a, point b)
{
	if(fabs(cross(a - arry1[0], b - arry1[0])) <= eps)
		return dist(a, arry1[0]) < dist(b, arry1[0]);
	else return cross(a - arry1[0], b - arry1[0]) > 0;
}

bool cmp2(point a, point b)
{
	if(fabs(cross(a - arry2[0], b - arry2[0])) <= eps)
		return dist(a, arry2[0]) < dist(b, arry2[0]);
	else return cross(a - arry2[0], b - arry2[0]) > 0;
}

double mind(point p, point a, point b)
{
	double r = dot(p - a, b - a);
	if(r <= eps)
	return sqrt(dist(p, a));
	double d = dist(a, b);
	
	if(r >= d)
	return sqrt(dist(p, b));
	return fabs(cross(a - p, b - p))/sqrt(d);
}

int main()
{
	int N, M;
	while (cin >> N >> M, N||M)
	{
		cout << fixed << setprecision(5);
		double ans = 1e10;
		int j = 0;
		for (int i = 0; i < N; ++i) cin >> arry1[i].x >> arry1[i].y;
		for (int i = 0; i < M; ++i) cin >> arry2[i].x >> arry2[i].y;
		sort(arry1, arry1 + N, cmp);
		sort(arry2, arry2 + M, cmp);
		sort(arry1 + 1, arry1 + N, cmp1);
		sort(arry2 + 1, arry2 + M, cmp2);
		for(int i = 0; i < N; ++i)
		{
			while(cross(arry1[i] - arry2[j], arry1[(i+1)%N] - arry2[j]) < cross(arry1[i] - arry2[(j+1)%M], arry1[(i+1)%N] - arry2[(j+1)%M]))
			j = (j+1)%M;
			ans = min(ans, mind(arry2[j], arry1[i], arry1[(i+1)%N]));
			ans = min(ans, mind(arry2[(j+1)%M], arry1[i], arry1[(i+1)%N])); 	
		} 
		j = 0;
		for(int i = 0; i < M; ++i)
		{
			while(cross(arry2[i] - arry1[j], arry2[(i+1)%M] - arry1[j]) < cross(arry2[i] - arry1[(j+1)%N], arry2[(i+1)%M] - arry1[(j+1)%N]))
			j = (j+1)%N;
			ans = min(ans, mind(arry1[j], arry2[i], arry2[(i+1)%M]));
			ans = min(ans, mind(arry1[(j+1)%N], arry2[i], arry2[(i+1)%M])); 	
		} 
		cout << ans << endl;
	}
}
