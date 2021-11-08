#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
	int m, ary[1000], dp[1000];
	fill(dp, dp + 1000, 1);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) scanf("%d", &ary[i]);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (ary[j] <= ary[i]) dp[i] = max(dp[j] + 1, dp[i]);		
		}		
	}		
	int ans = 0;
	for (int i = 0; i < m; ++i) ans = max(ans, dp[i]); 
	printf("%d", ans);
	return 0;
} 
