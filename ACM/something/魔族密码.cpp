#include<iostream>
#include<cstring>
#include<algorithm>
#include<functional>
using namespace std;
const int maxn = 80;
const int maxm = 2005;

int main()
{
	std::ios::sync_with_stdio(0);
	int words_num;
	int dp[maxm];
	for(int i=0;i<maxm;i++)
	dp[i]=1;
	char words[maxm][maxn];
	cin >> words_num;
	for (int i = 0;i < words_num;i++)
		cin >> words[i];
	for (int i = 1;i < words_num;i++)
	{
		for (int m = i - 1;m >= 0;m--)
		{
			int check = 0;
			if (strlen(words[i]) > strlen(words[m]))
			{
				for (unsigned int n = 0;n < strlen(words[m]);n++)
				{
					if (words[i][n] != words[m][n])break;
					if (n == strlen(words[m]) - 1)
					{
						dp[i] = dp[m] + 1;
						check++;
					}
				}
			}
			if (check)break;
		}
	}
	sort(dp, dp + words_num, greater<int>());
	cout << dp[0] << endl;
}
 
