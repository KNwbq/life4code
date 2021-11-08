#include<stdio.h>
typedef long long ll;

int main()
{
	ll l, r;
	int m;
	scanf("%d", &m);
	while (m--)
	{
		scanf("%lld%lld", &l, &r);
		for(int i = 62; i >= 0; --i)
		{
			ll l1 = l & ((ll)1 << i);
			ll r1 = r & ((ll)1 << i);
			if (l1 != r1){
				for (int j = 0; j < i; ++j)
				r = r | ((ll)1 << j); 
				break;
			}
		}
		printf("%lld\n", r);
	}	
	return 0;
} 
