#include<iostream>
using namespace std;

class A
{
public:
	A(int m = 1) :x(m) { cout << ' ' << 'A'; }
	int x;
};

class B :virtual public A
{
public:
	int y;
	B(int x = 1) :A(x), y(x) { cout << ' ' << 'B'; }
};

class C :virtual public A
{
public:
	C(int x = 2) :A(x) { cout << ' ' << 'C'; }
};

class D :public A
{
public:
	D(int x = 1) :A(x) {}
};

class test :public B, public C, public D
{
public:
	test(int x, int y, int z, int p) :B(x), D::A(z), C(y) {}
};

int main()
{
	test t(10, 2, 3, 4);
	cout << &t.D::x << ' ' << &t.B::x << ' ' << &t.C::x << ' ' << t.D::x << ' ' << t.B::x << ' ' << t.C::x << ' ' << t.y;
	return 0;
}
