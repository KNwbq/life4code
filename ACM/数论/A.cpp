#include <bits/stdc++.h>
#define LL long long
#define N 100005
using namespace std;
const int mod = 1e9 + 7;
int cnt[N], p[N], mu[N], x[N], g[N], s[N], ret, maxn = N - 5;
LL t, z = 1;
int main(){
	int i, j, d, n, m, T, tmp, ans;
	mu[1] = 1;
	for(i = 2; i <= maxn; i++){
		if(!x[i]) p[++ret] = x[i] = i, mu[i] = -1;
		for(j = 1; j <= ret; j++){
			t = z * i * p[j];
			if(t > maxn) break;
			x[t] = p[j];
			if(i % p[j] == 0) break;
			mu[t] = -mu[i];
		}
	}
	scanf("%d", &T);
	while(T--){
		ans = 0;
		memset(cnt, 0, sizeof(cnt));
		memset(g, 0, sizeof(g));
		memset(s, 0, sizeof(s));
		scanf("%d", &n);
		for(i = 1; i <= n; i++){
			scanf("%d", &j);
			cnt[j]++;
		}
		n = maxn;
		//for(i = 1; i <= n; i++) printf("%d %d=====\n", i, cnt[i]);
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n / i; j++){
				g[i] = (g[i] + z * cnt[i * j] * j % mod) % mod;
			}
			g[i] = z * g[i] * g[i] % mod;
			//printf("%d %d\n", i, g[i]);
		}
		for(d = 1; d <= n; d++){
			tmp = 0;
			for(i = 1; i <= n / d; i++){
				tmp = (tmp + z * i * i % mod * mu[i] * g[(d * i)] % mod) % mod;	
			}
			tmp = (tmp + mod) % mod;
			ans = (ans + z * d * tmp % mod) % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}

