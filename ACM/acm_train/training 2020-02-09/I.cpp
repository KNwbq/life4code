#include<iostream>
using namespace std;

int main()
{
	int n, ans = 0;
	char arry[10050];
	cin >> n;
	for (int i = 0; i < n*n; ++i) cin >> arry[i];
	for (int i = 0; i < n; ++i) 
	{
		int flag = 0;
		for (int j = 0; j < n; ++j)
		{
			if (arry[i+j*n] == 'C')flag++;
		}
		if (flag >= 2)ans += (flag-1)*flag/2;
	}
	for (int i = 0; i < n; ++i)
	{
		int flag = 0;
		for (int j = 0; j < n; ++j)
		{
			if (arry[j+n*i] == 'C')flag++;
		}
		if (flag >= 2)ans += (flag-1)*flag/2;
	}
	cout << ans;
}
