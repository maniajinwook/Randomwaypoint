#include "RandomWaypoint.h"
#include "standardHeader.h"
#include "udp_socket.h"

void initialize(char **argv, struct Node **node, struct PacketCP_Status **packetCP_Status)
{	
	int i;

	nNodes = atoi(argv[1]);
	communicationRange = atoi(argv[2]);
	nodeSpeed = atoi(argv[3]);
	coverageWidth = atoi(argv[4]);
	coverageHeight = atoi(argv[5]);
	areaSize = atoi(argv[6]);
	executionTime = atoi(argv[7]);
	velocity = (float)nodeSpeed / 3600 * 30;	//30 is test values

	
	//Create and Initialize node
	*packetCP_Status = (struct PacketCP_Status*)calloc(sizeof(struct PacketCP_Status), nNodes);
	*node = (struct Node*)calloc(sizeof(struct Node), nNodes);
	for(i=0; i<nNodes; i++)
	{
		(*node)[i].timeTag = 0;

		(*node)[i].current_x = (double)START_X;
		(*node)[i].current_y = (double)START_Y;
		(*node)[i].current_z = (double)START_Z;

		(*node)[i].destination_x = START_X;
		(*node)[i].destination_y = START_Y;
		(*node)[i].destination_z = START_Z;
	}

	//UDP Initialization
	UDP_Initialize();
}