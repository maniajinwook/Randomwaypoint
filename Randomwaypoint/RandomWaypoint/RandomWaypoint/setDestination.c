#include "RandomWaypoint.h"
#include "standardHeader.h"

void setDestination(struct Node *node)
{
	node->source_x = node->destination_x;
	node->source_y = node->destination_y;

	node->destination_x = rand()%areaSize;
	node->destination_y = rand()%areaSize;	
}