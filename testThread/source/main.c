
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

void * beijing(void * args){

	int count = 0;

	while(1){
		printf("Beijing count: %d\n", count);
		count++;
		sleep(1);
	}

}


int main(){

	pthread_t * a = malloc(sizeof(pthread_t));

	pthread_create(a, NULL, beijing, NULL);

	sleep(10);


	printf("main over !");
	return 0;

}
