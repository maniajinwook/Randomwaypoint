#include "RandomWaypoint.h"
#include "standardHeader.h"

void setPackets(struct Node *node, struct PacketCP_Status **packetCP_Status)
{
	int i;

	for(i=0; i<nNodes; i++)
	{
		(*packetCP_Status)[i].timeTag		= node[i].timeTag;
		(*packetCP_Status)[i].nodeNo		= i;
		(*packetCP_Status)[i].current_x		= (int)node[i].current_x;
		(*packetCP_Status)[i].current_y		= (int)node[i].current_y;
		(*packetCP_Status)[i].current_z		= (int)node[i].current_z;
		(*packetCP_Status)[i].destination_x = node[i].destination_x;
		(*packetCP_Status)[i].destination_y = node[i].destination_y;
		(*packetCP_Status)[i].destination_z = node[i].destination_z;
	}
}