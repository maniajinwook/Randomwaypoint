#include "RandomWaypoint.h"
#include "standardHeader.h"


//Get distance from source to destination
int getDistanceFromSourceToDeststination(struct Node node)
{
	int distance = (int)sqrt(pow((double)node.destination_x - node.source_x, 2.0) + 
							 pow((double)node.destination_y - node.source_y, 2.0));

	return distance;
}

//Get distance from source to current position for exception
int getCurrentDistance(struct Node node)
{
	int distance = (int)sqrt(pow(node.current_x - node.source_x, 2.0) + 
					 	     pow(node.current_y - node.source_y, 2.0));

	return distance;
}