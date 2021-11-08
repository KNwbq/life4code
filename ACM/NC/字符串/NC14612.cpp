#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
const int maxn = 100;

int trie[maxn][26];
int fail[maxn];
int last[maxn];
int cntword[maxn];
int cnt = 0;
int pos[maxn];
stack<int> ans;

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

void init()
{
    for (int i = 0; i < maxn; ++i) 
    {
        for (int j = 0; j < 26; ++j) trie[i][j] = 0;
        cntword[i] = 0; fail[i] = 0; last[i] = 0;
    }
    cnt = 0;
}

int main()
{
    int T, N, M, op[maxn];
    string s[maxn],ss;
    cin >> T;
    while (T--)
    {
        init();
        cin >> N >> M;
        while (N--) { cin >> ss; Build_Trie(ss); }
        for (int i = 0; i < M; ++i) {
            cin >> op[i] >> s[i];
            if (op[i] == 1) { pos[i] = Build_Trie(s[i]); }
        }
        Build_AC_Trie();
        for (int i = M - 1; i >= 0; --i)
        {
            if (op[i] == 1) cntword[pos[i]] = 0;
            else ans.push(query(s[i]));
        }
        while (!ans.empty())
        {
            cout << ans.top() << endl; ans.pop();
        }
    }
    system("pause");
}