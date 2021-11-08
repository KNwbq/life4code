#include<iostream>
#include<vector>
using namespace std;
const int maxn = 100000;
vector<int> primes;
vector<int> isPrime(maxn, 1);

int main()
{
    primes.push_back(2); 
    for (int i = 3; i <= maxn; ++i)
    {
        if (isPrime[i]) primes.push_back(i);
        for (int j = 0; i * primes[j] <= maxn && j < primes.size(); ++j)
            isPrime[i * primes[j]] = 0;
    }
    for (int i = 0; i < primes.size(); ++i) cout << primes[i] << ' ';
    system("pause");
}
