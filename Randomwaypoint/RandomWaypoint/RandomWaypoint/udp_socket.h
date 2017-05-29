#ifndef _UDP_SOCKET_H_
#define _UDP_SOCKET_H_

#pragma comment(lib,"ws2_32.lib")	//Winsock Library

//Define
#define SERVER "127.0.0.1"			//ip address of udp server
#define RECVPORT 8888					//The port on which to listen for incoming data
#define SENDPORT 8889
#define BUFSIZE 1024


//Function
void UDP_Initialize(void);
void UDP_Send(char *data);
int UDP_Receive(void);
void UDP_Close(void);


//Variable
int socketStatus;
int recvsocket;


#endif