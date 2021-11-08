#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn= 755;

struct item
{
	int s,b;
	item(int ss,int bb):s(ss),b(bb){}
	bool operator <(const item x)const
	{
		return x.s<s;
	}
};

void merge(int* A,int *B,int *C,int n)
{
	priority_queue<item>q;
	for(int i=0;i<n;i++)
	{
		q.push(item(A[i]+B[0],0));
	}
	for(int i=0;i<n;i++)
	{
		item Item=q.top();
		q.pop();
		C[i]=Item.s;
		int b=Item.b;
		if(b+1<n)q.push(item(Item.s-B[b]+B[b+1],b+1));
	}
}

int A[maxn][maxn];
int main()
{
	int num;
	while(cin>>num)
	{
		for(int m=0;m<num;m++)
		{
			for(int n=0;n<num;n++)
			cin>>A[m][n];
			sort(A[m],A[m]+num);
		}
		for(int i=1;i<num;i++)
		merge(A[0],A[i],A[0],num);
		cout<<A[0][0];
		for(int i=1;i<num;i++)
		cout<<" "<<A[0][i];
		cout<<endl;
	}
	return 0;
}



















