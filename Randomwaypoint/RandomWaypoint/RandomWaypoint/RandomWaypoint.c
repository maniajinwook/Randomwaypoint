#include "RandomWaypoint.h"
#include "standardHeader.h"
#include "udp_socket.h"


void run_RandomWaypoint(char **argv)
{
	int i, recv_check;
	struct Node *node=NULL;
	struct PacketCP_Status *packetCP_Status=NULL;

	initialize(argv, &node, &packetCP_Status);

	while(node->timeTag < executionTime)
	{	
		for(i=0; i<nNodes; i++)
		{	
			//When the node arrives at destination OR the node is through the destination 
			if( (((int)node[i].current_x == node[i].destination_x) && ((int)node[i].current_y == node[i].destination_y)) ||
				(node[i].currentDistance >= node[i].distanceFromSrcToDest) )
			{	
				//Set next destination
				setDestination(&node[i]);

				//Get distance from source to destination for exception
				node[i].distanceFromSrcToDest = getDistanceFromSourceToDeststination(node[i]);
			}
			
			//Compute next position
			computeNextCoordinate(&node[i]);

			//Get distance from source to current position for exception
			node[i].currentDistance = getCurrentDistance(node[i]);

			//Increase timetag which is second
			node[i].timeTag++;
		}

		setPackets(node, &packetCP_Status);
		
		/*
		for(i=0; i<nNodes; i++)
		{
			printf("%d ", packetCP_Status[i].timeTag);
			printf("%d ", packetCP_Status[i].nodeNo);
			printf("%d ", packetCP_Status[i].current_x);
			printf("%d ", packetCP_Status[i].current_y);
			printf("%d ", packetCP_Status[i].current_z);
			printf("%d ", packetCP_Status[i].destination_x);
			printf("%d ", packetCP_Status[i].destination_y);
			printf("%d\n", packetCP_Status[i].destination_z);
		}
		*/

		//Sleep(500);

		



		//while (recv_check = UDP_Receive() == 10);
		//printf("send complete. \n");
		recv_check = UDP_Receive();
		//printf("receive complete \n");
		UDP_Send((char*)packetCP_Status);


		//system("pause");
	}

	//UDP Close
	UDP_Close();
}