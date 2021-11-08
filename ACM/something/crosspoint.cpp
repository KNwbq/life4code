#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<deque>
#define maxl 20010
#define eps 1e-8
#include<iostream>
 
using namespace std;
 
inline int sgn(double x)
{
	if(x>-eps && x<eps) return 0;
	if(x>0) return 1;
	else	return -1;
}
 
struct point
{
	double x,y;
	point(double a=0,double b=0)
	{
		x=a,y=b;
	}
	point operator + (const point &b)const
	{
		return point(x+b.x,y+b.y);
	}
	point operator - (const point &b)const
	{
		return point(x-b.x,y-b.y);
	}
	friend point operator * (const double &t,const point &a)
	{
		return point(t*a.x,t*a.y);
	}
	inline double norm()
	{
		return sqrt(x*x+y*y);
	}
};
inline double dot(const point &a,const point &b)
{
	return a.x*b.x+a.y*b.y;
}
inline double det(const point &a,const point &b)
{
	return a.x*b.y-a.y*b.x;
}
 
struct halfplane
{// s->e on the left
	point s,e;
	halfplane(point a=point(),point b=point())
	{
		s=a;e=b;
	}
};
 
inline bool satisfy(point a,const halfplane L)
{
	return sgn(det(a-L.s,L.e-L.s))<=0;
}
point crosspoint(const halfplane &a,const halfplane &b)
{
	double t=det(b.s-a.s,b.e-b.s);
	t=t/det(a.e-a.s,b.e-b.s);
	return a.s+t*(a.e-a.s);
}
inline double arg(const point vec)
{
	return atan2(vec.y,vec.x);
}
inline bool cmp(const halfplane &a,const halfplane &b)
{
	int res=sgn(arg(a.e-a.s)-arg(b.e-b.s));
	return res==0 ? satisfy(a.s,b) : res<0;
}
vector<point> halfplaneIntersection(vector<halfplane> v)
{
	sort(v.begin(),v.end(),cmp);
	deque<halfplane> q;
	deque<point> ans;
	q.push_back(v[0]);
	int l=v.size();
	for(int i=1;i<l;i++)
	{
		if(sgn(arg(v[i].e-v[i].s)-arg(v[i-1].e-v[i-1].s))==0)
			continue;
		while(ans.size()>0 && !satisfy(ans.back(),v[i]))
		{
			ans.pop_back();
			q.pop_back();
		}
		while(ans.size()>0 && !satisfy(ans.front(),v[i]))
		{
			ans.pop_front();
			q.pop_front();
		}
		ans.push_back(crosspoint(q.back(),v[i]));
				q.push_back(v[i]);
	}
	while(ans.size()>0 && !satisfy(ans.back(),q.front()))
	{
		ans.pop_back();
		q.pop_back();
	}
	while(ans.size()>0 && !satisfy(ans.front(),q.back()))
	{
		ans.pop_front();
		q.pop_front();
	}
	ans.push_back(crosspoint(q.back(),q.front()));
	return vector<point>(ans.begin(),ans.end());
}
 
int n;
vector<halfplane> a;
vector<point> res;
double ans;
const double inf=10000;
 
inline void prework()
{
	a.resize(n);
	for(int i=0;i<n;i++)
		scanf("%lf%lf%lf%lf",&a[i].s.x,&a[i].s.y,&a[i].e.x,&a[i].e.y);
	++n;a.push_back(halfplane(point(0,0),point(inf,0)));
	++n;a.push_back(halfplane(point(inf,0),point(inf,inf)));
	++n;a.push_back(halfplane(point(inf,inf),point(0,inf)));
	++n;a.push_back(halfplane(point(0,inf),point(0,0)));
}
 
inline double area(vector<point> &a)
{
	double sum=0;int n=a.size();
	for(int i=0;i<n;i++)
		sum+=det(a[(i+1)%n],a[i]);
	return fabs(sum/2);
}
 
inline void mainwork()
{
	res=halfplaneIntersection(a);
	ans=area(res);
}
 
inline void print()
{
	printf("%.1f",ans);
}
 
int main()
{
	while(~scanf("%d",&n))
	{
		prework();
		mainwork();
		print();
	}
	return 0;
}
