#ifndef _RANDOMWAYPOINT_H_
#define _RANDOMWAYPOINT_H_

#define START_X 350
#define START_Y 699
#define START_Z 0

//Structure
struct Node{
	int timeTag;

	double current_x;
	double current_y;
	double current_z;
	
	int source_x;
	int source_y;
	int source_z;

	int destination_x;
	int destination_y;
	int destination_z;

	int distanceFromSrcToDest;
	int currentDistance;
};

struct PacketCP_Status{
	int timeTag;

	int nodeNo;
	int current_x;
	int current_y;
	int current_z;
	int destination_x;
	int destination_y;
	int destination_z;
};

//Function
void initialize(char **argv, struct Node **node, struct PacketCP_Status **packetCP_Status);
void run_RandomWaypoint(char **argv);
void setDestination(struct Node *node);
void computeNextCoordinate(struct Node *node);
void setPackets(struct Node *node, struct PacketCP_Status **packetCP_Status);
int getDistanceFromSourceToDeststination(struct Node node);
int getCurrentDistance(struct Node node);
	

//Variable
int nNodes;
int communicationRange;		// 단위: km
int nodeSpeed;				// 단위: km/h
int coverageWidth;			// 단위: km
int coverageHeight;			// 단위: km
int areaSize;				// 단위: km
int executionTime;			// 단위: sec
float velocity;

#endif