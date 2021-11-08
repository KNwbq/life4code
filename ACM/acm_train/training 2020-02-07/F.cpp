#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char a;
	int ans = 0, flag = 0;
	while(cin >> a)
	{
		flag++;
		if(a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U' || a=='Y')
		{
			if(flag > ans)ans = flag;
			flag = 0;
		}
	}
	if(flag+1 > ans)ans = flag+1;
	cout << ans;
	return 0; 
} 
