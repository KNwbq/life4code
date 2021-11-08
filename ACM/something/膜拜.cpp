#include<iostream>
#include<cmath>
using namespace std;
const int maxn=2510;
int count(int,int,int *,int);

int main()
{
	int number,gap,student,cow1=1,dp[maxn];
	cin>>number>>gap;
	for(int i=0;i<number;i++)
	{
		cin>>student;
		if(i==0)
		{	if(student==cow1)dp[i]=0;
			else dp[i]=1;
		}
		else
		{
			if(student==cow1)dp[i]=dp[i-1];
	     	else dp[i]=dp[i-1]+1;
		}
	}
	cout<<count(gap,number,dp,0);
	return 0;
}

int count(int gap,int number,int *arry,int decline)
{
	for(int i=number;i>1;i--     )
	if(fabs(2*(arry[i-1]-decline-(arry[0]-decline))-i)==gap)return 1+count(gap,number-i,arry+i,arry[i-1]);
	return 1;
}

