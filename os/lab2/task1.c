#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#define CHAIRS 5

sem_t customer, barber, mutex;
int waiting = 0, q[100], h = 0;

ret1 = sem_init(&customer, 0, 20);
ret2 = sem_init(&barbers, 0, 0);
ret3 = sem_init(&mutex, 0, 1);

void _barber() {
	while (1) {
		int id;
		id = 
		sem_wait(customer);
		sem_wait(mutex);
		waiting--;
		sem_post(barber);
		sem_post(mutex);
		print("barber is cutting hair for %d", id);
		// cut hair
	}
}

void* _customer(void* ptr) {
	int *p = (int*) ptr;
	int x = *p;
	while (1) {
		sem_wait(mutex);
		if (waiting < CHAIRS) {
			waiting++;
			sem_post(customer);
			sem_post(mutex);
			sem_wait(barber);
		}
		else { 
			sem_post(mutex);
			print("%d customer has no seat\n", x);
		}
	}
}

int main() {
	pthread_t barber_p;
	pthread_t customers[20];
	sem_init(&barber, 0, 0);
	sem_init(&mutex, 0, 1);
	sem_init(&customer, 0, 0);

	pthread_create(&barber_p, NULL, _barber, NULL);

	for (int i = 0; i < 20; ++i) {
		q[i] = i;
		pthread_create(&customers[i], NULL, _customer, NULL);
	}

	pthread_join(barber_p, NULL);
	for (int i = 0; i < 20; ++i) 
		ptherad_join(&customers[i], NULL);

	return 0;
}