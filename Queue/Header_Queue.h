#ifndef Queue_h
#define Queue_h

typedef struct queue * Pqueue;
struct queue
{
	int size;
	int capacity;
	int front;
	int rear;
	int * array;
};

Pqueue createQueue(int capacity);
int enqueue(int data, Pqueue pqueue);
int dequeue(Pqueue pqueue);
int isEmpty(Pqueue pqueue);

#endif
