#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 2020;
int f[maxn];

int main()
{
	int n, v, vi, wi, si;
	scanf("%d %d", &n, &v);
	for (int i = 0; i < n; ++i){
		int peg = 1;
		scanf("%d %d %d", &vi, &wi, &si);
		while (si - peg >= 0)
		{
			for (int j = v; j >= peg * vi; --j)
			f[j] = max(f[j], f[j - peg * vi] + wi * peg);
			si -= peg;
			peg *= 2;
		}
		for (int j = v; j >= si * vi; --j)
		f[j] = max(f[j], f[j - si * vi] + wi * si);
	} 
	printf("%d", f[v]);
	return 0;
}
