#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

struct island{
	double l,r;
	bool operator < (const island A)const
	{
		if(A.r!=r)return A.r<r;
		else return A.l<=l;
	}
};

int main()
{
	int num,range,x,y,flag=1;
	island cas;
	priority_queue<island>ran;
	while(cin>>num>>range)
	{
		bool def=true;
		if(num==0&&range==0)break;
		for(int i=0;i<num;i++)
		{
			cin>>x>>y;
			if(range-y<0){
				def=false;
			}
			double m=fabs(range*range-y*y);
			cas.l=x-sqrt(m);
			cas.r=x+sqrt(m);
			ran.push(cas);
		}
		int ans=0;
		cas=ran.top();
		ran.pop();
		while(!ran.empty())
		{
			if(ran.top().l<=cas.r)
			{
				ran.pop();
				continue;
			}
			else
			{
				ans+=1;
				cas=ran.top();
				ran.pop();
			}
		}
		ans+=1;
		if(def)
		{
			cout<<"Case "<<	flag<<": "<<ans<<endl;
			flag++;
		}
		else {
			cout<<"Case "<<	flag<<": "<<-1<<endl;
			flag++;
		}
	}
	return 0;
}
