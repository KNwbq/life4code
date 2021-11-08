#include<iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		long long sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			if(2*n%i==0)sum+=2*n/i;
			else sum+=2*n/i+1;
		}
		cout<<sum<<endl;
	}
	return 0;
}
