void exgcd(int a,int b,int &d,int &x,int &y)
{
	if(!b){d=a;x=1;y=0;}
	else{exgcd(b,a%b,d,y,x);y-=x*(a/b);}	
} 

void Euler(int n)
{
	int res = n;
	for (int i = 2; n != 1; ++i){
		if (n%i == 0) res = res/i*(i-1);
		while(n%i == 0) n/=i;
	}
}

void sieve()
{
	np[1]=1;
	for(int i=2;i<vol;++i)
	{
		if(!np[i])prime[++amo]=i;
		for(int j=1;j<=amo;++j)
		{
			if(i*prime[j]>=vol)break;
			np[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	} 
} 

void sieve()
{
	fill(isPrime, isPrime + maxn, 1);
	isPrime[1]= 0, mu[1] = 1, num = 0;
	for (int i = 2;i < maxn; ++i){
		if(isPrime[i])mu[i] = -1,primes[num++] = i;
		int d;
		for (int j = 0; j < num && d = j * prime[j] < maxn;++j){
			isPrime[d] = false;
			if (i % prime[j] == 0){
				mu[d] = 0;
				break;
			}else mu[d] = -mu[i];
		}
	}
}



 long long fpow(long long a,long long b,long long mod)
 {
 	long long ans=1;
 	while(b)
 	{
 		if(b&1)	ans=(ans*a)%mod;
 		a=(a*a)%mod;
 		b>>=1;
	}
	return ans;
 }
 
int minp[maxn], mu[maxn], phi[maxn], primes[maxn],num,d;
bool isPrime[maxn];
void init()
{
	fill(isPrime, isPrime + maxn, 1);
	minp[1] = 1, mu[1] = 1, phi[1] = 1,isPrime[1] = false;
	for(int i = 2; i < maxn; ++i)
	{
		if(isPrime[i]){
			minp[i] = i; mu[i] = -1; phi[i] = i-1; primes[num++] = i;
		}
		for(int j = 0; j<num && d = i*primes[j] < maxn; ++j)
		{
			isPrime[d] = false;
			minp[d] = primes[j];
			if(i%primes[j]){
				mu[d] = 0;
				phi[d] = phi[i] * primes[j];
				break; 
			}
			mu[d] = -mu[i];
			phi[d] = phi[i] * phi[prmes[j]];
		}
	}
}
