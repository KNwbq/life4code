#include<iostream>
using namespace std;
typedef long long ll;
const int maxn = 1e9;
ll Euler(ll x)
{
	ll res = x;
	for(int i = 2;x != 1;++i)
	{
		if(x%i == 0)res = res/i*(i-1);
		while(x%i == 0)x /= i;
	}
	return res;
}

int main()
{
	ll n,m,t,ans;
	cin >> t;
	while(t--)
	{
		ans = 0;
		cin >> n >> m;
		for(ll s = 1;s*s <= n;++s)
		{
			if(n%s == 0)
			{
				if(s >= m)ans += Euler(n/s);
				if(n/s >= m && s*s!= n)ans += Euler(s);
			}		
		}
		cout << ans << endl;
	}
	return 0;
}
