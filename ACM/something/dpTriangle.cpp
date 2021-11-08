#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

int main()
{
	int Triangle[100][100];
	int dp[100][100];
	int N,maxn;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=i;j++)
		cin>>Triangle[i][j];
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(i==0)dp[i][j]=Triangle[i][j];
			else if(j==0)dp[i][j]=dp[i-1][j]+Triangle[i][j];
			else if(j==i)dp[i][j]=dp[i-1][j-1]+Triangle[i][j];
			else {
				dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+Triangle[i][j];
			}
		}
	}
	sort(dp[N-1],dp[N-1]+(N-1),greater<int>());
	cout<<dp[N-1][0];
	system("pause");
	return 0;
}
