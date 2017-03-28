
#include <malloc.h>
#include <sys/queue.h>

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

int main(){

	struct cmdQueueHead * cmdQueue = (struct cmdQueueHead *)calloc(1,sizeof(struct cmdQueueHead));
	TAILQ_INIT(cmdQueue);

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

	free(cmdQueue);
	cmdQueue = NULL;

	int bbb = 2;

	return 0;
}
