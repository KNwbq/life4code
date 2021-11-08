#include<iostream>
using namespace std;
typedef long long ll;

int main()
{
	ll k, r, peg;
	cin >> k >> r;
	peg = k%10;
	for(ll i = 1;; ++i)
	{
		if(((i*peg)%10) == r || ((i*peg)%10) == 0)
		{
			cout << i;
			break;	
		}
	}
}
