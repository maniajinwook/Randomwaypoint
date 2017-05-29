#include "udp_socket.h"
#include "standardHeader.h"
#include "RandomWaypoint.h"

//외부에서 해당 변수를 사용하지 못하게 static 으로 선언
static struct sockaddr_in socketAddr;
static struct sockaddr_in fromAddr;
static WSADATA wsa;

void UDP_Send(char *data){
	int socketLength = sizeof(socketAddr);
	
	if (sendto(socketStatus, data, sizeof(struct PacketCP_Status)*nNodes, 0 , (struct sockaddr *) &socketAddr, socketLength) == SOCKET_ERROR)
	{
		printf("sendto() failed with error code : %d" , WSAGetLastError());
		exit(EXIT_FAILURE);
	}
}


int UDP_Receive() {
	int data_length = 0, addr_length, check_num;
	char recvdata[1100];

	addr_length = sizeof(fromAddr);
	
	data_length = recvfrom(recvsocket, recvdata, BUFSIZE, 0, (struct sockaddr *) &fromAddr, &addr_length);	

    recvdata[data_length] = 0;
	//printf("recvdata : %s",recvdata);
	check_num = atoi(recvdata);

	return check_num;
}


void UDP_Initialize(void){

	//Initialize winsock	
	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf("Failed. Error Code : %d",WSAGetLastError());
		exit(EXIT_FAILURE);
	}

	//Create socket
	socketStatus = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	recvsocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if(socketStatus == SOCKET_ERROR || recvsocket == SOCKET_ERROR)
	{
		printf("socket() failed with error code : %d" , WSAGetLastError());
		exit(EXIT_FAILURE);
	}



	//Setup address structure
	memset((char *) &socketAddr, 0, sizeof(socketAddr));
	socketAddr.sin_family = AF_INET;
	socketAddr.sin_port = htons(SENDPORT);
	socketAddr.sin_addr.S_un.S_addr = inet_addr(SERVER);	//Server IP: 127.0.0.1


	memset((char *)&fromAddr, 0, sizeof(fromAddr));
	fromAddr.sin_family = AF_INET;
	fromAddr.sin_port = htons (RECVPORT);
	fromAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);	//Server IP: 127.0.0.1

	bind(recvsocket, (struct sockaddr*)&fromAddr, sizeof(fromAddr));

}

void UDP_Close(void)
{
	//closesocket(socketStatus);
	closesocket(recvsocket);
	WSACleanup();
} 