#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<iterator>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

typedef set<int> Set;
map<Set, int> IDcache;
vector<Set> Setcache;

int ID(Set x)
{
    if (IDcache.count(x) != 0) return IDcache[x];
    else {
        Setcache.push_back(x);
        IDcache.insert(pair<Set, int> (x, Setcache.size() - 1));
        return IDcache[x];
    }
}


int main()
{
    stack<int> s;
    int T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            string op;
            cin >> op;
            if (op[0] == 'P') s.push(ID(Set()));
            else if (op[0] == 'D') s.push(s.top());
            else {
                Set s1 = Setcache[s.top()]; s.pop();
                Set s2 = Setcache[s.top()]; s.pop();
                if (op[0] == 'U') {
                    Set ss;
                    set_union(ALL(s1), ALL(s2), INS(ss));
                    s.push(ID(ss));
                } 
                if (op[0] == 'I') {
                    Set ss;
                    set_intersection(ALL(s1), ALL(s2), INS(ss));
                    s.push(ID(ss));
                } 
                if (op[0] == 'A') {
                    s2.insert(ID(s1));
                    s.push(ID(s2));
                }
            }
            cout << Setcache[s.top()].size() << endl;
        }
        cout << "***" << endl;
    }
    system("pause");
    return 0;
}
