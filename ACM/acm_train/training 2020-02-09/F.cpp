#include<iostream>
using namespace std;

int main()
{
	int arry[5] = {1, 2, 3, 4, 5};
	int x, ans = 0;
	cin >> x;
	for(int i = 4; i >= 0; --i)
	{
		ans += (x-x%arry[i])/arry[i];
		x -= x/arry[i]*arry[i];
	}
	cout << ans;
	system("pause");
	return 0;
}
