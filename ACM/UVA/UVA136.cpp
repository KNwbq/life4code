/*#include<iostream>
#include<queue>
using namespace std;
typedef long long LL;
priority_queue<LL> Ugly_Num;

bool isU (long long x)
{
    if (x == 1) return true;
    int f[3] = {2, 3, 5};

    if (x % 2 != 0 && x % 3 != 0 && x % 5 != 0) return false;
    for (int i = 0; i < 3; ++i)
        while (x % f[i] == 0) x /= f[i];
    if (x != 1) return false;
    return true;
}

int main()
{
    long long x = 1;
    while (Ugly_Num.size() != 1500)
    {
        if (isU(x)) Ugly_Num.push(x);
        ++x;
    }
    cout << "The 1500'th ugly number is <" << Ugly_Num.top() << '>';
    system("pause");
    return 0;
}*/

#include<iostream>
#include<set>
#include<queue>
using namespace std;
typedef long long LL;

int main()
{
    int f[3] = {2, 3, 5};
    priority_queue<LL, vector<LL>, greater<LL> > U;
    set<LL> cnt;
    U.push(1); cnt.insert(1);
    for (int i = 1;; ++i)
    {
        LL x = U.top(); U.pop();
        if (i == 1500) { cout << "The 1500'th ugly number is " << x << ".\n"; break; }
        for (int j = 0; j < 3; ++j)
        {
            LL x2 = x * f[j];
            if (cnt.count(x2) == 0) { U.push(x2); cnt.insert(x2); }
        }
    }
    return 0;
}