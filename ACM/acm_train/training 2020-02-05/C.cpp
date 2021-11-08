#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 20;

struct node {
    double x, y;
    node(double xx, double yy) : x(xx), y(yy) {}
    node() {}
}nodes[maxn];

double dis(node a, node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
    int pos; double minx = 1e6, dist = 0, ans = 0;
    nodes[1].x = 0; nodes[1].y = 0;
    nodes[2].x = 0; nodes[2].y = 4;
    nodes[3].x = 2; nodes[3].y = 3;
    nodes[4].x = 3; nodes[4].y = 2;
    nodes[5].x = 4; nodes[5].y = 1;
    nodes[6].x = 4; nodes[6].y = 6;
    nodes[7].x = 5; nodes[7].y = 2;
    nodes[8].x = 5; nodes[8].y = 4;
    nodes[9].x = 7; nodes[9].y = 2;
    nodes[10].x = 8; nodes[10].y = 1;
    nodes[11].x = 8; nodes[11].y = 5;
    for (int i = 1; i <= 11; ++i) {
        for (int j = 1; j <= 11; ++j) 
            dist += dis(nodes[i], nodes[j]);
        if (dist < minx) { minx = dist; pos = i; }
        dist = 0;
    }
    cout << char(pos - 1 + 'A') << ' ' << minx;
    system("pause");
}
