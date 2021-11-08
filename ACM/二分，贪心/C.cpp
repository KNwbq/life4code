#include<iostream>
using namespace std;
const int maxn = 100010;

int main()
{
	int kase, num;
	cin >> kase;
	int ccase = 1;
	while (kase--)
	{
		cin >> num;
		int times = 0, bgin = 1;
		bool def = true;
		int arry1[2*maxn] = { 0 };
		int arry2[2*maxn] = { 0 };

		for (int i = 1;i <= num;i++)
		{ 
			cin >> arry1[i];
			arry1[num + i] = arry1[i];
		}

		for (int i = 1;i <= num;i++)
		{
			cin >> arry2[i];
			arry2[num + i] = arry2[i];
		}

		for (int k = 1;;++k)
		{
			times++;
			arry1[k] = arry1[k - 1] + arry1[k];
			arry2[k] = arry2[k - 1] + arry2[k];
			if (arry1[k] < arry2[k] && bgin != num&&k<=num)
			{
				arry1[k] = 0;
				arry2[k] = 0;
				bgin = k + 1;
				times = 0;
				continue;
			}
			if (arry1[k] < arry2[k] && k>=num)
			{
				def = false;
				break;
			}
			if (times == num)break;
		}
		if (def)cout << "Case " << ccase << ": Possible from station " << bgin << endl;
		else cout << "Case " << ccase << ": Not possible" << endl;
		ccase++;
	} 
	return 0;
}
