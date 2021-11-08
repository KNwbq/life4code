// #include<iostream>
// #include<vector>
// #include<cstring>
// #define ms(x) memset(x, 0, sizeof(x))
// using namespace std;
// const int maxn = 1e5;
// bool vis[maxn];

// int main() {
//     ios::sync_with_stdio(0);
//     int n, m;
//     while (cin >> n >> m ) {
//         vector<int> b; b.clear();
//         int ans[maxn];
//         ms(vis); ms(ans);
//         for (int cnt = 0, pos = 1; cnt < n; pos=pos%(2*n)+1) {
//             if (!vis[pos]) {
//                 b.push_back(pos);
//                 if ((int)b.size() == m) {
//                     vis[pos]=1;
//                     ans[pos] = 1; ++cnt;
//                     b.clear();
//                 }
//             }
//         }
//         for (int i = 1; i <= 2*n; ++i) {
//             if (ans[i] == 1) cout << 'B';
//             else cout << 'G';
//             if (i%50 == 0 && i != 2*n) cout << endl;
//         }
//         cout << endl << endl;
//     }
// }

#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<int> table;
        int pos = 0;
        for (int i = 0; i < 2*n; ++i) table.push_back(i);
        for (int cnt = 0; cnt < n; ++cnt) 
            table.erase(table.begin()+(pos=(pos+m-1)%table.size()));
        pos = 0;
        for (int i = 0; i < 2*n; ++i) {
            if (pos < n && table[pos] == i) { cout << 'G'; ++pos; }
            else cout << 'B';
            if ((i+1)%50 == 0 && i != 2*n-1) cout << endl;
        }
        cout << endl << endl;
    }
}