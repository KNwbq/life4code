#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=4010;

int main()
{
	int A[maxn];
	int B[maxn];
	int C[maxn];
	int D[maxn];
	int arry1[maxn*maxn];
	int arry2[maxn*maxn];
	int kase,num;
	cin>>kase;
	while(kase--)
	{
		cin>>num;
		for(int i=0;i<num;i++)
		{
			cin>>A[i]>>B[i]>>C[i]>>D[i];
		}
		int flag1=0,flag2=0;
		for(int i=0;i<num;i++)
		{
			for(int m=0;m<num;m++)
			{
				arry1[flag1]=A[i]+B[m];
				flag1++;
			}
		}
		for(int i=0;i<num;i++)
		{
			for(int m=0;m<num;m++)
			{
				arry2[flag2]=C[i]+D[m];
				flag2++;
			}
		}
		sort(arry1,arry1+num*num);
		sort(arry2,arry2+num*num);
		int flag=0;
		for(int m=0;m<num*num;m++)
		{
			if(binary_search(arry2,arry2+num*num,-arry1[m]))
			{
				int* p=lower_bound(arry2,arry2+num*num,-arry1[m]);
				int* q=upper_bound(arry2,arry2+num*num,-arry1[m]);
				flag+=(q-p);	
			}
		}
		cout<<flag<< endl;
		if(kase)
		{
			cout<<endl;
		}
	} 
	return 0;
}


