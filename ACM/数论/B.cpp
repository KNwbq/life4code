#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const ll maxn = 10000001;
ll primes[maxn], tot = 0, flag, ans = 1;
bool isPrime[maxn];

void init()
{
	fill (isPrime, isPrime + maxn, 1);
	isPrime[1] = false;
	for (int i = 2; i < maxn; ++i)
	{
		if (isPrime[i]) primes[tot++] = i;
		for (int j = 0; j < tot && i*primes[j] < maxn; ++j)
		{
			isPrime[i*primes[j]] = false;
			if(i%primes[j] == 0)break;	
		}	
	} 	
}

int main()
{
	init();
	ll c;
	cin >> c;
	for (ll i = 0; i < tot && primes[i]*primes[i] <= c; ++i)
	{
		flag = 0;
		while (c%primes[i] == 0)
		{
			c /= primes[i];
			flag++;
		}
		if (flag%2) ans *= primes[i]; 
	}
	if((ll)sqrt(c)*(ll)sqrt(c) == c)cout << ans;
	else cout << ans*c;
	return 0;
}
