#include<iostream>
using namespace std;

class wbq
{
public:
	operator char*() { return NULL; }
};

int main() {
	double a = 3.14;
	wbq *A = new wbq();
	int n = static_cast<int> (a);
	char* m = static_cast<char*> (*A);

	int *iptr = new int(12);
	double *dptr = reinterpret_cast<double*>(iptr);
	cout << *iptr << ' ' << *dptr << endl;

	int *c = new int(10);
	const int *b = const_cast<const int*>(c);
	cout << *c << ' ' << *b << endl;
	*c = 12;
	cout << *c << ' ' << *b << endl;

}