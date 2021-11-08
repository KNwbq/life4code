#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, m, flag = 1;
	while (cin >> n >> m)
	{
		if (flag) flag = 0;
		else cout << endl;
		for (int i = min(n,m)+1; i <= max(n,m)+1; ++i)
		{
			cout << i << endl;
		}
	}
	return 0;
}
