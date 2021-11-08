#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

const double eps = 1e-2;
const int maxn = 105;
const double pi = acos(-1);

struct node {
	double a, b;
	node() {};
	node(double aa, double bb): a(aa), b(bb) {};
}ab[maxn], cd[maxn], abbuff[maxn];

bool cmp(node a, node b) {
	if (a.a != b.a) return a.a < b.a;
	else return a.b < b.b;
}

double dis(node a, node b) {
	return sqrt((a.a - b.a)*(a.a - b.a) + (a.b - b.b)*(a.b - b.b));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	double xx, yy, last, cur;
	for (int i = 0; i < N; ++i) { cin >> xx >> yy; ab[i] = node(xx, yy); }
	for (int i = 0; i < N; ++i) { cin >> xx >> yy; cd[i] = node(xx, yy); }
	if (N == 1) { cout << "Yes"; return 0; }
	sort(cd, cd+N, cmp);
	for (double degree = eps; degree < 360; degree += eps) {
		bool flag = true;
		for (int i = 0; i < N; ++i) 
			abbuff[i] = node(ab[i].a*cos(degree*pi/180) - ab[i].b*sin(degree*pi/180), ab[i].a*sin(degree*pi/180) + ab[i].b*cos(degree*pi/180));
		sort(abbuff, abbuff+N, cmp);
		double tagx = abbuff[0].a - cd[0].a, tagy = abbuff[0].b - cd[0].b;
		for (int i = 1; i < N; ++i) {
			double buffx = abbuff[i].a - cd[i].a, buffy = abbuff[i].b - cd[i].b;
			if (abs(tagx - buffx) > eps || abs(tagy - buffy) > eps) { flag = false; break;}
		}
		if (flag) { cout << "Yes"; return 0; }
	}
	cout << "No"; return 0; 
}