#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> points[maxn];

inline int read(void)
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
		{
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int l[maxn], cnt[maxn];

int main()
{
    ios::sync_with_stdio(0);

    for (int i = 0; i < maxn; ++i) l[i] = 1;
    int n, m, p1, p2;
    n = read(); m = read();
    for (int i = 0; i < m; ++i) {
        p1 = read(); p2 = read();
        points[p1].push_back(p2);
        points[p2].push_back(p1);
    }

    for (int i = 1; i <= n; ++i) 
        for (int j = 0; j < points[i].size(); ++j) 
           if(points[i][j] < i) l[i] = max(l[i], l[points[i][j]]+1);

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        long long val = (long long)l[i] * (long long)points[i].size();
        if (val > ans) ans = val;
    }
    cout << ans << endl;
    return 0;
}