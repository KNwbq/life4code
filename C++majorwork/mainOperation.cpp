#include "aClass.cpp"
#include "RAL.cpp"
using namespace std;

bool defineDate (int year, int month, int day)
{
    if ((year % 100 == 0 && year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
    {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (day <= 31) return true;
            else return false;
        }
        if (month == 2) {
            if (day <= 29) return true;
            else return false;
        }
        else {
            if (day <= 30) return true;
            else return false;
        }
    }
    else 
    {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (day <= 31) return true;
            else return false;
        }
        if (month == 2) {
            if (day <= 28) return true;
            else return false;
        }
        else {
            if (day <= 30) return true;
            else return false;
        }
    }
}
bool cmp1 (finance* A, finance* B) 
{ 
    if ((double)*A == (double)*B)
    {
        if (A -> gety() != B -> gety()) return A -> gety() < B -> gety();
        else if (A -> getm() != B -> getm()) return A -> getm() < B -> getm();
        else return A -> getd() < B -> getd();
    }
    else return (double)*A < (double)*B; 
}
bool cmp2 (finance* A, finance* B) 
{ 
    if ((double)*A == (double)*B)
    {
        if (A -> gety() != B -> gety()) return A -> gety() < B -> gety();
        else if (A -> getm() != B -> getm()) return A -> getm() < B -> getm();
        else return A -> getd() < B -> getd();
    }
    else return (double)*A > (double)*B; 
}

class fileOperation
{
public:
    void message_1 () { cout << "1:Input information  2:Query information  3:Clear record  4:Exit   PLEASE ENTER: "; }
    void message_2 () { cout << "1:Wechat pay  2:One-card-pass   PLEASE ENTER: "; }
    void message_3 () { cout << "How do you query? 1:Year 2:Month 3:Day   PLEASE ENTER: "; }
    void message_4 (int m) { if (m == 1) { cout << "Please enter the year: "; } else if (m == 2) { cout << "Please enter the year and the month: "; } else cout << "Please enter the date: "; }
    bool message_5 (int year, int month, int day) { if (!defineDate(year, month, day)) { cout << "Invalid date entered.\n"; return false; } else return true;}
    void message_6 () { cout << "How to sort? 1:By date  2:From less to more  3:From more to less   PLEASE ENTER: "; }
    int IAQ (int a, int b) 
    {
        if (a == 1 && b == 1)
        {
            int yOn;
            do {
                int flag;
                wechatPay wp;

                ofstream writee (fileName, ios::app);

                wp.message3(); cin >> flag;
                if (flag == 1) {
                    int ldoann; bool h = false; bool validDate;
                    wp.message1(); wp.input(flag);
                    validDate = message_5(wp.gety(), wp.getm(), wp.getd());
                    if (!validDate) { writee.close(); goto loop4; }
                    ofstream cardWrite (fileName2, ios::app); ifstream cW (fileName2, ios::in);
                    while (cW >> ldoann) { if (ldoann == wp.getl()) { h = true; break; } }
                    if (!h) cardWrite << wp.getl() << ' ';
                    cardWrite.close(); cW.close();
                }
                else {
                    bool validDate;
                    wp.message2(); wp.input(flag);
                    validDate = message_5(wp.gety(), wp.getm(), wp.getd()); 
                    if (!validDate) { writee.close(); goto loop4; }
                }
                writee << wp; writee.close();
            loop4:
                cout << "Continue? 1:Y 2:N   PLEASE ENTER: "; cin >> yOn; if (yOn == 2) return 2;
            } while (yOn == 1);
        }
        else if (a == 1 && b == 2)
        {
            int yOn;
            do{
                int flag;
                oneCard oc;

                ofstream writee(fileName, ios::app);

                oc.message2(); cin >> flag; oc.message1(); oc.input(flag);
                bool validDate;
                validDate = message_5(oc.gety(), oc.getm(), oc.getd()); 
                if (!validDate) { writee.close(); goto loop5; }
                writee << oc;
            loop5:
                cout << "Continue? 1:Y 2:N   PLEASE ENTER: "; cin >>yOn; writee.close();  if (yOn == 2) return 2;
            } while (yOn == 1);
        }
        else if (a == 2 && b == 1)
        {
            int flag;
            do {
                int way, queryWay, tot = 0, ctot = 0, card[maxn], yy, mm, dd;
                double mtot = 0, mtot2 = 0, mttot = 0, mttot2 = 0, mttot3 = 0;
                wechatPay* wc[200];
                wc[0] = new wechatPay;
                ifstream readd (fileName, ios::in);
                ifstream cardRead (fileName2, ios::in);
                message_3(); cin >> way; message_4(way); 
                if (way == 1)
                {
                    cin >> yy;
                    while (readd >> *wc[tot++]) { wc[tot] = new wechatPay; if (wc[tot - 1] -> gety() != yy) --tot; }
                }
                else if (way == 2)
                {
                    cin >> yy >> mm;
                    while (readd >> *wc[tot++]) { wc[tot] = new wechatPay; if (wc[tot - 1] -> gety() != yy || wc[tot - 1] -> getm() != mm) --tot; }
                }
                else
                {
                    cin >> yy >> mm >> dd;
                    bool validDate;
                    validDate = message_5(yy, mm, dd); 
                    if (!validDate) { readd.close(); goto loop6; }
                    while (readd >> *wc[tot++]) { wc[tot] = new wechatPay; if (wc[tot - 1] -> gety() != yy || wc[tot - 1] -> getm() != mm || wc[tot - 1] -> getd() != dd) --tot; }
                }
                --tot;
                readd.close();

                message_6(); cin >> queryWay;

                if (queryWay == 2) sort(wc, wc + tot, cmp1);
                else if (queryWay == 3) sort(wc, wc + tot, cmp2);

                while (cardRead >> card[ctot++]) {;}
                --ctot;

                cout << "\nChange\n\n";
                cout << "Expenditure:\n";
                for (int i = 0; i < tot; ++i) { if ((double)*wc[i] < 0 && wc[i] -> getl() == -1000) { wc[i] -> output(); mtot += (double)*wc[i]; } }
                cout << "Total expenditure: " << mtot << '\n'; mttot += mtot; mtot = 0;
                cout << "Income:\n";
                for (int i = 0; i < tot; ++i) { if ((double)*wc[i] > 0 && wc[i] -> getl() == -1000) { wc[i] -> output(); mtot += (double)*wc[i]; } } 
                cout << "Total income: " << mtot << "\n\n"; mttot += mtot; mtot = 0;

                cout << "Credit Card\n\n";
                for (int i = 0; i < ctot; ++i)
                {
                    cout << "*Card Number*: " << card[i] << "\n";
                    cout << "Expenditure:\n";
                    for (int j = 0; j < tot; ++j) { if ((double)*wc[j] < 0 && wc[j] -> getl() == card[i]) { wc[j] -> output(); mtot += (double)*wc[j]; } }
                    cout << "Total expenditure: " << mtot << '\n'; mttot2 += mtot;
                    cout << "Income:\n";
                    for (int j = 0; j < tot; ++j) { if ((double)*wc[j] > 0 && wc[j] -> getl() == card[i]) { wc[j] -> output(); mtot2 += (double)*wc[j]; } }
                    cout << "Total income: " << mtot2 << "\n"; mttot3 += mtot2;
                    cout << "Total income and expenditure of " << card[i] << ": " << mtot + mtot2 << "\n\n"; mtot = 0; mtot2 = 0;
                }

                cout << "Total expenditure of all cards: " << mttot2 << '\n'
                    << "Total income of all cards: " << mttot3 << "\n\n"
                    << "Total income and expenditure of change: " << mttot << '\n'
                    << "Total income and expenditure of all cards: " << mttot2 + mttot3 << '\n'
                    << "Total income and expenditure of wechat: " <<  mttot + mttot2 + mttot3 << "\n\n";
            loop6:
                cardRead.close(); cout << "Continue? 1:Y 2:N   PLEASE ENTER: "; cin >> flag; if (flag == 2) return 2;
            } while (flag == 1);
        }
        else if (a == 2 && b == 2)
        {
            int flag;
            do {
                int way, queryWay, tot = 0, yy, mm, dd;
                double mtot = 0, mtot2 = 0, mttot = 0, mttot2 = 0, mttot3 = 0;
                oneCard* oc[200];
                oc[0] = new oneCard;
                ifstream readd (fileName, ios::in);
                message_3(); cin >> way; message_4(way); 
                if (way == 1)
                {
                    cin >> yy;
                    while (readd >> *oc[tot++]) { oc[tot] = new oneCard; if (oc[tot - 1] -> gety() != yy) --tot; }
                }
                else if (way == 2)
                {
                    cin >> yy >> mm;
                    while (readd >> *oc[tot++]) { oc[tot] = new oneCard; if (oc[tot - 1] -> gety() != yy || oc[tot - 1] -> getm() != mm) --tot; }
                }
                else
                {
                    cin >> yy >> mm >> dd;
                    bool validDate;
                    validDate = message_5(yy, mm, dd); 
                    if (!validDate) { readd.close(); goto loop7; }
                    while (readd >> *oc[tot++]) { oc[tot] = new oneCard; if (oc[tot - 1] -> gety() != yy || oc[tot - 1] -> getm() != mm || oc[tot - 1] -> getd() != dd) --tot; }
                }
                --tot;

                readd.close();

                message_6(); cin >> queryWay;

                if (queryWay == 2) sort(oc, oc + tot, cmp1);
                else if (queryWay == 3) sort(oc, oc + tot, cmp2);

                cout << "\nBlue Card:\n\n";
                cout << "Expenditure:\n";
                for (int i = 0; i < tot; ++i) {
                    if ((double)*oc[i] < 0 && oc[i] -> getb() == 'B') { oc[i] -> output(); mtot += (double)*oc[i]; }
                }
                cout << "Total expenditure: " << mtot << "\n"; mttot += mtot; mtot = 0;
                cout << "Income:\n";
                for (int i = 0; i < tot; ++i) {
                    if ((double)*oc[i] > 0 && oc[i] -> getb() == 'B') { oc[i] -> output(); mtot += (double)*oc[i]; }
                }
                cout << "Total income: " << mtot << '\n'; mttot += mtot;
                cout << "Total income and expenditure of blue card: " << mttot << '\n'; mtot = 0; mttot = 0;

                cout << "\nGreen Card:\n\n";
                cout << "Expenditure:\n";
                for (int i = 0; i < tot; ++i) {
                    if ((double)*oc[i] < 0 && oc[i] -> getb() == 'G') { oc[i] -> output(); mtot += (double)*oc[i]; }
                }
                cout << "Total expenditure: " << mtot << "\n"; mttot += mtot; mtot = 0;
                cout << "Income:\n";
                for (int i = 0; i < tot; ++i) {
                    if ((double)*oc[i] > 0 && oc[i] -> getb() == 'G') { oc[i] -> output(); mtot += (double)*oc[i]; }
                }
                cout << "Total income: " << mtot << "\n"; mttot += mtot;
                cout << "Total income and expenditure of Green card: " << mttot << "\n\n";
            loop7:
                cout << "Continue? 1:Y 2:N   PLEASE ENTER: "; cin >> flag; if (flag == 2) return 2;
            } while (flag == 1);
        }
        return 0;
    }
    void clear ()
    {
        ofstream writee (fileName, ios::out); ofstream writeee (fileName2, ios::out);
        cout << "Empty record!\n\n";
        writee.close(); writeee.close();
    }
};