#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    while(cin >> s) {
        bool def = true;
        int len = s.length();
        if (len%2) {
            for (int i = 0; i < len+1; ++i) {
                if (i < (len+1)/2) cout << 1;
                else cout << 9;
            }
            cout << endl;
        }
        else {
            for (int i = 0; i < len; ++i) {
                if (i <len/2 && s[i] < '9') break;
                else if (i >= len/2 && s[i] > '1') { def = false; break; }
            }
            if (!def) {
                for (int i = 0; i < len+2; ++i) {
                    if (i < (len+2)/2) cout << 1;
                    else cout << 9;
                }
                cout << endl;
            }
            else {
                int n1 = len/2, n9 = len/2;
                for (int i = 0; i < len; ++i) {
                    if (s[i] == '9') { cout << 9; --n9; }
                    else if (s[i] == '0') {
                        if (n1 > 0) { cout << 1; --n1; }
                        for(int i = 0; i < n1; ++i) cout << 1;
                        for(int i = 0; i < n9; ++i) cout << 9;
                        cout << endl; def = false;
                        break;
                    }
                    else if (s[i] > '1' && s[i] < '9') { 
                        cout << 9; --n9; 
                        for(int i = 0; i < n1; ++i) cout << 1;
                        for(int i = 0; i < n9; ++i) cout << 9;
                        cout << endl; def = false;
                        break;
                    }
                    else if(n1 > 0){
                        string s1, s2;
                        for (int i = 0; i < n9; ++i) s1 += '9';
                        for (int i = 0; i < n1-1; ++i) s1 += '1';
                        for (int j = i+1; j < len; ++j) s2 += s[j];
                        if (s1 < s2) { 
                            cout << 9; --n9; 
                            for(int i = 0; i < n1; ++i) cout << 1;
                            for(int i = 0; i < n9; ++i) cout << 9;
                            cout << endl; def = false;
                            break;
                        }
                        else { cout << 1; --n1; }
                    }
                    else {
                        for (int i = 0; i < n9; ++i) cout << 9;
                        cout << endl; def = false;
                        break;
                    }
                }
                if (def) cout << endl;
            }
        }
    }
    return 0;
}