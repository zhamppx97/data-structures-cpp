#include <stdio.h>
#include "Header_Queue.h"
#include "Source_Queue.cpp"
#define VERTICE 7
#define INFINITY 10000

int UGraph[VERTICE][VERTICE] = 
{
	{0, 1, 0, 1, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0},
	{1, 0, 0, 0, 0, 1, 0},
	{0, 0, 1, 0, 1, 1, 1},
	{0, 0, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 0}
};

int WGraph[VERTICE][VERTICE] = 
{
	{0, 2, 0, 1, 0, 0, 0},
	{0, 0, 0, 3, 10, 0, 0},
	{4, 0, 0, 0, 0, 5, 0},
	{0, 0, 2, 0, 2, 8, 4},
	{0, 0, 0, 0, 0, 0, 6},
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 0}
};

int UTable[VERTICE][3] = 
{
	{0, 0, -1},
	{0, INFINITY, 0},
	{0, INFINITY, 0},
	{0, INFINITY, 0},
	{0, INFINITY, 0},
	{0, INFINITY, 0},
	{0, INFINITY, 0}
};

int WTable[VERTICE][3] = 
{
	{0, 0, -1},
	{0, INFINITY, 0},
	{0, INFINITY, 0},
	{0, INFINITY, 0},
	{0, INFINITY, 0},
	{0, INFINITY, 0},
	{0, INFINITY, 0}
};

void Unweighted()
{
	Pqueue q1;
	int v, w;
	q1 = createQueue(7);
	enqueue(0, q1);
	while (isEmpty(q1) != 1)
	{
		v = dequeue(q1);
		UTable[v][0] = 1;
		for (w = 0; w < VERTICE; w++)
		{
			if (UGraph[v][w] == 1)
			{
				if (UTable[w][1] == INFINITY)
				{
					UTable[w][1] = UTable[v][1] + 1;
					UTable[w][2] = v;
					enqueue(w, q1);
				}
			}
		}
	}
}

int findminIndex()
{
	int i, result = -1, min;
	min = INFINITY;
	for (i = 0; i < VERTICE; i++)
	{
		if (WTable[i][0] == 0)
		{
			if (WTable[i][1] < min)
			{
				min = WTable[i][1];
				result = 1;
			}
		}
	}
	return result;
}

void Dijkstra()
{
	int v, w;
	while (1)
	{
		v = findminIndex();
		if (v == -1) { break; }
		WTable[v][0] = 1;
		for (w = 0; w < VERTICE; w++)
		{
			if (WGraph[v][w] != 0)
			{
				if (WTable[w][0] != 1)
				{
					if (WTable[v][1] + WGraph[v][w] < WTable[w][1])
					{
						WTable[w][1] = WTable[v][1] + WGraph[v][w];
						WTable[w][2] = v;
					}
				}
			}
		}
	}
}

int main(int argc, const char *argv[])
{
	int i;
	Unweighted();
	printf("Unweighted");
	for (i = 0; i < VERTICE; i++)
	{
		printf("\n%d, %d, v%d", UTable[i][0], UTable[i][1], UTable[i][2] + 1);
	}
	printf("\n\n");
	
	Dijkstra();
	printf("Dijkstra");
	for (i = 0; i < VERTICE; i++)
	{
		printf("\n%d, %d, v%d", WTable[i][0], WTable[i][1], WTable[i][2] + 1);
	}
	return 0;
}
