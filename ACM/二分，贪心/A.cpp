#include<iostream>
#include<queue>
#include<functional>
using namespace std;

int main()
{
	priority_queue<int,vector<int>,greater<int> > wood;
	long long num,planks;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cin>>planks;
		wood.push(planks);
	}
	long long p,q,sum=0;
	while(!wood.empty())
	{
		p=wood.top();
		wood.pop();
		if(wood.empty())
		{
			sum+=p;
			break;
		}
		q=wood.top();
		wood.pop();
		wood.push(p+q);
		sum+=(p+q);
	}
	if(num>1)sum-=p;
	cout<<sum;
	return 0;
} 
