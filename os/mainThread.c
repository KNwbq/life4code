#include<pthread.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int* thread(void* arg) {
	pthread_t newthid = pthread_self();
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	printf("child thread: %lu time: %d/%d/%d %d:%d:%d\n", newthid, lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
	return NULL;
}

int main() {
	pthread_t thid = pthread_self();
	time_t t;
	struct tm* lt;
	time(&t);
	lt = localtime(&t);
	printf("main thread: %lu time: %d/%d/%d %d:%d:%d\n", thid, lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
	if (pthread_create(&thid, NULL, (void*)thread, NULL)!=0) {
		printf("thread creation failed\n");
		exit(1);
	}
	sleep(1);
	exit(0);
}