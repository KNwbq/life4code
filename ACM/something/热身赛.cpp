#include<iostream>
using namespace std;

int main()
{
	int n;
	long long arry[2000];
	cin>>n;
    for(int i=0;i<2*n;i++)
    {
	cin>>arry[i];
	if(i>=n)
	{
   	    if(arry[i]>arry[i-n])
	    cout<<arry[i]<<" ";
	    else cout<<arry[i-n]<<" ";
	}
    }
	return 0;
}
