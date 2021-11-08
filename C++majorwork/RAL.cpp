#include "head.cpp"
using namespace std;
const int maxn = 15; bool startOk = false;
char currentUser[maxn], fileName[maxn + 20] = { "D:\\User\\" }, fileName2[maxn + 50] = { "D:\\UserCard\\" };

int registAndlogin (int m)
{
    if (m == 0) {
        ifstream readd("D:\\registandlogin.txt", ios::in); bool teg = false; int cnt = 0;
        char account[maxn], password[maxn], aa[maxn], pp[maxn];
        cout << "Please enter your account: "; cin >> account;
        cout << "Please enter your password: ";
        int index=0;
        while (1)
        {
            char ch;
            ch = getch();
            if(ch == 8)
            {
                if (index != 0)
                {
                    cout << char(8) << ' ' << char(8);
                    --index;
                }
            }
            else if(ch == '\r')
            {
                password[index] = '\0';
                cout << endl;
                break;
            }
            else
            {
                cout << '*';
                password[index++] = ch;
            }
        }
        while (readd >> aa >> pp) {
            bool flag1 = false, flag2 = false;
            if (strlen(account) != strlen(aa)) continue;
            for (int i = 0; i < strlen(account); ++i) { if (account[i] != aa[i]) flag1 = true; } if (flag1) continue; else teg = true;
            if (strlen(password) != strlen(pp)) { cout << "Incorrect password\n"; flag2 = true; break; }
            for (int i = 0; i < strlen(password); ++i) { if (password[i] != pp[i]) { cout << "Incorrect password\n"; flag2 = true; break; } }
            if (flag2) break;
            cout << "Login succeeded\n"; strcpy(currentUser, account);  startOk = true;
            strcat(fileName, currentUser); strcat(fileName, ".txt"); 
            strcat(fileName2, currentUser); strcat(fileName2, ".txt"); break;
        }
        if (!teg) cout << "Account does not exist.\n";
        readd.close();
    }
    if (m == 1) {
        int flag;
        do {
            bool securityLevel[3] = {0}; int cnt = 0; bool teg = false;
            ofstream writee("D:\\registandlogin.txt", ios::app);
            ifstream readd("D:\\registandlogin.txt", ios::in);
            char account[maxn], password[maxn], aa[maxn], c[maxn + 10];
            cout << "Please enter your account: "; cin >> account;

            while (readd >> aa) {
                bool flag = true;
                readd.getline(c, maxn + 10);
                for (int i = 0; i < strlen(account); ++i) { if (account[i] != aa[i]) { flag = false; } }
                if (flag && strlen(account) != strlen(aa)) { flag = false; }
                if (flag) { cout << "Account already exists\n"; teg = true; break; }
            }
            if (teg) goto loop;
        
            cout << "Please enter your password: "; cin >> password;
            for (int i = 0; i < strlen(password); ++i) { 
                if (password[i] >= '0' && password[i] <= '9') securityLevel[0] = 1;
                else if (password[i] >= 'a' && password[i] <= 'z' || password[i] >= 'A' && password[i] <= 'Z') securityLevel[1] = 1;
                else securityLevel[2] = 1;
            }
            if (strlen(password) <= 5) cout << "Weak password\n";
            else {
                for (int i = 0; i < 3; ++i) { if(securityLevel[i]) ++cnt; }
                if (cnt == 2) cout << "Medium security password\n";
                else if (cnt == 3) cout << "More secure password\n";
            } 
            writee << account << ' ' << password << '\n';
            loop:
                writee.close(); readd.close();
                cout << "Continue? 1:Y 2:N   PLEASE ENTER: "; cin >> flag; if (flag == 2) return 2;
        } while (flag == 1);
    }
    if (m == 2) {
        int flag;
        do {
            ifstream readd("D:\\registandlogin.txt", ios::in);
            char account[maxn], password[maxn], aa[maxn], pp[maxn];
            cout << "Please enter your account: "; cin >> account;
            cout << "Please enter your password: "; cin >> password;
            while (readd >> aa >> pp)
            {
                bool haccount = true, cpassword = true;
                if (strlen(aa) == strlen(account)) {
                    for (int i = 0; i < strlen(aa); ++i) {
                        if (aa[i] != account[i]) haccount = false;
                    }
                    if (haccount) {
                        if (strlen(pp) == strlen(password)) {
                            for (int i = 0; i < strlen(pp); ++i) {
                                if (pp[i] != password[i]) cpassword = false;
                            }
                            if (cpassword) {
                                ofstream writee("D:\\registandlogin(2).txt", ios::out);
                                readd.seekg(0, ios::beg);

                                while (readd >> aa >> pp)
                                {
                                    bool teg = true;
                                    if (strlen(aa) != strlen(account)) {
                                        writee << aa << ' ' << pp << '\n';
                                    }
                                    else {
                                        for (int i = 0; i < strlen(aa); ++i) {
                                        if (aa[i] != account[i]) teg = false;
                                    }
                                        if (!teg) {
                                            writee << aa << ' ' << pp << '\n';
                                        }
                                    }
                                }
                                writee.close(); readd.close();
                                ofstream writeee("D:\\registandlogin.txt", ios::out);
                                ifstream readdd("D:\\registandlogin(2).txt", ios::in);
                                while (readdd >> aa >> pp) { writeee << aa << ' ' << pp << '\n'; }
                                writeee.close(); readdd.close();
                                cout << "Operation successful.\n";
                                goto loop2;
                            }
                            else continue;
                        }
                        else continue;
                    }
                    else continue;
                }
                else continue;
            }
            cout << "operation failed (Account does not exist or account password does not match)";
            readd.close();
            loop2:
                cout << "Continue? 1:Y  2:N   PLEASE ENTER: "; cin >> flag;  if (flag == 2) return 2;
        } while (flag == 1);
    }
    if (m == 3) {
        int flag;
        do {
            ifstream readd("D:\\registandlogin.txt", ios::in);
            char account[maxn], password[maxn], aa[maxn], pp[maxn], newpassword[maxn];
            int cnt = 0;
            bool securityLevel[3] = {0};
            cout << "Please enter your account: "; cin >> account;
            cout << "Please enter your password: "; cin >> password;
            while (readd >> aa >> pp)
            {
                bool haccount = true, cpassword = true;
                if (strlen(aa) == strlen(account)) {
                    for (int i = 0; i < strlen(aa); ++i) {
                        if (aa[i] != account[i]) haccount = false;
                    }
                    if (haccount) {

                        if (strlen(pp) == strlen(password)) {
                            for (int i = 0; i < strlen(pp); ++i) {
                                if (pp[i] != password[i]) cpassword = false;
                            }
                            if (cpassword) {
                                ofstream writee("D:\\registandlogin(2).txt", ios::out);
                                readd.seekg(0, ios::beg);
                                cout << "Please enter the new password. new password: "; cin >> newpassword;

                                for (int i = 0; i < strlen(newpassword); ++i) { 
                                if (newpassword[i] >= '0' && newpassword[i] <= '9') securityLevel[0] = 1;
                                else if (newpassword[i] >= 'a' && newpassword[i] <= 'z' || newpassword[i] >= 'A' && newpassword[i] <= 'Z') securityLevel[1] = 1;
                                else securityLevel[2] = 1;
                                }
                                if (strlen(newpassword) <= 5) cout << "Weak password\n";
                                else {
                                for (int i = 0; i < 3; ++i) { if(securityLevel[i]) ++cnt; }
                                if (cnt == 2) cout << "Medium security password\n";
                                else if (cnt == 3) cout << "More secure password\n";
                                } 

                                while (readd >> aa >> pp)
                                {
                                    bool teg = true;
                                    if (strlen(aa) != strlen(account)) {
                                        writee << aa << ' ' << pp << '\n';
                                    }
                                    else {
                                        for (int i = 0; i < strlen(aa); ++i) {
                                        if (aa[i] != account[i]) teg = false;
                                    }
                                        if (!teg) {
                                            writee << aa << ' ' << pp << '\n';
                                        }
                                        else if (teg) {
                                            writee << aa << ' ' << newpassword << '\n';
                                        }
                                    }
                                }
                                writee.close(); readd.close();
                                ofstream writeee("D:\\registandlogin.txt", ios::out);
                                ifstream readdd("D:\\registandlogin(2).txt", ios::in);
                                while (readdd >> aa >> pp) { writeee << aa << ' ' << pp << '\n'; }
                                writeee.close(); readdd.close();
                                cout << "Operation successful.\n";
                                goto loop3;
                            }
                            else continue;
                        }
                        else continue;
                    }
                    else continue;
                }
                else continue;
            }
            cout << "operation failed (Account does not exist or account password does not match)";
            readd.close();
            loop3:
                cout << "Continue? 1:Y  2:N   PLEASE ENTER: "; cin >> flag;  if (flag == 2) return 2;
        } while (flag == 1);
    }
    return 0;
}