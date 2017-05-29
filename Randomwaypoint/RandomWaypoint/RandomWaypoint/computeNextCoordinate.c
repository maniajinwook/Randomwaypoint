#include "RandomWaypoint.h"
#include "standardHeader.h"

void computeNextCoordinate(struct Node *node)
{	
	int x1 = node->source_x;
	int y1 = node->source_y;
	int x2 = node->destination_x;
	int y2 = node->destination_y;

	double tmp_x = 0;
	double tmp_y = 0;

	double deg;

	// �������� ������ ��ǥ�� x ��ǥ�� ���� ��� ����ó��
	if( (x2-x1 == 0) && (y2 < y1) )
	{
		tmp_x = 0;
		tmp_y = velocity * (-1);
	}
	else if( (x2-x1 == 0) && (y2>=y1) )
	{
		tmp_x = 0;
		tmp_y = velocity;
	}
	else
	{
		deg = atan2((float)y2-y1, (float)x2-x1); // ���ϰ��� ����
	
		tmp_x = velocity * cos(deg);
		tmp_y = velocity * sin(deg);
	}
	
	node->current_x = node->current_x + tmp_x;
	node->current_y = node->current_y + tmp_y;	
}