#include<iostream>
using namespace std;
struct point{
	int x, y;
}arry[3];

int main()
{
	int ans = 0, res = 4;
	for(int i = 0; i < 3; ++i)cin >> arry[i].x >> arry[i].y;
	for(int i = 0; i < 3; ++i)
	{
		ans = 0;
		for(int j = 1; j <=2; ++j)
		{
			if(arry[i].x == arry[(i+j)%3].x || arry[i].y == arry[(i+j)%3].y) ans+=1;
			else ans += 2;
		}
		if(ans < res)res = ans;
	}
	if((arry[0].x == arry[1].x && arry[1].x == arry[2].x ) || (arry[0].y == arry[1].y && arry[1].y == arry[2].y ))
	cout << res;
	return 0;
}
