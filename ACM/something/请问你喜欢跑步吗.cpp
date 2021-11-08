#include<iostream>
const int maxn=310;
using namespace std;

int main()
{
	std::ios::sync_with_stdio(0);
	int N,M;
	int arry[maxn][maxn];
	cin>>N>>M;
	for(int n=0;n<N;n++)
	{
		for(int m=0;m<M;m++)
		{
		 cin>>arry[n][m];
		 if(n>=1){
			if(arry[n][m]>arry[0][m])swap(arry[n][m],arry[0][m]);
		}
		}
	}
	long long sum=0;
	for(int m=0;m<M;m++)
	sum+=arry[0][m];
	cout<<sum;
	return 0;
}
