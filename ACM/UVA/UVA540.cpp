/*#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1010;


int main()
{
    ios::sync_with_stdio(0);
    
    int t, Size, num, c_n = 1;
    string op;
    while (cin >> t && t != 0)
    {
        queue<int> Queue[maxn];
        queue<int> team_queue[maxn];
        queue<int> ans;
        vector<int> Q_N;
        for (int i = 0; i < t; ++i)
        {
            cin >> Size;
            for (int j = 0; j < Size; ++j)
            {
                cin >> num;
                Queue[i].push(num);
            }
        }

        while (cin >> op && op[0] != 'S')
        {
            if (op[0] == 'E')
            {
                cin >> num;
                for (int i = 0; i < t; ++i) 
                {
                    bool F = false;
                    if (Queue[i].front() == num) 
                    {
                        Queue[i].pop(); team_queue[i].push(num);
                        bool H = false;
                        for (int j = 0; j < Q_N.size(); ++j) 
                            if (Q_N[j] == i) { H = true; break; }
                        F = true;
                        if (!H) Q_N.push_back(i);
                    }
                    if (F) break;
                }
            }
            if (op[0] == 'D')
            {
                int buff = team_queue[Q_N[0]].front();
                team_queue[Q_N[0]].pop();
                if (team_queue[Q_N[0]].size() == 0) Q_N.erase(Q_N.begin());
                ans.push(buff);
            }
        }
        cout << "Scenario #" << c_n << endl;
        ++c_n;
        while (!ans.empty())
        {
            int buff = ans.front();
            cout << buff << endl;
            ans.pop();
        }
        cout << endl;
    }
    system("pause");
    return 0;
}*/

#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;
const int maxn = 1000 + 10;

int main()
{
    int id, sise, num, kase = 1;
    while (cin >> num && num != 0)
    {
        map<int, int> team;
        queue<int> q, q2[maxn];
        string op;
        cout << "Scenario #" << kase << endl; ++kase;
        for (int i = 0; i < num; ++i)
        {
            cin >> sise;
            for (int j = 0; j < sise; ++j) { cin >> id; team[id] = i; }
        }
        while (cin >> op && op[0] != 'S')
        {
            if (op[0] == 'D')
            {
                cout << q2[q.front()].front() << endl;
                q2[q.front()].pop();
                if (q2[q.front()].empty()) q.pop();
            }
            else if (op[0] == 'E')
            {
                cin >> id;
                if (q2[team[id]].size() == 0) q.push(team[id]);
                q2[team[id]].push(id);
            }
        }
        cout << endl;
    }
    return 0;
}