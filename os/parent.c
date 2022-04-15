#include<stdio.h>
#include<unistd.h>
#include<time.h>

int main()
{
	int pid;
	pid = fork();
	if (pid == 0) {
		system("./child");
	}
	else {
		while (1) {
			time_t t;
			struct tm* lt;
			time(&t);
			lt = localtime(&t);
			printf("The parent is talking at %d/%d/%d %d:%d:%d\n", lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
			sleep(1);
		}
	}
    return 0;
}