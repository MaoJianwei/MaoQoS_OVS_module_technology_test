
#include <stdio.h>

int log();

static int maoCount = 0;
int main(){

//	FILE * log;
//
//	log = fopen("/home/mao/maoOVSlog/1.txt","a+");
//	if(NULL == log){
//		printf("Mao: open fail!");
//		return 1;
//	}
//
//	fprintf(log, " %d device is going on!\n", ++maoCount);
//	printf("%d device is going on!", maoCount);
//
//	fclose(log);
	
	log();

}

int log(){

	FILE * log;

	log = fopen("/home/mao/maoOVSlog/1.txt","a+");
	if(NULL == log){
		printf("Mao: open fail!");
		return 1;
	}

	//fprintf(log, " %d device is going on!\n", ++maoCount);
	fputs("beijing radar",log);
	printf("%d device is going on!", maoCount);

	fclose(log);

	return 0;
}
