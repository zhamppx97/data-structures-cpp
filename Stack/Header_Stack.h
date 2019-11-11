#ifndef Stack_h
#define Stack_h

typedef struct stack * Pstack;
struct stack
{
	int topIndex;
	int capasity;
	int *array;
};

Pstack createStack(int capasity);
int push(int data, Pstack pstack);
int pop(Pstack pstack);
int topOfStack(Pstack pstack);
int isEmpty(Pstack pstack);
int sizeOfStack(Pstack pstack);
int spaceOfStack(Pstack pstack);

#endif
