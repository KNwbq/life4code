#include<iostream>
const int maxn=131100;
int arry1[maxn];
int arry2[maxn];
using namespace std;

int main()
{   
	std::ios::sync_with_stdio(0);                                                   
	int P,N,M,min,max;
	cin>>P>>N>>M;
	min=P-1,max=0;
	for(int i=0;i<N;i++)
	cin>>arry1[i];
	for(int i=0;i<M;i++)
	cin>>arry2[i];
	for(int x=0;x<N;x++)
	{
		for(int y=0;y<M;y++)
		{
		if((arry1[x]*arry2[y])%P>max)max=(arry1[x]*arry2[y])%P;
		if((arry1[x]*arry2[y])%P<min)min=(arry1[x]*arry2[y])%P;
		}
	}
	cout<<min<<" "<<max;
	return 0;
} 
