#include<iostream>
const long long maxn=100;
using namespace std;

int main()
{
    std::ios::sync_with_stdio(0);
    int T;
    long long n;
    cin>>T;
    while(T--)
    {
        long long arry[maxn];
        cin>>n;
        for(int i=0;i<=n;i++)
        {
        	if(i==0)arry[i]=0;
        	else if(i==1)arry[i]=1;
        	else arry[i]=arry[i/2]+arry[i/4];
		}
		cout<<arry[n]<<endl;
    }
}

