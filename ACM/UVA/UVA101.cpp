#include<bits/stdc++.h>
using namespace std;
const int maxn = 30;
vector<int> p[maxn];

void init () 
{ 
    for (int i = 0; i < maxn; ++i)
    {
        p[i].push_back(i);
    }
    return;
}

void clear(int a)
{
    for (int i = 0; i < maxn; ++i)
    {
        for (int j = 0; j < p[i].size(); ++j)
        {
            if (p[i][j] == a)
            {
                while (p[i].back() != a)
                {
                    p[p[i].back()].push_back(p[i].back());
                    p[i].pop_back();
                }
                return;
            }
        }
    }
}

void move(int a, int b)
{
    stack<int> buf; 
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < p[i].size(); ++j) {
            if (p[i][j] == a) {
                while (p[i].back() != a) {
                    buf.push(p[i].back());
                    p[i].pop_back();
                }
                buf.push(a); p[i].pop_back();
                break;
            }
        }
    }
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < p[i].size(); ++j) {
            if (p[i][j] == b) {
                while (!buf.empty()) {
                    p[i].push_back(buf.top()); buf.pop();
                }
                return;
            }
        }
    }
}

int main()
{
    init();
    int n, a, b, bn, posa, posb;
    string arry1, arry2;
    cin >> n; bn = n;
    while (cin >> arry1) {
        if (arry1 == "quit") break;
        else cin >> a >> arry2 >> b;
        for (int i = 0; i < maxn; ++i) {
            for (int j = 0; j < p[i].size(); ++j) {
                if (p[i][j] == a) posa = i;
                if (p[i][j] == b) posb = i;
            }
        }
        if (posa == posb) continue;
        if (arry1 == "move") clear(a);
        if (arry2 == "onto") clear(b);
        move(a, b);
    }
    for (int i = 0; i < n; ++i) {
        cout << i << ':';
        for (int j = 0; j < p[i].size(); ++j) {
            cout << ' ' << p[i][j];
        }
        cout << endl;
    }
}