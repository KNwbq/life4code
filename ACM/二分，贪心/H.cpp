#include<iostream>
#include<cstring> 
using namespace std;
const int maxn = 510;
bool divide(long long*, long long);
long long binary(long long, long long);
int arry[maxn];
bool tab[maxn];
long long maxm, sum[maxn];
int m, k;

int main()
{
	int cases;
	cin >> cases;
	while (cases--)
	{
		int cnt = 0;
		long long add=0;
		cin >> m >> k;
		for (int i = 0;i < m;++i)cin >> arry[i];
		sum[0] = arry[0];
		for (int i = 1;i < m;++i)sum[i] = sum[i - 1] + arry[i];

		maxm = sum[m - 1];
		long long ans = binary(0, maxm);
		
		memset(tab, false, sizeof(tab));
		for (int i = m - 1;i >= 0;--i)
		{
			add += arry[i];
			if (add > ans)
			{
				++cnt;
				tab[i] = true;
				add = arry[i];
			}
		}
		for (int i = 0;i < m && cnt < k - 1;++i)
		{
			if (!tab[i])
			{
				tab[i] = true;
				++cnt;
			}
		}
		cout << arry[0];
		for (int i = 1;i < m;++i)
		{
			if (tab[i - 1])cout << " /";
			cout <<' '<<arry[i];
		}
		cout << endl;
	}
	return 0;
}

bool divide(long long* sum, long long now)
{
	int cnt = 0;
	long long peg = 0;
	for (int i = 0;i < m - 1 && cnt < k - 1;++i)
	{
		if (sum[i] - peg <= now && sum[i + 1] - peg > now)
		{
			++cnt;
			peg = sum[i];
		}
	}
	if (sum[m - 1] - peg > now)return false;
	else return true;
}
long long binary(long long min, long long maxm)
{
	long long mid = (min + maxm) / 2;
	if (min == maxm)return mid;
	if (divide(sum, mid))return binary(min, mid);
	else return binary(mid + 1, maxm);
}

