
#include <string.h>

void main(){

	char * target = "tcp:103.103.189.154:6653";
	char * head = strchr(target,':');
	char * tail = strrchr(target,':');

	int count = tail - head;

	char * controllerIP = (char*) calloc(1,16);
	memcpy(controllerIP, head+1, tail-head-1);

	return;

}
