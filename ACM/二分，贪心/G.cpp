#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=200050;
int arry[maxn];

int main()
{
	int n,k,i;
	cin>>n>>k;
	for(int m=0;m<n;m++)cin>>arry[m];
	sort(arry,arry+n);
	int flag=1;
	for(i=n/2;i<n-1&&k>0;i++)
	{
		if((long long)(arry[i+1]-arry[i])*flag<=k)
		{
			k-=(arry[i+1]-arry[i])*flag;
			arry[n/2]+=arry[i+1]-arry[i];
			arry[i]=arry[i+1];
		}	
		else break;
		++flag;   
	} 
	if(k>0)arry[n/2]+=k/(i-n/2+1);
	cout<<arry[n/2]; 
	return 0;
}
