#include "main.h"
#include "standardHeader.h"
#include "RandomWaypoint.h"

int main(int argc, char *argv[])
{
	if(argc != ARGUMENTS)
	{
		printf("Need more Arguments!!\n");
		exit(EXIT_FAILURE);
	}

	run_RandomWaypoint(argv);

	system("pause");
	return 0;
}