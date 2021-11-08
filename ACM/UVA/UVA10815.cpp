#include<iostream>
#include<cstring>
#include<set>
#include<algorithm>
#include<sstream>
using namespace std;
const int maxn = 1000;

string str, str2;
set<string> Set;

int main()
{
    int tot = 0;
    set<string>::iterator iter;
    while (cin >> str) 
    { 
        for (int i = 0; i < str.length(); )
        {
            if (!isalpha(str[i])) { str[i] = ' '; }
            else str[i] = tolower(str[i]);
            ++i;
        } 
        stringstream ss(str);
        while (ss >> str2) Set.insert(str2);
        
    }
    iter = Set.begin();
    for (; iter != Set.end(); ++iter) {
        cout << *iter << endl;
    }
    system("pause");
    return 0;
}