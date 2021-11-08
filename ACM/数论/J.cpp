#include<iostream>
using namespace std;
typedef long long ll;

int main()
{
	ll n, k, ans = 0;
	while(cin >> n >> k){
		ans =  n*k;
		if(n > k) n = k;
		for(ll i = 1; i <=n;)
		{
			ll d = k/i;
			ll j = k/d;
			if(j > n)j = n;
			ans -= ((i+j)*(j-i+1)/2)*d;
			i = j+1;
		}
	cout << ans << endl;
	}
	
	return 0;
}
