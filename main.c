
#include <stdio.h>
#include "Socket.h"
#include <string.h>
char buffer[4096] = { 0 };
void main() {
	Socket_Client_Init("54.192.22.61", 80);
	Send("GET /v1/bpi/currentprice.json HTTP/1.1\r\nHost: api.coindesk.com\r\n\r\n");
	Recv(buffer, sizeof(buffer));
	char* keyStar = "\"rate\":";
	char* startPos = strstr(buffer, keyStar);
	startPos += strlen(keyStar);

	char bitcoin[32] = { 0 };
	int i = 0;
	for (i = 0; i <= 12; i++) {
		bitcoin[i] = startPos[i+1];
	}
	bitcoin[13] = "\0";
	printf("%s", bitcoin);
}
