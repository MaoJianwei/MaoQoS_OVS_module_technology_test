
#include <stdio.h>
#include <malloc.h>

int main(){

	printf("contact beijing tower at 118.5");

	char * radarList = malloc(1025);

//	FILE * ff = popen("echo 123 | sudo -S ls", "r");
//	printf("%s", fgets(radarList,1024,ff));
//	pclose(ff);

	FILE * fp = popen("echo 123 | sudo -S ovs-ofctl -O OpenFlow13 add-flow s1 in_port=1,actions=output:normal", "r");
	printf("%s", fgets(radarList,1024,fp));
	pclose(fp);

	fp = popen("echo 123 | sudo -S ovs-ofctl -O OpenFlow13 add-flow s1 in_port=2,actions=output:normal", "r");
	printf("%s", fgets(radarList,1024,fp));
	pclose(fp);

	fp = popen("echo 123 | sudo -S tc qdisc add dev s1-eth2 root handle 1 htb", "r");
	printf("%s", fgets(radarList,1024,fp));
	pclose(fp);

	fp = popen("echo 123 | sudo -S tc class add dev s1-eth2 parent 1 classid 2 htb rate 20mbit", "r");
	printf("%s", fgets(radarList,1024,fp));
	pclose(fp);

	fp = popen("echo 123 | sudo -S ovs-ofctl -O OpenFlow13 add-flow s1 in_port=1,actions=set_queue:1,output:2", "r");
	printf("%s", fgets(radarList,1024,fp));
	pclose(fp);


	return 0;
}
