#include<iostream>
#include<stack>
using namespace std;

int main() {
    int n, m;
    stack<int> paint;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        while(!paint.empty()) {
            int buff = paint.top();
            if (m >= buff) paint.pop();
            else break;
        }
        paint.push(m);
    }
    cout << paint.size();
    return 0;
}