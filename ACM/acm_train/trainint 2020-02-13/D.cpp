#include<iostream>
using namespace std;

int main()
{
	int a, b, c, d, Emma = 0, Gunnar = 0;
	cin >> a >> b >> c >> d;
	Gunnar = a + b + c + d;
	cin >> a >> b >> c >> d;
	Emma = a + b + c + d;
	if (Emma > Gunnar) cout << "Emma";
	else if (Emma < Gunnar) cout << "Gunnar";
	else cout << "Tie";
	return 0;
} 
