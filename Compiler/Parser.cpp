#include<bits/stdc++.h>
using namespace std;
const int maxn = 2500;
const int error = 1000;
int cnt = 1;
int cnt2 = 0;
int numQ = 0;
int numT = 1;
string table[maxn][maxn];
map<string, set<char> > first[maxn];
int Tchain[maxn];
int Fchain[maxn];
int four[maxn];
stack<int> headT;
stack<int> headF;

map<char, int> S2I = { {'a',23}, {'b',36}, {'c',33}, {'d',17}, {'e',4}, {'f',7}, {'h',20}, {'i', 1}, {'j', 18}, 
                       {'k',55}, {'l',54}, {'m',58}, {'o',51}, {'p',15}, {'q',29}, {'r',11}, {'s',34}, {'t',10}, {'u',26}, 
                       {'v',32}, {'w',3}, {'x',12},
                       {'+',43}, {'-',45}, {'*',41}, {'/',48}, {'=',56}, {'<',53}, 
                       {'>',57}, {'(',39}, {')',40}, {'.',46}, {';',52}, {',',44}, {':',50}, {'$', 99},
                       {'A', 101}, {'C', 102}, {'D', 103}, {'U', 104}, {'G', 105}, {'H', 106}, {'E', 128}, 
                       {'I', 107}, {'J', 108}, {'K', 109}, {'L', 110}, {'M', 111}, {'N', 112}, {'P', 113},
                       {'Q', 114}, {'R', 115}, {'0', 116}, {'1', 117}, {'2', 118}, {'3', 119}, {'4', 120},
                       {'5', 121}, {'6', 122}, {'7', 123}, {'8', 124}, {'9', 125}, {'W', 126}, {'T', 127} };

struct token {
    int kind;
    string value;
    token(int x, string s): kind(x), value(s) {}
};
vector<token> lexeme;

struct node {
    int input;
    char type_;
    int nextS;
    node(int a = 0, char b = '#', int x = 0): input(a), type_(b), nextS(x) {}
};
vector<node> AG[maxn];

void init() {
    for (int i = 0; i < maxn; ++i) { Fchain[i] = Tchain[i] = four[i] = -1; }
}

void mergeT(int x, int y) {
    Tchain[y] = x;
    if (!headT.empty() && x == headT.top()) { headT.pop(); headT.push(y); }
    else headT.push(y);
}

void mergeF(int x, int y) {
    Fchain[y] = x;
    if (!headF.empty() && x == headF.top()) { headF.pop(); headF.push(y); }
    else headF.push(y);
}

void backpatchT(int begin_, int T) {
    for (int i = begin_; i != -1; i = Tchain[i]) {
        four[i] = T;
    }
    if (!headT.empty()) headT.pop();
}

void backpatchF(int begin_, int F) {
    for (int i = begin_; i != -1; i = Fchain[i]) {
        four[i] = F;
    }
    if (!headF.empty()) headF.pop();
}

struct node2 {
    string s1, s2, s3, s4;
    node2() {}
    node2(string S1, string S2, string S3, string S4): s1(S1), s2(S2), s3(S3), s4(S4){}
    void plus(int x) {
        if (s4 == "0") s4 = to_string(stoi(s4)+x);
    }
}Quatersion[maxn];

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
        if (offset = inCS(s), offset) { cout << "Error" << ":Illegal symbol! "; exit(0); }
        else if (isKey(s)) { lexeme.push_back(token(isKey(s),s)); }
        else if (isInt(s)) { 
            if (!id.count(s)) { id.insert(make_pair(s, cnt)); ++cnt; }
            lexeme.push_back(token(36, s));
        }
        else if (isIden(s)) { 
            if (!id.count(s)) { id.insert(make_pair(s, cnt)); ++cnt; }
            lexeme.push_back(token(36, s));
        }
        else if (isStr(s)) { 
            if (!id.count(s)) { id.insert(make_pair(s, cnt)); ++cnt; }
            lexeme.push_back(token(38, s));
        }
        else if (isDou(s))
            lexeme.push_back(token(douBoundId[s], s));
        else if (s.length() == 1 && isSim(s[0]))
            lexeme.push_back(token(simBoundId[s], s));
        else { cout << "Error" << ":Invalid expression! "; exit(0); }
    }
    void scanning() {
        Scanner A;
        while (getline(cin, A.s)) {
            for (int i = 0, j = 0; i < A.s.length();) {
                while (j < A.s.length() && A.isWhite(A.s[j])) ++j;
                i = j;
                if (i == A.s.length()) continue;
                while (j < A.s.length() && !(A.isSim(A.s[j]) || A.isWhite(A.s[j]))) ++j;
                if (i != j) { string buff = A.s.substr(i, j-i); A.Define(buff, i); i = j; }
                if (j == A.s.length()) continue;
                if (A.isSim(A.s[j])) {
                    if (A.s[j] == '\'') { 
                        while(j+2 < A.s.length() && !(A.s[j+1] != '\\' && A.s[j+2] == '\'')) ++j;
                        if (j+2 < A.s.length()) { A.Define(A.s.substr(i, j-i+3), i); j = j+3; i = j; }
                        else { cout << "Error:" << "No match\'"; exit(0); }
                    }
                    else if (j + 1 < A.s.length() && A.isDou(A.s.substr(j, 2))) {
                        if (A.s[j] == '/' && A.s[j+1] == '*') {
                            while (j+3 < A.s.length() && !(A.s[j+2] == '*' && A.s[j+3] == '/')) ++j;
                            if (j+3 == A.s.length()) { cout << "Error:" << ": No match/* "; j += 3; i = j; ++cnt2; }
                        }
                        else A.Define(A.s.substr(j, 2), j); j += 2; i = j;
                    }
                    else { A.Define(string(1, A.s[j]), j); ++j; i = j; }
                }
            }
        }
        lexeme.push_back(token(99, "$"));
    }
};

class ItemSet {
public:
    vector<string> INPUT = {
                                "E->ab;AW.",
                                "A->cC",
                                "C->D:U;C|D:U;",
                                "D->b,D|b",
                                "U->d|e|f",
                                "G->G+H|G-H|H",
                                "H->H*I|H/I|I",
                                "I->J|-I",
                                "J->b|(G)",
                                "K->KhL|L",
                                "L->LiM|M",
                                "M->N|jM",
                                "N->b|(K)|bPb|GPG",
                                "P-><|k|l|m|>|=",
                                "Q->R|1|3|6|8|W",
                                "R->boG",
                                "0->pKq",
                                "1->0Q",
                                "2->1r",
                                "3->2Q",
                                "4->s",
                                "5->4Kt",
                                "6->5Q",
                                "7->u",
                                "8->7QvK",
                                "W->wTx",
                                "T->Q;T|Q",
                           };
    vector<string> EXPRESSIONS;
    vector<string> ITEMS;
    map<char, set<char> > FIRST;
    map<string, int> EID;
    int NUM_EXP;

    ItemSet(): NUM_EXP(0) { ADDE("S->E"); }

    bool isCap(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    void ADDE(string exp) {
        EXPRESSIONS.push_back(exp);
        EID.insert(make_pair(exp, NUM_EXP++));
    }

    void GETEXPS() {
        string exp;
        for (auto exp: INPUT) {
            int len = exp.length(), OR[maxn], cnt = 0;
            OR[cnt++] = 2;
            for (int i = 0; i < len; ++i)
                if (exp[i] == '|') OR[cnt++] = i;
            for (int i = 0; i < cnt - 1; ++i)
                ADDE(exp.substr(0, 3) + exp.substr(OR[i] + 1, OR[i+1] - OR[i] -1));
            ADDE(exp.substr(0, 3) + exp.substr(OR[cnt-1]+1));
        }
    }

    void PRINTEXP() {
        for (int i = 0; i <EXPRESSIONS.size(); ++i)
            cout << i << ' ' << EXPRESSIONS[i] << endl;
    }

    void GETITEMS() {
        for (auto it: EXPRESSIONS) {
            if (it[3] == '~') ITEMS.push_back(it.substr(0, 3) + "!");
            else {
                for (int i = 3; i < it.length(); ++i)
                    ITEMS.push_back(it.substr(0, 3) + it.substr(3, i - 3) + "!" + it.substr(i));
                ITEMS.push_back(it + "!");
            }
        }
    }

    void PRINTITEM() {
        for(auto it: ITEMS) 
            cout << it << endl;
    }

    vector<string> CLOSURE(string exp, set<string> isV = set<string>({})) {
        vector<string> EXP_CLOSURE;
        EXP_CLOSURE.push_back(exp);
        isV.insert(exp);
        int len = exp.length();
        for (int i = 0; i < len; ++i) {
            if (exp[i] == '!') {
                if (i < len - 1 && isCap(exp[i + 1])) {
                    for (auto it: ITEMS) {
                        int len2 = it.length();
                        if (!isV.count(it) && it[0] == exp[i + 1] && it[3] == '!') {
                            isV.insert(it);
                            vector<string> closure = CLOSURE(it, isV);
                            for (auto itc: closure)
                                EXP_CLOSURE.push_back(itc);
                        }
                    }
                } 
                else return vector<string>({exp});
            }
        }
        set<string> u_c(EXP_CLOSURE.begin(), EXP_CLOSURE.end());
        EXP_CLOSURE.assign(u_c.begin(), u_c.end());
        return EXP_CLOSURE;
    }

    void PRINTCLOSURE() {
        for (auto it: ITEMS) {
            cout << it << endl;
            vector<string> closure = CLOSURE(it);
            for (auto itc: closure) {
                cout << itc << endl;
            }
            cout << endl;
        }
    }

    void First() {
        for (int i = 0; i < NUM_EXP; ++i) {
            string exp = EXPRESSIONS[i];
            // int len = exp.length();
            if (!isCap(exp[3]))
                if (FIRST.count(exp[0]) == 0) FIRST.insert(make_pair(exp[0], set<char>({exp[3]})));
                else FIRST[exp[0]].insert(exp[3]);
        }
        for (int i = 0; i < 10; ++i) { // tranverse 10 times to get the first set
            for (int j = 0; j < NUM_EXP; ++j) {
                string exp = EXPRESSIONS[j];
                if (!FIRST.count(exp[0])) FIRST.insert(make_pair(exp[0], set<char>({})));
                if (isCap(exp[3])) {
                    if (!FIRST.count(exp[3])) FIRST.insert(make_pair(exp[3], set<char>({})));
                    else set_union(FIRST[exp[0]].begin(), FIRST[exp[0]].end(), FIRST[exp[3]].begin(), FIRST[exp[3]].end(), inserter(FIRST[exp[0]], FIRST[exp[0]].begin()));
                }
            }
        }
    }

    void PRINTFIRST() {
        map<char, set<char> >::iterator it;
        for (it = FIRST.begin(); it != FIRST.end(); ++it) {
            cout << it->first << endl;
            set<char>::iterator sit;
            for (sit = (it->second).begin(); sit != (it->second).end(); ++sit)
                cout << *sit << ' ';
            cout << endl << endl;
        }
           
    }

    char NEXTC(string item) {
        for (int i = 0; i < item.length(); ++i) 
            if (i < item.length() - 1 && item[i] == '!') return item[i + 1];
        return '^';
    }

    string GNEX(string item) {
        for (int i = 0; i < item.length(); ++i)
            if (i < item.length() - 1 && item[i] == '!') return item.substr(0, i) + item[i + 1] + item[i] + ((i + 2) < item.length()? item.substr(i+2): "");  // Warning
        return item;
    }
};

class DFA {
public:
    ItemSet items;
    vector<string> CLUSTER[maxn];
    int I;

    DFA(): I(0) {
        items.GETEXPS();
        items.GETITEMS();
        items.First();
        string start = items.ITEMS[0];
        vector<string> I0 = items.CLOSURE(start);
        map<string, set<char> >& cf = first[0];
        PUSH(I0); // The start cluster; I0
        for (int i = 0; i < maxn; ++i)
            for (int j = 0; j < maxn; ++j)
                table[i][j] = "%";
        for (auto it: I0) if (!cf.count(it)) cf.insert(make_pair(it, set<char>({})));
        cf[start].insert('$');
        GETN(cf, I0, start);
    }

    bool CHECKSET(set<char> a, set<char> b) { // a include b
        set<char>::iterator pb, pa;
        for (pb = b.begin(); pb != b.end(); ++pb) {
            bool flag = false;
            for (pa = a.begin(); pa != a.end(); ++pa) 
                if ((*pb) == (*pa)) { flag = true; break; }  
            if (!flag) return false;
        }
        return true;
    }

    bool CHECKSET3(set<char> a, set<char> b) { 
        set<char>::iterator pb, pa;
        if (a.size() != b.size()) return false;
        for (pb = b.begin(); pb != b.end(); ++pb) {
            bool flag = false;
            for (pa = a.begin(); pa != a.end(); ++pa) 
                if ((*pb) == (*pa)) { flag = true; break; }  
            if (!flag) return false;
        }
        return true;
    }

    bool CHECKSET2(map<string, set<char> > a, map<string, set<char> > b) { // a == b
        map<string, set<char> >::iterator pa, pb;
        bool flag = true;
        for (pa = a.begin(); pa != a.end(); ++pa) {
            string indexa = (*pa).first;
            if (!CHECKSET3(a[indexa], b[indexa])) { flag = false; break; } 
        }
        return flag;
    }

    void GETN(map<string, set<char> >& f, vector<string> clu, string cur) {
        // cout << cur << endl;
        char nc = items.NEXTC(cur);
        char nnc = items.NEXTC(items.GNEX(cur));
        // cout << nc << ' ' << nnc << endl;
        if (!items.isCap(nc)) return; // A->B! || A->!aA
        if (nnc == '^') {  // A->!B
            for (auto it: clu) {
                // cout << it << endl;
                if ((!(it[0] == nc && it[3] == '!')) || CHECKSET(f[it], f[cur])) continue; // if f[it] has f[cur] then return
                set_union(f[it].begin(), f[it].end(), f[cur].begin(), f[cur].end(), inserter(f[it], f[it].begin()));
                GETN(f, clu, it);
            }
        }
        else {
            for (auto it: clu) {
                if (it[0] == nc && it[3] == '!') {
                    if (items.isCap(nnc)) {
                        if (CHECKSET(f[it], f[cur])) continue;
                        set_union(f[it].begin(), f[it].end(), items.FIRST[nnc].begin(), items.FIRST[nnc].end(), inserter(f[it], f[it].begin()));
                        GETN(f, clu, it);
                    }
                    else {
                        if (f[it].count(nnc)) continue;
                        f[it].insert(nnc);
                        GETN(f, clu, it);
                    }
                        
                    
                } 
            }
        }
    }

    bool CHECK(vector<string> Ia, vector<string> Ib) {
        if (Ia.size() != Ib.size()) return false;
        for (auto it1: Ia) {
            bool flag = false;
            for (auto it2: Ib) {
                if (it1 == it2) { flag = true; break; } 
            }
            if (!flag) return false;
        }
        return true;
    }

    void PUSH(vector<string> II) {
        CLUSTER[I++] = II;
    }

    void GENDFA(int sta = 0) {
        set<char> inputsymbol;
        set<char>::iterator iter;
        vector<string> cluster = CLUSTER[sta];
        for (int i = 0; i < cluster.size(); ++i) {
            if (items.NEXTC(cluster[i]) != '^')
                inputsymbol.insert(items.NEXTC(cluster[i]));
        }

        for (iter = inputsymbol.begin(); iter != inputsymbol.end(); ++iter) {
            vector<string> buffer;
            map<string, set<char> > fbuffer;
            bool exist = false;
            for (int i = 0; i < cluster.size(); ++i)
                if (items.NEXTC(cluster[i]) == *iter) {
                    string next = items.GNEX(cluster[i]);
                    vector<string> clo = items.CLOSURE(next);
                    for (auto it: clo) if (!fbuffer.count(it)) fbuffer.insert(make_pair(it, set<char>({})));
                    set_union(fbuffer[next].begin(), fbuffer[next].end(), first[sta][cluster[i]].begin(), first[sta][cluster[i]].end(), inserter(fbuffer[next], fbuffer[next].begin()));
                    GETN(fbuffer, clo, next);
                    for (auto it: clo) buffer.push_back(it);
                }
                set<string> u_c(buffer.begin(), buffer.end());
                buffer.assign(u_c.begin(), u_c.end());
            for (int i = 0; i < I; ++i)
                if (CHECK(CLUSTER[i], buffer) && CHECKSET2(first[i], fbuffer)) { table[sta][i] = *iter; exist = true; break; }
            if (!exist) { PUSH(buffer); table[sta][I-1] = *iter; first[I - 1] = fbuffer; GENDFA(I - 1); }
        }
    }

    void PRINTDFA() {
        for (int i = 0; i < I; ++i) {
            cout << 'I' << i << endl;
            for (auto it: CLUSTER[i]) 
                cout << it << endl;
            cout << endl;
        }
    }

    void PRINTTAB() {
        for (int i = 0; i < I; ++i)
            for (int j = 0; j < I; ++j)
                if (table[i][j] != "%") cout << i << ' ' << j << ' ' << table[i][j] << endl;
    }

    void PRINTF() {
        for (int i = 0; i < I; ++i) {
            cout << 'I' << i << endl;
            map<string, set<char> >::iterator it;
            set<char>::iterator it2;
            for (it = first[i].begin(); it != first[i].end(); ++it) {
                cout << (*it).first << ' ';
                for (it2 = (*it).second.begin(); it2 != (*it).second.end(); ++it2) 
                    cout << (*it2) << ' ';
                cout << endl;
            }
        }
    }
};

class ACTION_GOTO {
public:
    DFA dfa;
    ACTION_GOTO() { dfa.GENDFA(); AG[1].push_back(node(S2I['$'], 'a', 0)); }
    void GENTABLE() {
        for (int i = 0; i < dfa.I; ++i) {
            set<char> ebuffer = {'a','b','c','d','e','f','h','i','j','k','l','m','o','p','q','r','s','t','u',
                                 'v','w','x','+','-','*','/','=','<','>','(',')','.',';',',',':','$',
                                 'A', 'C','D','U','G','H','E','I','J','K','L','M','N','P','Q','R','0','1','2','3','4','5','6','7','8','W','T' }; // record the error
            set<char>::iterator it3;
            for (int j = 0; j < dfa.I; ++j) {
                char c = table[i][j][0];
                if (!dfa.items.isCap(c) && c != '%') { AG[i].push_back(node(S2I[c], 's', j)); ebuffer.erase(c); } // SHIFT items
                else if (dfa.items.isCap(c)) { AG[i].push_back(node(S2I[c], 'g', j)); ebuffer.erase(c); } // GOTO items
            }
            map<string, set<char> > buffer = first[i];
            map<string, set<char> >::iterator it;
            set<char>::iterator it2;
            for (it = buffer.begin(); it != buffer.end(); ++it) {
                string s = it->first; int len = s.length();
                if (s[len-1] == '!') {
                    for (it2 = (it->second).begin(); it2 != (it->second).end(); ++it2) {
                        ebuffer.erase(*it2);
                        AG[i].push_back(node(S2I[*it2], 'r', dfa.items.EID[s.substr(0, len-1)])); // REDUCED items
                    }
                }
            }
            for (it3 = ebuffer.begin(); it3 != ebuffer.end(); ++it3) AG[i].push_back(node(S2I[*it3], 'e', 0));
        }
    }
    void PRINTTABLE() {
        for (int i = 0; i < dfa.I; ++i) {
            cout << 'I' << i << ' ';
            for (int j = 0; j < AG[i].size(); ++j) 
                cout << AG[i][j].input << '-' << AG[i][j].type_ << AG[i][j].nextS << ' ';
            cout << endl; 
        }
    }
};

class Stack {
public:
    ACTION_GOTO ag;
    Scanner scan;
    stack<int> staS;
    stack<string> sybS;
    stack<int> whileN;
    stack<int> repeatN;
    stack<int> ifthen;
    set<string> identify;

    Stack() { scan.scanning(); ag.GENTABLE(); staS.push(0); sybS.push("$"); init(); }  // input:lexeme, analyse:AG 

    node corag(int curs, int input) {
        vector<node> buffer = AG[curs];
        for (auto it: buffer)
            if (it.input == input) return it;
        return node();
    }

    string trans(string& s) {
        int i = stoi(s);
        if (Quatersion[i-1].s1 == "j") s = trans(Quatersion[i-1].s4);
        return s;
    }

    void sol() {
        
        for (int i = 0; i < numQ; ++i) {
            if (four[i] != -1) Quatersion[i].plus(four[i]+1);
        }
        for (int i = 0; i < numQ; ++i) {
            if (Quatersion[i].s1[0] == 'j') trans(Quatersion[i].s4);
        }
        cout << "(0) (" << Quatersion[numQ-1].s1 << " , " << Quatersion[numQ-1].s2 << " , " 
                        << Quatersion[numQ-1].s3 << " , " << Quatersion[numQ-1].s4 << ")\n";  
        for (int i = 0; i < numQ-1; ++i) {
            cout << "(" << i+1 << ") (" << Quatersion[i].s1 << " , " << Quatersion[i].s2 << " , " 
                 << Quatersion[i].s3 << " , " << Quatersion[i].s4 << ")\n";  
        }
        cout << "(" << numQ << ") (sys , - , - , -)\n";
    }

    bool isnum(string s)
    {
        string::iterator it;
        for (it = s.begin(); it < s.end(); ++it)
        {
            if (*it<'0' || *it>'9')
                return false;
        }
        return true;
    }

    void checkI(string s) {
        if(!identify.count(s) && !isnum(s)) cout << "Error: Variable "<< s << " undefined\n";
    }

    void Semantic(int rid, vector<string> vs) {
        reverse(vs.begin(), vs.end());
        if (rid == 1) Quatersion[numQ++] = node2(vs[0], vs[1], "-", "-");
        else if (rid == 5) {
            identify.insert(vs[0]);
        }
        else if (rid == 6) {
            identify.insert(vs[0]);
        }
        else if (rid == 42) {
            checkI(vs[0]);
            Quatersion[numQ++] = node2(":=", vs[2], "-", vs[0]);
        }
        else if (rid == 10) {
            checkI(vs[0]); checkI(vs[2]);
            Quatersion[numQ++] = node2("+", vs[0], vs[2], string("T"+to_string(numT)));
        }// A+B
        else if (rid == 11) {
            checkI(vs[0]); checkI(vs[2]);
            Quatersion[numQ++] = node2("-", vs[0], vs[2], string("T"+to_string(numT)));
        }// A-B
        else if (rid == 13) { 
            checkI(vs[0]); checkI(vs[2]);
            Quatersion[numQ++] = node2("*", vs[0], vs[2], string("T"+to_string(numT)));
        }// A*B
        else if (rid == 14) {
            checkI(vs[0]); checkI(vs[2]);
            Quatersion[numQ++] = node2("/", vs[0], vs[2], string("T"+to_string(numT)));
        }// A/B
        else if (rid == 28 || rid == 29) {
            checkI(vs[0]); checkI(vs[2]);
            Quatersion[numQ++] = node2(string("j"+vs[1]), vs[0], vs[2], "0");
            Quatersion[numQ++] = node2("j", "-", "-", "0");
        }// A <> < > = >= <=
        else if (rid == 22) {
            backpatchT(numQ - 4, numQ - 2); 
            headT.push(numQ - 2);
            mergeF(numQ - 3, numQ - 1);
        } // and
        else if (rid == 20) {
            backpatchF(numQ - 3, numQ - 1);
            headF.push(numQ - 1);
            mergeT(numQ - 4, numQ - 21);
        } // or
        else if (rid == 43) {
            if (headT.empty() || numQ - 2 != headT.top()) headT.push(numQ - 2);
            if (headF.empty() || numQ - 1 != headF.top()) headF.push(numQ - 1);
            backpatchT(headT.top(), numQ);
        } // if A then, fill the true
        else if (rid == 44) {
            backpatchF(headF.top(), numQ+1);
            Quatersion[numQ++] = node2("j", "-", "-", "0");
            ifthen.push(numQ - 1);
        } // if A then B else, fill the false
        else if (rid == 47) whileN.push(numQ+1); // identify while and record the beginning
        else if (rid == 48) {
            if (headT.empty() || numQ - 2 != headT.top()) headT.push(numQ - 2);
            if (headF.empty() || numQ - 1 != headF.top()) headF.push(numQ - 1);
            backpatchT(headT.top(), numQ);
        } //  while A do, fill the true
        else if (rid == 46) {
            four[ifthen.top()] = numQ;
        }// if A then B else C
        else if (rid == 49) {
            Quatersion[numQ++] = node2("j", "-", "-", to_string(whileN.top())); whileN.pop();
            backpatchF(headF.top(), numQ);
        }// while A do B, fill the false
        else if (rid == 50) {
            repeatN.push(numQ);
        }// repeat
        else if (rid == 51) {
            four[numQ - 1] = repeatN.top(); repeatN.pop();
            four[numQ - 2] = numQ;
        }
        else if (rid == 17) {
            checkI(vs[1]);
            Quatersion[numQ++] = node2("@", vs[1], "-", string("T"+to_string(numT))); 
        }// A = -A
    }
    
    void reduce(node buffer, string lv) {
        vector<string> vs;
        // if (buffer.type_ == 'a') { cout << "accept\n"; return; }
        if (buffer.type_ == 'a') return;
        else if (buffer.type_ == 'g') { sybS.push(lv); staS.push(buffer.nextS); return; }
        else if (buffer.type_ == 'e') { cout << "Error: Syntax error"; exit(0); }
        else if (buffer.type_ == 's') { staS.push(buffer.nextS); sybS.push(lv); return; }
        string s = ag.dfa.items.EXPRESSIONS[buffer.nextS]; int len = s.length()-3;
        while (len--) { if (staS.empty()) { cout << "Error: Syntax error"; exit(0); } vs.push_back(sybS.top()); sybS.pop(); staS.pop(); }
        Semantic(buffer.nextS, vs);
        node buffer2 = corag(staS.top(), S2I[s[0]]);
        if (buffer.nextS == 10 || buffer.nextS == 11 || buffer.nextS == 13 || buffer.nextS == 14 || buffer.nextS == 17) { identify.insert("T"+to_string(numT)); reduce(buffer2, string("T"+to_string(numT++))); }// +-*/ ->Tx
        else if (buffer.nextS == 19 || buffer.nextS == 27) reduce(buffer2, vs[1]);
        else reduce(buffer2, vs[0]);
        buffer = corag(staS.top(), buffer.input);
        reduce(buffer, lv);
    }

    void parsing() {
        for (int i = 0; i < lexeme.size(); ++i) {
            int curs = staS.top();
            int input = lexeme[i].kind; 
            node buffer = corag(curs, input);
            reduce(buffer, lexeme[i].value);
        }
    }
};

int main() {
    string path;
    cout << "吴斌权 19计创 201930343483\n温馨提示：因为所使用的是LR(1)文法分析器，故程序要经过6~10s后才处理完任务\n输入TEST4或TEST5\n";
    cin >> path;
    path = path + ".txt";
    freopen(path.c_str(), "r", stdin);
    Stack s;
    s.parsing();
    s.sol();
}