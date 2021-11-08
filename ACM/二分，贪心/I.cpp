#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
using namespace std;
const int maxn = 1050;
const double eps = 1e-6;
int n, k;
struct number {
	int a, b;
}arry[maxn];
double sum[maxn];
bool check(double);

int main()
{
	while (cin >> n >> k, n || k)
	{
		for (int i = 0;i < n;++i)cin >> arry[i].a;
		for (int i = 0;i < n;++i)cin >> arry[i].b;
		double lb = 0, ub = 1, mid;
		while (ub - lb > eps)
		{
			mid = (ub + lb) / 2;
			if (check(mid))lb = mid;
			else ub = mid;
		}
		cout << round(mid * 100) << endl;
	}
	return 0;
}

bool check(double x)
{
	double summ = 0;
	for (int i = 0;i < n;++i)sum[i] = arry[i].a - x * arry[i].b;
	sort(sum, sum + n, greater<double>());
	for (int i = 0;i < n - k;++i)summ += sum[i];
	return summ >= 0;
}









