#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str[120]; int tot = 0, cnt = 0;

    while (cin >> str[tot])
    {
        if (str[tot] == "#") break;
        ++tot;
        if (cin.get() == '\n') {
            for (int i = 0; i < tot; ++i)
            {
                bool def = true;
                for (int j = 0; j < tot; ++j)
                {
                    if (str[i] == str[j] && i != j) { def = false; break; }
                }
                if (def) ++cnt;
            }
            if ((double)cnt / tot >= 0.5) cout << "yes" << endl;
            else cout << "no" << endl;
            tot = 0; cnt = 0;
        }
    }
    return 0;
}