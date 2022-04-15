#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex, wmutex;

void* writer(void*) {
	while (1) {
		sem_wait(wmutex);
	}

}
void* reader(void*) {
	while (1) {
		sem_wait(mutex);

	}
}

int main() {
	pthread_t writers[10], readers[10];

	for (int i = 0; i < 10; ++i) {
		ptherad_create(&readers[i], NULL, reader, &i);
		sleep(2);
	}

	for (int i = 0; i < 10; ++i) {
		ptherad_create(&writers[i], NULL, writer, &i);
		sleep(2);
	}

	for (int i = 0; i < 10; ++i) {
		pthread_join(&readers[i], NULL);
		sleep(2);
	}

	for (int i = 0; i < 10; ++i) {
		ptherad_join(&writers[i], NULL);
		sleep(2);
	}
}
