#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;

struct point{
	double x, y;
}arry[110];

double cross(point a, point b)
{
	return a.x*b.y-a.y*b.x;
}

int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int main()
{
	double area;
	int cases, m, dx, dy, edge, inside;
	cin >> cases;
	for (int i = 1; i <= cases; ++i)
	{
		cout << fixed << setprecision(1);
		area = 0, edge = 0;
		cin >> m;
		for (int j = 0; j < m; ++j)
		{
			cin >> dx >> dy;
			if (j == 0) {arry[j].x = dx; arry[j].y = dy;}
			else {
				arry[j].x = arry[j-1].x + dx;
				arry[j].y = arry[j-1].y + dy;
			}
		}
		for (int j = 0; j < m; ++j) 
		{
			int p = j, q = (j+1)%m;
			area += cross(arry[p], arry[q]);
			edge += abs(gcd(arry[p].x-arry[q].x, arry[p].y-arry[q].y));	
		}
		area = fabs(area)*0.5;
		inside = area - edge*0.5 + 1;
		
		cout << "Scenario #" << i << ":" << endl;
		cout << inside << ' ' << edge << ' ' << area << endl;
		if (i != cases)cout << endl;
	}
	return 0;
}
