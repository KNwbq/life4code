#include "head.cpp"
using namespace std;

class finance
{
public:
    finance () {};
    finance (int yy, int mm, int dd, double mny, char* rea) : year(yy), month(mm), day(dd) { strcpy(reason, rea); cout << "Data entry succeeded"; }
    int gety () { return year; }
    int getm () { return month; }
    int getd () { return day; }
    virtual operator double () = 0;
protected:
    int year, month, day; double money; char reason[200];
};

class wechatPay : public finance
{
public:
    void message1 () { cout << "PLEASE ENTER\nLast four digits of bank card---time---amount of money---reason \n"; }
    void message2 () { cout << "PLEASE ENTER\ntime---amount of money---reason \n"; }
    void message3 () { cout << "1:Credit Card  2:Change   PLEASE ENTER: "; }
    wechatPay () {}
    wechatPay (wechatPay& A) { year = A.year; month = A.month; day = A.day; money = A.money; ldoan = A.ldoan; strcpy(reason, A.reason); }
    friend double operator + (wechatPay& A, wechatPay& B) { return A.money + B.money; }
    friend ofstream& operator << (ofstream& writee, wechatPay& A)
    {
        writee << A.ldoan << ' ' << A.year << ' ' << A.month << ' ' << A.day << ' ' << A.money << ' ' << A.reason << '\n';
        return writee;
    }
    friend ifstream& operator >> (ifstream& readd, wechatPay& A)
    {
        readd >> A.ldoan >> A.year >> A.month >> A.day >> A.money >> A.reason ;
        return readd;
    }
    void output () { cout << "YEAR: " << setw(6) << left << year 
                          << "MONTH: " << setw(6) << left << month 
                          << "DAY: " << setw(6) << left << day 
                          << "AMOUNT: "<< setw(6) << left << money 
                          << "REASON: "<< setw(6) << left << reason << '\n'; 
                   }
    void input (int a)
    {
        if (a == 2) { cin >> year >> month >> day >> money >> reason; ldoan = -1000; }
        else { cin >> ldoan >> year >> month >> day >> money >> reason; }
    }
    int getl () { return ldoan; }
    operator double () { double m = money; return m; }
private:
    int ldoan;
};

class oneCard : public finance
{
public:
    void message1 () { cout << "PLEASE ENTER\ntime---amount of money---reason \n"; }
    void message2 () { cout << "1:Blue card  2:Green card   PLEASE ENTER: "; }
    oneCard () {};
    oneCard (oneCard& A) { year = A.year; month = A.month; day = A.day; money = A.money; bog = A.bog; strcpy(reason, A.reason); }
    int getb() { return bog; }
    void output () { cout << "YEAR: " << setw(6) << left << year 
                          << "MONTH: " << setw(6) << left << month 
                          << "DAY: " << setw(6) << left << day 
                          << "AMOUNT: "<< setw(6) << left << money 
                          << "REASON: "<< setw(6) << left << reason << '\n'; 
                   }
    void input (int a)
    {
        if (a == 1) { cin >> year >> month >> day >> money >> reason; bog = 'B'; }
        else { cin >> year >> month >> day >> money >> reason; bog = 'G'; }
    }
    friend ofstream& operator << (ofstream& writee, oneCard& A)
    {
        writee << A.bog << ' ' << A.year << ' ' << A.month << ' ' << A.day << ' ' << A.money << ' ' << A.reason << '\n';
        return writee;
    }
    friend ifstream& operator >> (ifstream& readd, oneCard& A)
    {
        readd >> A.bog >> A.year >> A.month >> A.day >> A.money >> A.reason;
        return readd;
    }
    operator double () { double m = money; return m; }
private:
    int bog;
};