
#include <stdio.h>
#include <malloc.h>

void main(){

	char * maoInt = calloc(50,1);
	char maoString[50] = {0};
	char maoFloat[50] = {0};

	float ffff = 6.1080;
	char * radar = "radar";
	int beijing = 1185;

	int temp = sprintf(maoInt,"here it is: %d", beijing);
	temp = sprintf(maoString, "here it is: %s", radar);
	temp = sprintf(maoFloat, "here it is: %f", ffff);

	temp = 0;

	free(maoInt);
	maoInt = NULL;

}
