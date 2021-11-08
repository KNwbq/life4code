#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1000010;
struct unit{
	int floor,ceiling,left,right;
}sample[maxn];

int main()
{
	int cases,num;
	cin>>cases;
	while(cases--)
	{
		long long sum=0;
		cin>>num;
		for(int i=0;i<num;i++)
		cin>>sample[i].floor;
		for(int i=0;i<num;i++)
		cin>>sample[i].ceiling;
		sample[0].left=sample[0].ceiling;
		sample[num-1].right=sample[num-1].ceiling;
		for(int i=0;i<num-1;i++)
		{
			
			if(sample[i+1].ceiling<sample[i].left)
			{
				sample[i+1].left=sample[i+1].ceiling;	
			}
			else if(sample[i+1].floor>sample[i].left)
			{
				sample[i+1].left=sample[i+1].floor;	
			}	
			else{
				sample[i+1].left=sample[i].left;
			}
		} 
		for(int i=num-1;i>0;i--)
		{
			
			if(sample[i-1].ceiling<sample[i].right)
			{
				sample[i-1].right=sample[i-1].ceiling;	
			}
			else if(sample[i-1].floor>sample[i].right)
			{
				sample[i-1].right=sample[i-1].floor;	
			}	
			else{
				sample[i-1].right=sample[i].right;
			}
		} 
		for(int i=0;i<num;i++)
		{
			sum+=min(sample[i].left,sample[i].right)-sample[i].floor;
		}
		cout<<sum<<endl;
	}
	return 0;
} 


