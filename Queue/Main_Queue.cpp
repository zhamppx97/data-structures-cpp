#include <stdio.h>
#include <stdlib.h>
#include "Header_Queue.h"
#include "Source_Queue.cpp"

int main(int argc, char *argv[])
{
	int capacity, value;
	printf("Please enter capacity of Queue : ");
	scanf("%d", &capacity);
	printf("Please enter %d element of Queue : ", capacity);
	
	Pqueue pqueue1;
	pqueue1 = createQueue(capacity);
	for (int i = 0; i < capacity; i++)
	{
		scanf("%d", &value);
		enqueue(value, pqueue1);
	}
	
	/*enqueue(1, pqueue1);
	enqueue(2, pqueue1);
	enqueue(3, pqueue1);
	enqueue(4, pqueue1);
	enqueue(5, pqueue1);
	enqueue(6, pqueue1);
	enqueue(7, pqueue1);
	enqueue(8, pqueue1);
	enqueue(9, pqueue1);*/
	
	printf("Front = %d\n", pqueue1 -> front);
	printf("Rear = %d\n", pqueue1 -> rear);
	printf("Size = %d\n", pqueue1 -> size);
	
	for (int i = 0; i < pqueue1 -> capacity; i++)
	{
		printf("%d\n", pqueue1 -> array[i]);
	}
	return 0;
}
