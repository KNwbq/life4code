#include<iostream>
using namespace std;
const int maxn = 120;

int main()
{
    int n, arry[maxn];
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arry[i];
    int k;
    if (n == 1) k = 1;
    else if (n == 2) k = 2;
    else k = 3;
    for (int i = 1; i <= k; ++i)
    {
        cout << arry[i];
        for (int j = i + 3; j <= n; j += 3) cout << ' ' << arry[j];
        cout << endl;
    }
    system("pause");
    return 0;
}