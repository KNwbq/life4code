#include<iostream>
#include<cstring>
using namespace std;

bool def(int y, int m, int d)
{
    bool flag = true;
    if ((y % 100 == 0 && y % 400 == 0) || (y % 100 != 0 && y % 4 == 0))
    {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
            { if (d > 31) flag = false; }
        else if (m != 2) { if (d > 30) flag = false; }
        else if (d > 29) flag = false;
    }
    else {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
            { if (d > 31) flag = false; }
        else if (m != 2) { if (d > 30) flag = false; }
        else if (d > 28) flag = false;
    }
    return flag;
}

char str[135];
char s[12];

int main()
{
    while ( cin.getline(s, 12) )
    {
        bool f = true, a = false;
        int y = 0, m = 0, d = 0, k = 1000;
        for (int i = 0; i < 8; ++i) {
            if (s[i] < '0' || s[i] > '9') { a = true; break; }
        }
        for (int i = 0; i < 4; ++i) {
            y += (s[i] - '0') * k; k /= 10;
        }
        k = 10;
        for (int i = 4; i < 6; ++i) {
            m += (s[i] - '0') * k; k /= 10;
        }
        k = 10;
        for (int i = 6; i < 8; ++i) {
            d += (s[i] - '0') * k; k /= 10;
        }

        if (strlen(s) != 8) f = false;
        else if (y < 1900 || y > 2020 || m < 1 || m > 12) f = false;
        else if (def(y, m, d) == false) f = false;

        cin.getline(str, 130);

        for (int i = 0; i < strlen(str); ++i) {
            if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == ' ')) a = true;
        }
        if (a) {
            cout << "none" << endl; continue;
        }
        k = 0;
        for (int i = 0; i < 8; ++i) k += (int)s[i] - (int)'0';
        while ( k >= 10)
            k = k / 10 + k % 10;
        for (int i = 0; i < strlen(str); ++i) {
            if (str[i] == ' ') str[i] = '#';
            else if ( str[i] >= 'a' && str[i] <= 'z') {
                str[i] = ( (str[i] - 'a') + (char)k ) % 26 + 'a';
            }
            else str[i] = ( (str[i] - 'A') + (char)k ) % 26 + 'A';
        }
        if (f) cout << str << endl;
        else cout << "none" << endl;
    }
}