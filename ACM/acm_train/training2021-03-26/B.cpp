#include<iostream>
#include<algorithm>
using namespace std;

struct node {
    int x, y;
    node(int x=0, int y=0):x(x), y(y){};
};

node func(int x, int m) {
    int cnt = 0; 
    while (x % m == 0) {
        x /= m;
        ++cnt;
    }
    return node(cnt, x);
}

int main() {
    int n, a, b, a3, a5, b3, b5, cnt = 0;
    bool flag = true;
    node buff;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        if (!flag) continue;
        buff = func(a, 3);
        a3 = buff.x, a = buff.y;
        buff = func(a, 5);
        a5 = buff.x, a = buff.y;
        buff = func(b, 3);
        b3 = buff.x, b = buff.y;
        buff = func(b, 5);
        b5 = buff.x, b = buff.y;
        if (a != b) { flag = false; continue; }
        if (a5 > b5) {
            cnt += a5-b5;
            a3 += a5-b5;
        }
        else if(b5 > a5){
            cnt += b5-a5;
            b3 += b5-a5;
        }
        cnt += abs(a3-b3);
    }
    if (flag) cout << cnt;
    else cout << "-1";
    return 0;
}