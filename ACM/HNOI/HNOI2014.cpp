#include<iostream>
using namespace std;

int main()
{
    int* a;
    char* b;
    int arry[3] = {64, 0, 0};
    a = arry; b = (char*)a + 3;
    cout << *b;
    system("pause");
}