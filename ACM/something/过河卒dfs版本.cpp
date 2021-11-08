#include<iostream>
void dfs(int, int, int, int, int, int, int*, int*,long long&);
using namespace std;


int main()
{
	int B_x, B_y, H_x, H_y;
	long long sum=0;
	int X[9]={ 1,2,2,1,-1,-2,-2,-1,0 };
	int Y[9]={ 2,1,-1,-2,-2,-1,1,2,0 };
	cin >> B_x >> B_y >> H_x >> H_y;
	dfs(0, 0, B_x, B_y, H_x, H_y, X, Y, sum);
	cout << sum;
	return 0;
}

void dfs(int x, int y, int B_x, int B_y, int H_x, int H_y, int* X, int* Y,long long& sum)
{
	if (x > B_x || y > B_y) return;
	for (int i = 0;i < 9;i++)
	{
		if (H_x + X[i] <= B_x && H_x + X[i] >= 0 && H_y + Y[i] <= B_y && H_y + Y[i] >= 0 && x == H_x + X[i]&&y== H_y + Y[i])
			return;
	}
	if (x == B_x && y == B_y) sum += 1;
	dfs(x + 1, y, B_x, B_y, H_x, H_y, X, Y, sum);
	dfs(x, y + 1, B_x, B_y, H_x, H_y, X, Y, sum);
}//数量多时会TLE 
