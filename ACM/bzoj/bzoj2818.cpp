#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
const int maxn = 1e7 + 10;
int tot = 0 , n ,primes[maxn], phi[maxn];
ll sum[maxn] = { 0 },ans=0;
bool isPrime[maxn];

void getPhi()
{
	fill(isPrime, isPrime + maxn, 1);
	isPrime[1] = false, phi[1] = 1;
	for (int i = 2;i <= n;++i)
	{
		if (isPrime[i]){primes[tot++] = i;phi[i] = i - 1;}
		for (int j = 0;j < tot && i * primes[j] <= maxn;++j)
		{
			isPrime[i * primes[j]] = false;
			if (i % primes[j] == 0) { phi[i * primes[j]] = phi[i] * primes[j];break; }
			phi[i * primes[j]] = phi[i] * phi[primes[j]];
		}
	}
}

int main()
{
	cin >> n;
	getPhi();
	for (int i = 1;i <= n;++i)sum[i] = sum[i - 1] + phi[i];
	for (int i = 0;i < tot;++i)ans += sum[n / primes[i]] * 2 - 1;
	cout << ans << endl;
	system("pause");
}

