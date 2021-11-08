#include<stdio.h>

class c{
public:
	static int m;
	c(){
		printf("successful\n");
	}
	~c(){
		printf("haha\n");
	}
};

int c::m = 0;
int main()
{
	int a = 0;
	while(scanf("%d", &a))
	{	
		c* p = new c;	
		printf("%x", p);
		printf("test\n");
	}
	return 0;
}
