#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 100100;
struct leg {
	double r, l, index;
}arry[maxn];

int main()
{
	int n;
	double resl = 0, resr = 0, ans, flag = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		arry[i].index = i + 1;
		cin >> arry[i].l >> arry[i].r;
		resl +=arry[i].l;
		resr +=arry[i].r; 
	}
	ans = fabs(resl-resr);
	for(int i = 0; i < n; ++i)
	{
		if(ans < fabs(resl-resr-2*arry[i].l+2*arry[i].r))
		{
			ans = fabs(resl-resr-2*arry[i].l+2*arry[i].r);
			flag = arry[i].index;			
		}
	}
	cout << flag;
	return 0;
}
