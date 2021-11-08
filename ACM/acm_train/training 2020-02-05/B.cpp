#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
#define double long double
using namespace std;
const int maxn = 1e5 + 20;
const double pi = acos(-1);
const double eps = 1e-10;

struct node {
    double x, y;
    node() {}
    node(double xx, double yy) : x(xx), y(yy) {}
    friend node operator-(node a, node b) { return node(a.x-b.x, a.y - b.y); }
}p, nodes[maxn];

double cross(node a, node b) {
    return (a.x*b.y - a.y*b.x);
}

double dot(node a, node b) {
    return (a.x*b.x + a.y*b.y);
}

double dist(node a, node b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

double mind(node p, node a, node b) {
    double val = dot(p-a, b-a);
    if(val <= eps) return sqrt(dist(p, a));
    double d = dist(a, b);
    if(val >= d) return sqrt(dist(p, b));
    return fabs(cross(a-p, b-p)) / sqrt(d);
}

int main()
{
    ios::sync_with_stdio(0);
    int n;
    double xx, yy, lmax = -1, lmin = 0x3f3f3f3f;
    cin >> n >> p.x >> p.y;
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].x >> nodes[i].y;
        lmax = max(lmax, sqrt(dist(nodes[i], p)));
    }    
    //cout << lmax << endl;

    for (int i = 0; i < n; ++i) 
        lmin = min(lmin, mind(p, nodes[i], nodes[(i+1)%n]));
    //cout << lmin << endl;

    cout << fixed << setprecision(18) << pi * (lmax * lmax - lmin * lmin) << endl;
    return 0;
}