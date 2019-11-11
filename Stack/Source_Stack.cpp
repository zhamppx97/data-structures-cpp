#include <stdio.h>
#include <stdlib.h>
#include "Header_Stack.h"

Pstack createStack(int capasity)
{
	Pstack PstackNew;
	PstackNew = (Pstack)malloc(sizeof(struct stack));
	PstackNew -> topIndex = -1;
	PstackNew -> capasity = capasity;
	PstackNew -> array = (int*)malloc(capasity * sizeof(int));
	return PstackNew;
}

int push(int data, Pstack pstack)
{
	if ((pstack -> topIndex) < (pstack -> capasity - 1))
	{
		pstack -> topIndex++;
		pstack -> array[pstack -> topIndex] = data;
		return 1;
	}
	else
	{
		return 0;
	}
}

int pop(Pstack pstack)
{
	if (pstack -> topIndex >= 0)
	{
		pstack -> topIndex --;
		return 1;
	}
	else
	{
		return 0;
	}
}

int isEmpty(Pstack pstack)
{
	if (pstack -> topIndex == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int topOfStack(Pstack pstack)
{
	if (isEmpty(pstack) != 1)
	{
		return pstack -> array[pstack -> topIndex];
	}
	else
	{
		return -1;
	}
}

int sizeOfStack(Pstack pstack)
{
	return (pstack -> topIndex) + 1;
}

int spaceOfStack(Pstack pstack)
{
	return (pstack -> capasity) - ((pstack -> topIndex) + 1);
}
