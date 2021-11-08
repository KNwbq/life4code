#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
	int T,x=1;
	long long b;
    cin>>T;
    while(T--)
	{
      	char arry[220];
      	cin>>arry>>b;
      	b=fabs(b);
      	if(arry[0]=='-')
      	{
      		long long ans=arry[1]-'0';
      		for(int i=0;i+2<strlen(arry);i++)
      		{
      			ans=((ans*10)%b+(arry[i+2]-'0')%b)%b;
			}
			if(ans!=0)cout<<"Case "<<x<<": "<<"not divisible"<<endl;
			else cout<<"Case "<<x <<": "<<"divisible"<<endl;
		}
		else{
			long long ans=arry[0]-'0';
      		for(int i=0;i+1<strlen(arry);i++)
      		{
      			ans=((ans*10)%b+(arry[i+1]-'0')%b)%b;
			}
			if(ans!=0)cout<<"Case "<<x<<": "<<"not divisible"<<endl;
			else cout<<"Case "<<x<<": "<<"divisible"<<endl;
		}    
		x++;
    }
    return 0;
}
