#include<iostream>
using namespace std;
typedef unsigned long long ll;

int main()
{
	ll l, r, k, tot = 0;
	cin >> l >> r >> k;
	if(l <= 1 && r >=1){
		cout <<1;
		tot++;
	}
	ll flag = k;
	while(k <= r)
	{
		if(tot >= 1 && k >=l){
			cout << ' ' << k;
			tot++;
		}
		else if(k >= l)
		{
			cout << k;
			tot++;
		}
		if(r/k < flag)break;
		k*=flag;
	}
	if(tot == 0)cout << -1;
	return 0;
}
