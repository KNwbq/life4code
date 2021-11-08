#include<iostream>
#include <cstring> 
using namespace std;

int main()
{
	int B_x,B_y,H_x,H_y;
	int X[9]={ 1,2,2,1,-1,-2,-2,-1,0 };
	int Y[9]={ 2,1,-1,-2,-2,-1,1,2,0 };
	long long dp[22][22];
	cin >> B_x >> B_y >> H_x >> H_y;
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<=B_y;i++)
	{
		for(int j=0;j<=B_x;j++)
		{
			if(i==0&&j==0)dp[i][j]=1;
			else if(i==0)dp[i][j]=dp[i][j-1];
			else if(j==0)dp[i][j]=dp[i-1][j];
			else dp[i][j]=dp[i][j-1]+dp[i-1][j];
			for(int m=0;m<9;m++)
			{
				//if(i-1==H_y+Y[m]&&j==H_x+X[m]&&i-1>=0)dp[i][j]=dp[i][j]-dp[i-1][j];
				//if(i==H_y+Y[m]&&j-1==H_x+X[m]&&j-1>=0)dp[i][j]=dp[i][j]-dp[i][j-1];
				if(i==H_y+Y[m]&&j==H_x+X[m])dp[i][j]=0;
			}
		}
	}
	cout<<dp[B_y][B_x];
	return 0;
}  
