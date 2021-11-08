#include<iostream> 
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int arry[maxn];

int main()
{
	int n,l,num;
	cin>>num;
	while(num--)
	{
		cin>>n>>l;
		for(int i=0;i<n;++i)cin>>arry[i];
		sort(arry,arry+n);
		int sum=0,lb=0,ub=n-1,k=n;
		for(;k>0;)
		{
			if(arry[lb]+arry[ub]<=l)
			{
				sum+=1,lb+=1,ub-=1,k-=2	;
			} 
			else
			{
				sum+=1,ub-=1,k-=1;
			}
		}
		cout<<sum<<endl;
		if(num)cout<<endl;
	}
}
