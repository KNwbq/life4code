#include<iostream>
#include<queue>
#include<map>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
const int maxn = 1020;

int main() {
    int n, m, ans;
    bool inf;
    while (cin >> n) {
        if (n == 0) return 0;
        map<string, int> id;
        vector<int> friends[maxn];
        string s1, s2;
        ans = 0; inf = false;
        for (int i = 0; i < n; ++i) {
            cin >> s1;
            id[s1] = i+1;
        }
        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> s1 >> s2;
            friends[id[s1]].push_back(id[s2]);
            friends[id[s2]].push_back(id[s1]);
        }
        for (int j = 1; j <= n; ++j) {
            int length[maxn];
            for (int i = 0; i < maxn; ++i) 
                length[i] = 1000000;
            length[j] = 0;
            queue<pair<int, int>> bfs;
            bfs.push(make_pair(j,0));
            while (!bfs.empty()) {
                int curid = bfs.front().first;
                int len = bfs.front().second;
                bfs.pop();
                for (int i = 0; i < (int)friends[curid].size(); ++i) {
                    if (len+1 < length[friends[curid][i]]) {
                        bfs.push(make_pair(friends[curid][i], len+1));
                        length[friends[curid][i]] = len+1;
                    }
                }
            }
            for (int i = 1; i <= n; ++i) {
                ans = max(ans, length[i]);
                if (length[i] == 1000000) {
                    cout << -1 << endl;
                    inf = true;
                    break;
                }
            }
            if (inf) break;
        }
        if (!inf) cout << ans << endl;
    }
    return 0;
}