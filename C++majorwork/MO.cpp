#include "mainOperation.cpp"
using namespace std;
int choice;

int main()
{
    cout << "Welcome to personal finance\n";
    do {
    loop0:
        int s;
        strcpy(fileName, "D:\\User\\"); strcpy(fileName2, "D:\\UserCard\\");
        cout << right << "0: Login  1: Regist  2:Delete  3:Change Password  4:Exit   PLEASE ENTER: ";
        cin >> choice;
        if (choice == 4) exit(0);
        s = registAndlogin (choice);
        if (s == 2) { goto loop0; }
        fileOperation start;

        if (startOk)
        {
        loop1:
            int choice_1, choice_2, flag;
            start.message_1(); cin >> choice_1;
            if (choice_1 == 3) { start.clear(); goto loop0; }
            if (choice_1 == 4) exit(0);
            start.message_2(); cin >> choice_2;
            flag = start.IAQ(choice_1, choice_2);
            if (flag == 2) { goto loop1; }
        }
    } while (!startOk);

    system("pause");
    return 0;
}