#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1e5 + 10;

int trie[maxn][26];
int fail[maxn];
int last[maxn];
int cntword[maxn];
int cnt = 0;
map<string, int> ind;
vector<string> strs;

int Build_Trie(string s)
{
    int root = 0;
    for (int i  = 0; i < s.length(); ++i)
    {
        int next = s[i] - 'a';
        if (!trie[root][next]) trie[root][next] = ++cnt;
        root = trie[root][next];
    }
    ++cntword[root];
    return root;
}

void Build_AC_Trie()
{
    queue<int> q;
    for (int i = 0; i < 26; ++i)
        if (trie[0][i] > 0) { fail[trie[0][i]] = 0; q.push(trie[0][i]); }
    while (!q.empty())
    {
        int now = q.front(); q.pop();
        for (int i = 0; i < 26; ++i)
        {
            int &v = trie[now][i];
            if (v > 0)
            {
                fail[v] = trie[fail[now]][i];
                q.push(v);
            }
            else v = trie[fail[now]][i];
            last[v] = cntword[fail[v]] ? fail[v] : last[fail[v]];
        }
    }
}

int query(string s)
{
    int now = 0, ans = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        now = trie[now][s[i] - 'a'];
        for (int j = now; j; j = last[j])
            ans += cntword[j];
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    int m, x, y;
    string str;
    char c;
    while (cin.get(c))
    {
        if (c == '\n') break;
        if (c == 'P') { ind.insert(pair<string, int> (str, Build_Trie(str))); strs.push_back(str); }
        else if (c == 'B' && str.length() != 0) {
            str.erase(str.end() - 1);
        }  
        else str += c;
    }

    Build_AC_Trie();
    memset(cntword, 0, sizeof(cntword));
    cin >> m;

    while (m--)
    {
        cin >> x >> y;
        cntword[ind[strs[x - 1]]] = 1;
        cout << query(strs[y - 1]) << endl;
        cntword[ind[strs[x - 1]]] = 0;
    }
}