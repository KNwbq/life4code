#include<iostream>
#include<stack>
#include<iomanip>
using namespace std;

int main() {
    int n; 
    char c;
    stack<double> num;
    while (cin >> n) {
        double ans = 0;
        c = getchar();
        if (n == 0 && c == '\n') return 0;
        c = getchar(); 
        num.push(n);
        double m;
        while (cin >> n) {
            if (c == '+') num.push(n);
            else if (c == '-') num.push(-1*n);
            else if (c == '*') { m = num.top(); num.pop(); num.push(m*n); }
            else if (c == '/') { m = num.top(); num.pop(); num.push(m/n); }
            if(getchar()=='\n')
                break;
            c = getchar();
        }
        while (!num.empty()) { ans += num.top(); num.pop(); }
        cout << fixed << setprecision(2) << ans << endl;
    }
}