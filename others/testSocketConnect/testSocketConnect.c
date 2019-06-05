

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> /*struct sockaddr_in*/
#include <arpa/inet.h>  /*inet_pton */
#include <error.h>

#include <unistd.h>
#include <malloc.h>

void main(void){

	struct sockaddr_in * peerSockaddr = (struct sockaddr_in *)calloc(1, sizeof(struct sockaddr_in));
	peerSockaddr->sin_family = AF_INET;
	peerSockaddr->sin_port = htons(5511);

	int ptonRet = inet_pton(AF_INET, "127.0.0.1", &(peerSockaddr->sin_addr));
	//char buf[30] = {0};
	//char * ntopRet = inet_ntop(AF_INET, &(peerSockaddr->sin_addr), buf, 29);


	int connectSocket = socket(AF_INET, SOCK_STREAM, 0);
	int connectRet = connect(connectSocket, (struct sockaddr*)peerSockaddr, sizeof(struct sockaddr_in));

	sleep(5);

	char * html = "<html><body>Beijing Tower 118.5</body></html>";
	int sendRet = send(connectSocket, html, strlen(html), 0);

	printf("send html %d\n", sendRet);

	sleep(5);

	close(connectSocket);

	free(peerSockaddr);
}
