// #include<iostream>
// using namespace std;

// class par
// {
// public:
// 	virtual void printa() { cout << 'a' << endl; }
// };

// class chi: public par
// {
// public:
// 	virtual void printa() { cout << 'c' << endl; }
// 	void printb() { cout << 'b' << endl; }
// };

// int main() {
// 	par a;
// 	a.printa();
// 	chi b;
// 	b.printb();

// 	par* bptr = static_cast<par*>(new chi());
// 	bptr->printa();
// 	return 0;
// }

#include <iostream> 
#include <typeinfo> 
using namespace std;
class X  {
	public:
		X()
		{
			
		}
		void func()
		{
			
		}
}; 
class XX : public X  {
	public:
	XX()
	{
		
	}
	void func()
	{
			
	}
}; 
class Y  {
	public:
	Y()
	{
		
	}
	void func()
	{
			
	}
}; 
 
int main()
{
    int n = 0;
    XX xx;
    Y y;
    Y *py = &y;
 
    // int和XX都是类型名
    cout << typeid(int).name() << endl;
    cout << typeid(XX).name() << endl;
    // n为基本变量
    cout << typeid(n).name() << endl;
    // xx所属的类虽然存在virtual，但是xx为一个具体的对象
    cout << typeid(xx).name() << endl;
    // py为一个指针，属于基本类型
    cout << typeid(py).name() << endl;
    // py指向的Y的对象，但是类Y不存在virtual函数
    cout << typeid(*py).name() << endl;
    return 0;
}

