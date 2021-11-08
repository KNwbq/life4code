#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;
const int error = 1000;
int cnt = 1;
int cnt2 = 0;
int row = 0;
int col = 0;

class Scanner {
private:
    const string keyWord[maxn] = { "and", "array", "begin", "bool", "call", "case", "char", "constant", "dim", "do", "else", 
                   "end", "false", "for", "if", "input", "integer", "not", "of", "or", "output", "procedure", 
                   "program", "read", "real", "repeat", "set", "stop", "then", "to", "true", "until", "var", "while", "write" };
    const string douBound[maxn] = { "*/", "..", "/*", ":=", "<=", "<>", ">=" };
    const char simBound[maxn] = { '+', '-', '*', '/', '=', '<', '>', '(', ')', '[', ']', ':', '.', ';', ',', '\''};
    map<string, int> douBoundId = { {"*/", 42}, {"..", 47}, {"/*", 49}, {":=", 51}, {"<=", 54}, {"<>", 55}, {">=", 58} };
    map<string, int> simBoundId = { {"+", 43}, {"-", 45}, {"*", 41}, {"/", 48}, {"=", 56}, {"<", 53}, {">", 57}, {"(", 39}, 
                                 {")", 40}, {"[", 59}, {"]", 60}, {":", 50}, {".", 46}, {";", 52}, {",", 44}, {"\'", maxn} };
    map<string, int> id;
public:
    string s;
    Scanner() {}
    bool isNum(char c) {
        if (c >= '0' && c <= '9') return true;
        return false;
    }
    bool isCha(char c) {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') return true;
        return false;
    }
    bool isSim(char c) {         //判断单
        for (auto it: simBound)
            if (it == c) return true;
        return false;
    }
    bool isDou(string s) {       //判断双
        for (auto it: douBound)
            if (it == s) return true;
        return false;
    }
    int inCS(string c) {          //判断字符集
        int length = c.length();
        for (int i = 0; i < length; ++i)
            if (!(isCha(c[i]) || isSim(c[i]) || isNum(c[i]))) return i+1;
        return 0;
    }
    int isKey(string s) {        //判断关键字
        for (int i = 0; i < 35; ++i)
            if (keyWord[i] == s) return i+1;
        return 0;
    }
    bool isInt(string s) {       //判断整数
        int length = s.length();
        for (int i = 0; i < length; ++i)
            if (!isNum(s[i])) return false;
        return true;
    }
    bool isIden(string s) {      //判断标识符
        int length = s.length();
        if (!isCha(s[0])) return false;
        for (int i = 1; i < length; ++i)
            if (!(isNum(s[i]) || isCha(s[i]))) return false;
        return true;
    }
    bool isStr(string s) {       //判断字符串常数
        int length = s.length();
        if (length < 3) return false;
        if (s[0] == '\'' && s[length-1] == '\'') return true;
        return false;
    }
    bool isWhite(char s) {       //判断空
        return s == ' ';
    }

    void Define(string s, int Col) {
        // cout << "D " << s << '\n';
        int offset;
        if (offset = inCS(s), offset) { cout << "Error(" << row << ", " << Col + offset - 1 << "): " << "Illegal symbol! "; ++cnt2; if (cnt2%5 == 0) putchar('\n');}
        else if (isKey(s)) { cout << '(' << isKey(s) << ", " << "-) "; ++cnt2; if (cnt2%5 == 0) putchar('\n');}
        else if (isInt(s)) { 
            if (!id.count(s)) { id.insert(make_pair(s, cnt)); ++cnt; }
            cout << "(37, " << id[s] << ") "; ++cnt2; if (cnt2%5 == 0) putchar('\n');
        }
        else if (isIden(s)) { 
            if (!id.count(s)) { id.insert(make_pair(s, cnt)); ++cnt; }
            cout << "(36, " << id[s] << ") "; ++cnt2; if (cnt2%5 == 0) putchar('\n');
        }
        else if (isStr(s)) { 
            if (!id.count(s)) { id.insert(make_pair(s, cnt)); ++cnt; }
            cout << "(38, " << id[s] << ") "; ++cnt2; if (cnt2%5 == 0) putchar('\n');
        }
        else if (isDou(s)) {
            cout << "(" << douBoundId[s] << ", -) "; ++cnt2; if (cnt2%5 == 0) putchar('\n');
        }
        else if (s.length() == 1 && isSim(s[0])) {
            cout << "(" << simBoundId[s] << ", -) "; ++cnt2; if (cnt2%5 == 0) putchar('\n');
        }
        else { cout << "Error(" << row << ", " << Col << "): " << "Invalid expression! "; ++cnt2; if (cnt2%5 == 0) putchar('\n');}
    }
};

int main() {
    string path;
    cout << "吴斌权 19计创 201930343483\n";
    cin >> path;
    path = path + ".txt";
    freopen(path.c_str(), "r", stdin);
    // freopen("D:\\code\\VSCODE\\DataTest\\data.in.txt", "r", stdin);
    // freopen("D:\\code\\VSCODE\\DataTest\\data.out.txt", "w", stdout);
    Scanner A;
    while (getline(cin, A.s)) {
        ++row;
        for (int i = 0, j = 0; i < A.s.length();) {
            while (j < A.s.length() && A.isWhite(A.s[j])) ++j;
            i = j;
            if (i == A.s.length()) continue;
            while (j < A.s.length() && !(A.isSim(A.s[j]) || A.isWhite(A.s[j]))) ++j;
            if (i != j) { string buff = A.s.substr(i, j-i); A.Define(buff, i); i = j; }
            if (j == A.s.length()) continue;
            if (A.isSim(A.s[j])) {
                if (A.s[j] == '\'') { 
                    col = j;
                    while(j+2 < A.s.length() && !(A.s[j+1] != '\\' && A.s[j+2] == '\'')) ++j;
                    if (j+2 < A.s.length()) { A.Define(A.s.substr(i, j-i+3), i); j = j+3; i = j; }
                    else { cout << "Error(" << row << ", " << col << ')' << ": No match\' "; j += 2; i = j; ++cnt2; if (cnt2%5 == 0) putchar('\n');}
                }
                else if (j + 1 < A.s.length() && A.isDou(A.s.substr(j, 2))) {
                    if (A.s[j] == '/' && A.s[j+1] == '*') {
                        col = j;
                        while (j+3 < A.s.length() && !(A.s[j+2] == '*' && A.s[j+3] == '/')) ++j;
                        if (j+3 == A.s.length()) { cout << "Error(" << row << ", " << col << ')' << ": No match/* "; j += 3; i = j; ++cnt2; if (cnt2%5 == 0) putchar('\n');}
                    }
                    else A.Define(A.s.substr(j, 2), j); j += 2; i = j;
                }
                else { A.Define(string(1, A.s[j]), j); ++j; i = j; }
            }
        }
    }
}