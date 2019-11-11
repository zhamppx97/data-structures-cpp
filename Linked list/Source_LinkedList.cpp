#include <stdio.h>
#include <stdlib.h>
#include "Header_LinkedList.h"

pnode createNode()
{
	pnode pnew;
	pnew = (pnode)malloc(sizeof(struct listnode));
	pnew -> data = 0;
	pnew -> pnext = NULL;
	return pnew;
}

pnode ithData(int n, pnode phead)
{
	pnode ptravel;
	ptravel = phead;
	for (int i = 1; i <= n; i++)
	{
		ptravel = ptravel -> pnext;
	}
	return ptravel;
}

int addListNode(int data, pnode phead)
{
	pnode pnew;
	pnew = createNode();
	if (pnew != NULL)
	{
		pnew -> data = data;
		pnew -> pnext = phead -> pnext;
		phead -> pnext = pnew;
		return 1;
	}
	else
	{
		return 0;
	}
}

void travelList(pnode phead)
{
	pnode ptravel;
	ptravel = phead;
	while (ptravel != NULL)
	{
		printf("%p | %d | %p \n", ptravel, ptravel -> data, ptravel -> pnext);
		ptravel = ptravel -> pnext;
	}
}

int insertIth(int ith, pnode phead, int new_data)
{
	pnode pbefore, pnew_data;
	pbefore = ithData(ith - 1, phead);
	pnew_data = createNode();
	if (pnew_data != NULL)
	{
		pnew_data -> data = new_data;
	    pnew_data -> pnext = pbefore -> pnext;
	    pbefore -> pnext = pnew_data;
	}
}

int deleteIth(int ith, pnode phead)
{
	pnode pbefore, pdelete;
	pbefore = ithData(ith - 1, phead);
	pdelete = pbefore -> pnext;
	if (pdelete != NULL)
	{
		pbefore -> pnext = pdelete -> pnext;
		free(pdelete);
		return 1;
	}
	else
	{
		return 0;
	}
}

void deleteAll(pnode phead)
{
	pnode ptravel, ptemp;
	ptravel = phead;
	while (ptravel != NULL)
	{
		ptemp = ptravel;
		ptravel = ptravel -> pnext;
		free(ptemp);
	}
}

void isEmpty(pnode phead)
{
	
}

int firstData(pnode phead)
{
	pnode ptravel;
	ptravel = phead;
	if (ptravel != NULL)
	{
		return ptravel -> data;
	}
}

//int finalData(pnode phead)
//{
//	int count = 0;
//	pnode ptravel;
//	ptravel = phead;
//	while (ptravel != NULL)
//	{
//	}
//}

int findMinData(pnode phead)
{
	int min = INT_MAX;
	pnode ptravel;
	ptravel = phead;
	while (ptravel != NULL)
	{
		if (min > ptravel -> data)
		{
			min = ptravel -> data;
		}
		ptravel = ptravel -> pnext;
	}
	return min;
}

void findPositionData(pnode phead)
{
	int count = 0;
	pnode ptravel;
	ptravel = phead;
	while (ptravel != NULL)
	{
		printf("\nData : %d is position %d\n", ptravel -> data, count);
		count++;
		ptravel = ptravel -> pnext;
	}
}

void findLenghtOfList(pnode phead)
{
	int count = 0;
	pnode ptravel;
	ptravel = phead;
	while (ptravel != NULL)
	{
		count++;
		ptravel = ptravel -> pnext;
	}
	printf("\nLenght of list is : %d\n", count);
}
