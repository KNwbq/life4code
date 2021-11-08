#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int a, b, c, d, f, arry[4];
    bool first = true;
    while (cin >> a >> b >> c >> d) {
        if (a == 0 && b == 0 && c == 0 && d == 0) return 0;
        if (!first) cout << endl;
        arry[0] = a; arry[1] = b; arry[2] = c; arry[3] = d; f = 0;
        sort(arry, arry+4);
        if (arry[0] == 0) while (arry[++f] == 0);
        swap(arry[0], arry[f]); f = arry[0];
        do {
            if (arry[0] != f) { f = arry[0]; cout << endl; }
            for (int i = 0; i < 4; ++i) cout << arry[i]; 
            if(next_permutation(arry, arry+4)) {
                if (arry[0] == f) cout << ' ';
            }
            prev_permutation(arry, arry+4);
        } while (next_permutation(arry, arry+4));
        cout << endl; first = false;
    }
    return 0;
}