/*#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100;

class M
{
public:
    int n; 
	char matrix[maxn][maxn];
	char Matrix[maxn][maxn];
	void input(int x)
	{
		n = x;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j) cin >> matrix[i][j];
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j) cin >> Matrix[i][j];
		}
	}
	void maxx()
	{
		for (int i = 0; i < n; ++i)
		{
			int maxx = -100000;
			for (int j = 0; j < n; ++j)
			{
				maxx = max(maxx, (int)matrix[j][i]);
			}
			cout << maxx;
			if (i == n - 1) cout << '\n';
			else cout << ' ';
		}
	}
	void Maxx()
	{
		for (int i = 0; i < n; ++i)
		{
			int maxx = -100000;
			for (int j = 0; j < n; ++j)
			{
				maxx = max(maxx, (int)Matrix[j][i]);
			}
			cout << maxx;
			if (i == n - 1) cout << '\n';
			else cout << ' ';
		}
	}
	void trans()
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = n - 1; j >= 0; ++j)
			{
				cout << matrix[j][i];
				if (j != 0) cout << ' ';
				else cout << '\n';
			}
		}
	}
	void Trans()
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = n - 1; j >= 0; ++j)
			{
				cout << Matrix[j][i];
				if (j != 0) cout << ' ';
				else cout << '\n';
			}
		}
	}
};

int main()
{
	int n;
	while (cin >> n)
	{
		M mm;
		mm.input(n);
		mm.maxx();
		mm.trans();
		mm.Maxx(); mm.Trans();
	}
}*/

#include<iostream>
using namespace std;
const int maxn = 1000;

class goods
{
public:
	static double tot;
	int q;
	double p;
}ggg[maxn];

double goods::tot = 0;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		goods::tot = 0;
		double dis;
		int num, cnt = 0;
		cin >> dis >> num;
		for (int i = 0; i < num; ++i)
		{
			cin >> ggg[i].q >> ggg[i].p;
			cnt += ggg[i].q;
			double pp = ggg[i].q * ggg[i].p;
			if (ggg[i].q > 10) pp *= 0.98;
			goods::tot += pp;
		}
		cout << goods::tot * (1 - dis) << ' ' << (goods::tot * (1 - dis)) / cnt  << endl;
	}
}




