#include<iostream>
using namespace std;
const int maxn = 110;
bool arry[maxn];

int main()
{
	int n, m, num1, num2;
	cin >> n >> m;
	while(n--)
	{
		cin >> num1;
		for(int i = 0; i < num1; ++i)
		{
			cin >> num2;
			arry[num2] = true;	
		} 
	}
	for(int i = 1; i <= m; ++i)
	{
		if(!arry[i]){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
