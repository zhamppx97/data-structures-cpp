#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header_Tree.h"

ptreeNode createTreeNode(int labelSize)
{
	ptreeNode pnew;
	pnew = (ptreeNode)malloc(sizeof(struct tree));
	pnew -> label = (char *)malloc(labelSize);
	pnew -> firstChild = NULL;
	pnew -> Sibling = NULL;
	return pnew;
}

ptreeNode addNode(ptreeNode parentNode, char * label)
{
	ptreeNode pnew;
	pnew = createTreeNode((int)strlen(label));
	strcpy(pnew -> label, label);
	pnew -> Sibling = parentNode -> firstChild;
	parentNode -> firstChild = pnew;
	return pnew;
}

ptreeNode addNodeTree(ptreeNode parentNode, char * label)
{
	ptreeNode pnew;
	pnew = createTreeNode((int)strlen(label));
	strcpy(pnew -> label, label);
	
	if (parentNode -> firstChild == NULL)
	{
		parentNode -> firstChild = pnew;
	}
	else
	{
		pnew -> Sibling = parentNode -> firstChild -> Sibling;
		parentNode -> firstChild -> Sibling = pnew;
	}
	return pnew;
}

void listChild(ptreeNode parentNode)
{
	ptreeNode ptreeTravel;
	printf("%15p | %20s | %15p | %15p\n", parentNode, parentNode -> label, parentNode -> firstChild);
	if (parentNode -> firstChild != NULL)
	{
		ptreeTravel = parentNode -> firstChild;
		while (ptreeTravel != NULL)
		{
			printf("%15p | %20s | %15p | %15p\n", ptreeTravel, ptreeTravel -> label, ptreeTravel -> firstChild);
			ptreeTravel = ptreeTravel -> Sibling;
		}
	}
}

ptreeNode findLabel(ptreeNode pnode, char * label)
{
	ptreeNode ptreeTravel, presult = NULL;
	if (strcmp(pnode -> label, label) == 0)
	{
		presult = pnode;
	}
	else if (pnode -> firstChild != NULL)
	{
		ptreeTravel = pnode -> firstChild;
		while (ptreeTravel != NULL)
		{
			presult = findLabel(ptreeTravel, label);
			if (presult != NULL)
			{
				break;
			}
			ptreeTravel = ptreeTravel -> Sibling;
		}
	}
	return presult;
}

void listSubtree(ptreeNode parentNode)
{
	ptreeNode ptreeTravel;
	printf("%15p | %20s | %15p | %15p\n", parentNode, parentNode -> label, parentNode -> firstChild, parentNode -> Sibling);
	if (parentNode -> firstChild != NULL)
	{
		ptreeTravel = parentNode -> firstChild;
		while (ptreeTravel != NULL)
		{
			listSubtree(ptreeTravel);
			ptreeTravel = ptreeTravel -> Sibling;
		}
	}
}

void deleteTree(ptreeNode parentNode)
{
	if (parentNode == NULL) return;
	
	deleteTree(parentNode -> Sibling);
    deleteTree(parentNode -> firstChild);
    
    printf("\n Deleting : %20s", parentNode -> label);
    free(parentNode);
}

void deleteLeaf(ptreeNode parentNode)
{
	if (parentNode == NULL) return;
	
	//if (parentNode -> Sibling == NULL) deleteLeaf(parentNode -> Sibling);
    if (parentNode -> firstChild != NULL) deleteLeaf(parentNode -> firstChild);
    
    printf("\n Deleting : %20s", parentNode -> firstChild -> label);
    free(parentNode -> firstChild);
}
