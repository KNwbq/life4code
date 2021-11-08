#include<iostream>
using namespace std;
struct List{
	int data;
	List* next;
}; 
void player(List* &,int);
void josephus(List* &,int,int);
void show(List*);


int main()
{
	int n,i,interval;
	cin>>n>>i>>interval;
	List* head=NULL;
	player(head,n);
	josephus(head,i,interval);
	return 0;
}

void player(List* &head,int n)
{
	List *p,*s;
	s=new List;
	s->data=1;
	head=s;
	for(int i=2;i<=n;i++)
	{
		p=s;
		s=new List;
		s->data=i;
		p->next=s;
	}
	s->next=head;
	return;
}

void josephus(List* &head,int i,int interval)
{
	List *s,*p;
	s=head;
	for(;;)
	{
		if(s->data==i)break;
		s=s->next;
	}
	p=s->next;
	while(p!=s)
	{
		for(int m=0;m<interval-2;m++)
		{
			s=s->next;
			p=p->next;
		}
			if(interval==1)
			{
				show(s);
				return;
			}
			cout<<p->data<<" ";
			s->next=p->next;
			delete p;
			s=s->next;
			p=s->next;
	}
	cout<<s->data;
	delete s;
	s=p=head=NULL;
	return;
}

void show(List* head)
{
	int flag=0;
	while(flag<8)
	{
		cout<<head->data<<" ";
		head=head->next;
		flag++;
	}
}





