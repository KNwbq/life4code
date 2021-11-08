#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;
struct  node{
	int val, len;
}N[10030], M[10030];
int ary[110];
bool cmp(node a, node b)
{
	if (a.val == b.val) return a.len <= b.len;
	return a.val < b.val;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int q, s, m, cnt = 0, count = 0;
		scanf("%d", &s);
		for (int i = 0; i < s; ++i) scanf("%d", &ary[i]);
		for (int i = 0; i < s; ++i){
			int k = 0;
			for (int j = i; j < s; ++j)
			{
				k ^= ary[j];
				N[cnt].val = k;
				N[cnt++].len = j - i + 1;
			}
		}
		sort(N, N + cnt, cmp);
		for (int i = 0; i < cnt - 1; ++i)
		{
			if (N[i].val != N[i + 1].val)
			{
				M[count].val = N[i].val; M[count++].len = N[i].len;
			}
		}
		M[count].val = N[cnt - 1].val; M[count++].len = N[cnt - 1].len;
		scanf("%d", &m);
		for (int i = 0; i < m; ++i){
			scanf("%d", &q);
			int l = 0, r = count - 1, flag = false, mid;
			while (l < r)
			{
				mid = (l + r) / 2;
				if (M[mid].val > q) r = mid;
				else if (M[mid].val < q) l = mid + 1;
				else if (M[mid].val == q) {
					flag = true; break;
				}
			}
			if (flag){
				printf("%d\n", M[mid].len);
			}
			else {
				if (l == 0) printf("%d\n", M[l].len);
				else if (abs(M[l].val - q) < abs(M[l - 1].val - q)){
					printf("%d\n", M[l].len);
				}
				else if (abs(M[l].val - q) > abs(M[l - 1].val - q)){
					printf("%d\n", M[l - 1].len);
				}
				else printf("%d\n", max(M[l].len, M[l - 1].len));
			}
		}
		printf("\n");
	}	
	return 0;
} 
