#include<iostream>
#include<iomanip>
using namespace std;
char arry[9] = {'B', 'K', 'M', 'G', 'T', 'P', 'E', 'Z', 'Y'};
char ip[10];
int x;

int main()
{
	int n, num, cases = 1;
	cin >> n;
	while (n--) {
		cin >> x >> ip;
		for (num = 0; num < 9; ++num) {if(ip[1] == arry[num])break;}
		double son = 1.0, mon = 1.0, ans;
		for(int i = 1; i <=num; ++i)son = son*1000;
		for(int i = 1; i <=num; ++i)mon = mon*1024;
		ans = (1 - son/mon)*100;
		cout << setiosflags(ios::fixed) << setprecision(2) << "Case #" << cases << ": " << ans << '%' << endl;
		++cases;
	}
	return 0;
}
