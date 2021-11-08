#include<iostream>
using namespace std;
struct List {
	char words[100];
	List* next;
};
void build(List*& head);
void show(List* head);

int main()
{
	int n;
	cin >> n;
	cin.get();
	while (n--)
	{
		List* head = NULL;
		build(head);
		show(head);
	}
	return 0;
}

void build(List*& head)
{
	List* s;
	s = new List;
	s->next = NULL;
	while (cin >> s->words)
	{
		if (head == NULL)
			head = s;
		else
		{
			s->next = head;
			head = s;
		}
		s = new List;
		if (cin.get() == '\n')return;
	}
	delete s;
	s = NULL;
}

void show(List* head)
{
	cout << head->words;
	head = head->next;
	while (head)
	{
		cout << " " <<head->words ;
		head = head->next;
	}
	cout << '\n';
}
