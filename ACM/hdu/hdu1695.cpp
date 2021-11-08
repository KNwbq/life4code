#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e6+20;
ll mu[maxn], primes[maxn], tot = 0, flag = 1, a, b, c, d, k, cases;
ll ans, res;
bool isPrime[maxn]; 
void init()
{
	fill (isPrime, isPrime + maxn, 1);
	isPrime[1] = false; mu[1] = 1;
	for(int i = 2; i < maxn; ++i)
	{
		if(isPrime[i]){primes[tot++] = i; mu[i] = -1;}
		for(int j = 0; j < tot && i*primes[j] < maxn; ++j)
		{
			isPrime[i*primes[j]] = false;
			if(i%primes[j] == 0){
				mu[i*primes[j]] = 0;
				break;
			}
			mu[i*primes[j]] = -mu[i];
		}
	}
}

int main()
{
	init();
	cin >> cases;
	while(cases--)
	{
		ans = 0, res = 0;
		cin >> a >> b >> c >> d >> k;
		if(k == 0){
			cout << "Case " << flag <<": " << 0 << endl;
			flag++;
			continue; 
		}
		b = b/k, d = d/k;
		for(ll i = 1; i <= min(b, d); ++i)ans += mu[i]*(b/i)*(d/i);
		for(ll i = 1; i <= min(b, d); ++i)res += mu[i]*(min(b, d)/i)*(min(b, d)/i);
		ans = ans - (res-1)/2;
		cout << "Case " << flag << ": " << ans << endl;
		flag++;
	}
	system("pause");
	return 0;
}
