#ifndef LinkedList_h
#define LinkedList_h

typedef struct listnode * pnode;
struct listnode
{
	int data;
	pnode pnext;
};

pnode createNode();
int addListNode(int data, pnode phead);
void travelList(pnode phead);
pnode ithData(int n, pnode phead);
int insertIth(int ith, pnode phead, int new_data);
int deleteIth(int ith, pnode phead);
void deleteAll(pnode phead);
void isEmpty(pnode phead);
int firstData(pnode phead);
//int finalData(pnode phead);
int findMinData(pnode phead);
void findPositionData(pnode phead);
void findLenghtOfList(pnode phead);

#endif
