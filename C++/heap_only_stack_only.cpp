#include<iostream>
using namespace std;

class heaponly
{
protected:
	heaponly() {};
	~heaponly() {};
public:
	static heaponly* create() { return new heaponly(); };
	void destroy() { delete this; };
};

class stackonly
{
private:
	void* operator new(size_t t) {};
	void operator delete(void* ptr) {};
	
};

int main() {
	heaponly* test = heaponly::create();
	test->destroy();
	// stackonly* test2 = new stackonly();
	// delete test2;
	stackonly test2();
	return 0;
}