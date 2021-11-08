#include<iostream>
#include<cstring>
#include<queue>
#define mem(x) memset(x, 0, sizeof(x))
using namespace std;
const int maxn = 25;
int x[4] = {0, 0, -1, 1};
int y[4] = {1, -1, 0, 0};
bool vis[maxn][maxn];

int main() {
    int w, h, xx, yy, cnt;
    while (cin >> w >> h) {
        if (w == 0 && h == 0) return 0;
        cnt = 0;
        queue<pair<int, int>> bfs;
        char room[maxn][maxn]; mem(vis);
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j) {
                cin >> room[i][j];
                if (room[i][j] == '@') { xx = i; yy = j; }
            }
        vis[xx][yy] = 1;
        bfs.push(make_pair(xx, yy));
        while (!bfs.empty()) {
            int cx = bfs.front().first;
            int cy = bfs.front().second;
            // cout << cx << ' ' << cy << endl;
            bfs.pop(); ++cnt;
            for (int i = 0; i < 4; ++i) {
                int nx = cx+x[i], ny = cy+y[i];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && (!vis[nx][ny]) && room[nx][ny] == '.') { bfs.push(make_pair(nx, ny)); vis[nx][ny] = 1; }
            }
        }
        cout << cnt << endl;
    } 
}