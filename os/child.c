#include<stdio.h>
#include<time.h>
#include<unistd.h>

int main() {
	for (int i = 0; i < 5; ++i) {
		time_t t;
		struct tm* lt;
		time(&t);
		lt = localtime(&t);
		printf("The child is talking at %d/%d/%d %d:%d:%d\n", lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
		sleep(1);
	}
}