
#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <pthread.h>


void * customer(void * arg);
void * producer(void * arg);

int shutdown = 0;
int product = 0;

pthread_mutex_t * pMutex;
pthread_cond_t * pCond;

int main(){

	pMutex = (pthread_mutex_t *)calloc(1,sizeof(pthread_mutex_t));
	pthread_mutex_init(pMutex,NULL);

	pCond = (pthread_cond_t *)calloc(1,sizeof(pthread_cond_t));
	pthread_cond_init(pCond,NULL);


	pthread_t * cus = (pthread_t *)calloc(1,sizeof(pthread_t));
	pthread_t * pro = (pthread_t *)calloc(1,sizeof(pthread_t));


	int ret1, ret2;
	ret1 = pthread_create(cus,NULL,customer,NULL);
	ret2 = pthread_create(pro,NULL,producer,NULL);

	printf("MAIN: both TOGA, %d, %d\n", ret1, ret2);

	printf("--------- MAIN: wait work ---------\n");
	sleep(5);
	printf("--------- MAIN: work over---------\n");

	printf("MAIN: set shutdown\n");
	shutdown = 1;
	pthread_cond_broadcast(pCond);
	printf("MAIN: cond broadcast!\n");


	printf("--------- MAIN: wait shutdown ---------\n");
	sleep(3);
	printf("--------- MAIN: shutdown over---------\n");

	printf("MAIN: destroy mutex and cond\n");
	pthread_mutex_destroy(pMutex);
	pthread_cond_destroy(pCond);

	printf("MAIN: free all\n");
	free(pMutex);
	free(pCond);
	free(cus);
	free(pro);

	printf("MAIN: GOOD BYE\n");
	return 0;
}

void * customer(void * arg){

	while(0 == shutdown){

		printf("Customer: will get Mutex\n");
		pthread_mutex_lock(pMutex);
		printf("Customer: got Mutex\n");

		while(0 == product && 0 == shutdown){
			printf("Customer: Wait condition ...\n");
			pthread_cond_wait(pCond,pMutex);
			printf("Customer: Get signal ...\n");
		}

		if(0 != shutdown){
			printf("SHUTDOWN: customer will release Mutex\n");
			pthread_mutex_unlock(pMutex);
			printf("SHUTDOWN: customer released Mutex\n");
			break;
		}

		printf("Customer: We eat %d !\n", product);
		product = 0;

		printf("Customer: will release Mutex\n");
		pthread_mutex_unlock(pMutex);
		printf("Customer: released Mutex\n");
	}

	printf("SHUTDOWN: customer is on its way ...\n");
	pthread_exit(NULL);
}

void * producer(void * arg){

	while(0 == shutdown){

		printf("Producer: will get Mutex\n");
		pthread_mutex_lock(pMutex);
		printf("Producer: got Mutex\n");

		product = 1080;

		printf("Producer: will release Mutex\n");
		pthread_mutex_unlock(pMutex);
		printf("Producer: released Mutex\n");

		printf("Producer: will send signal\n");
		pthread_cond_signal(pCond);
		printf("Producer: sent signal\n");


		printf("Producer: sleep ...\n");
		sleep(1);
	}

	printf("SHUTDOWN: producer is on its way ...\n");
	pthread_exit(NULL);
}
