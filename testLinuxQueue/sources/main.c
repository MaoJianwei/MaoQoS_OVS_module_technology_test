
#include <malloc.h>
#include <sys/queue.h>
#include <string.h>

#ifndef NULL
#define NULL ((void *)0)
#endif

struct cmdQueueEntry{

	char * cmdQos;
	TAILQ_ENTRY(cmdQueueEntry) tailq_entry;
};

struct cmdQueueHead {
	  struct cmdQueueEntry *tqh_first;
	  struct cmdQueueEntry * *tqh_last;
};

/**
 * cmd will be copied away, That release cmd is the invoker's duty
 */
void maoEnQueue(struct cmdQueueHead *cmdQueue, char * cmd){
	struct cmdQueueEntry * data = (struct cmdQueueEntry * )calloc(1, sizeof(struct cmdQueueEntry));
	data->cmdQos = (char*)calloc(1,strlen(cmd)+1); // +1 include \0
	strcpy(data->cmdQos,cmd);
	TAILQ_INSERT_TAIL(cmdQueue, data, tailq_entry);
}

/**
 * That release cmd char* is the invoker's duty; The rest is my duty
 * @Return : char*, will be NULL if Queue is empty
 */
char * maoDeQueue(struct cmdQueueHead *cmdQueue){

	if(TAILQ_EMPTY(cmdQueue)){
		return NULL;
	}

	struct cmdQueueEntry* DATA = TAILQ_FIRST(cmdQueue);

	char * cmd = DATA->cmdQos;

	TAILQ_REMOVE(cmdQueue, DATA, tailq_entry);
	free(DATA);
	DATA = NULL;

	return cmd;
}
void maoInitQueue(struct cmdQueueHead * queue){

	TAILQ_INIT(queue);
}


int main(){

	struct cmdQueueHead * cmdQueue = (struct cmdQueueHead *)calloc(1,sizeof(struct cmdQueueHead));
	maoInitQueue(cmdQueue);

	char * beijing = "beijing";
	char * qingdao = "qingdao";
	char * haikou = "haikou";

	maoEnQueue(cmdQueue, beijing);
	maoEnQueue(cmdQueue, qingdao);
	maoEnQueue(cmdQueue, haikou);

	char * temp = NULL;
	temp = maoDeQueue(cmdQueue);
	free(temp);
	temp = maoDeQueue(cmdQueue);
	free(temp);
	temp = maoDeQueue(cmdQueue);
	free(temp);
	temp = maoDeQueue(cmdQueue);
	free(temp);



	/*  below is original
	struct cmdQueueEntry * data;

	data = (struct cmdQueueEntry * )calloc(1, sizeof(struct cmdQueueEntry));
	data->cmdQos = calloc(1,50);
	sprintf(data->cmdQos,"qingdao");
	TAILQ_INSERT_TAIL(cmdQueue, data, tailq_entry);

	data = (struct cmdQueueEntry * )calloc(1, sizeof(struct cmdQueueEntry));
	data->cmdQos = calloc(1,50);
	sprintf(data->cmdQos,"beiing");
	TAILQ_INSERT_TAIL(cmdQueue, data, tailq_entry);

	data = (struct cmdQueueEntry * )calloc(1, sizeof(struct cmdQueueEntry));
	data->cmdQos = calloc(1,50);
	sprintf(data->cmdQos,"haikou");
	TAILQ_INSERT_TAIL(cmdQueue, data, tailq_entry);




	struct cmdQueueEntry* DATA = TAILQ_FIRST(cmdQueue);

	char * a = DATA->cmdQos;

	TAILQ_REMOVE(cmdQueue, DATA, tailq_entry);

	if(TAILQ_EMPTY(cmdQueue)){
		int aaa = 1;
	}

	DATA = TAILQ_FIRST(cmdQueue);
	TAILQ_REMOVE(cmdQueue, DATA, tailq_entry);

	if(TAILQ_EMPTY(cmdQueue)){
		int aaa = 1;
	}

	DATA = TAILQ_FIRST(cmdQueue);
	TAILQ_REMOVE(cmdQueue, DATA, tailq_entry);

	if(TAILQ_EMPTY(cmdQueue)){
		int aaa = 1;
	}
	*/

	free(cmdQueue);
	cmdQueue = NULL;

	int bbb = 2;

	return 0;
}
