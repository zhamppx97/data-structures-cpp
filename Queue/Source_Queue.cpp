#include <stdio.h>
#include <stdlib.h>
#include "Header_Queue.h"

Pqueue createQueue(int capacity)
{
	Pqueue pnewQueue;
	pnewQueue = (Pqueue)malloc(sizeof(struct queue));
	pnewQueue -> size = 0;
	pnewQueue -> capacity = capacity;
	pnewQueue -> front = 0;
	pnewQueue -> rear = -1;
	pnewQueue -> array = (int*)malloc(sizeof(int) * capacity);
	return pnewQueue;
}

int enqueue(int data, Pqueue q1)
{
	if (q1 -> size < q1 -> capacity)
	{
		q1 -> rear = (q1 -> rear + 1) % (q1 -> capacity);
		q1 -> array[q1 -> rear] = data;
		q1 -> size++;
		return 1;
	}
	else
	{
		printf("Queue full");
		return 0;
	}
}

int dequeue(Pqueue pqueue)
{
	int data;
	if (pqueue -> size > 0)
	{
		data = pqueue -> array[pqueue -> front];
		pqueue -> size--;
		pqueue -> front = (pqueue -> front + 1) % (pqueue -> capacity);
		return data;
	}
	else
	{
		return -1;
	}
}

int isEmpty(Pqueue pqueue)
{
	if (pqueue -> size == 0)
	{ 
	    return 1;
	}
	else 
	{ 
	    return 0; 
	}
}
