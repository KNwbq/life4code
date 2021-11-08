#include<iostream>
using namespace std;
const int maxn=100000+50;
int d,n;

int main()
{
	while(cin>>d>>n&&(d||n))
	{
		char arry[maxn];
		char c;
		int k=0;
		for(int i=0;i<d;i++)
		{
			cin>>c;
			while(k>0&&c>arry[k]&&k+d-i>d-n)--k;
			if(k<d-n)arry[++k]=c;	
		}
		arry[++k]='\0';
		for(int i=1;i<=d-n;i++)
		cout<<arry[i];
		cout<<endl;
	}
	return 0;
}
