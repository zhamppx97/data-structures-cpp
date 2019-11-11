#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header_Tree.h"
#include "Source_Tree.cpp"

int main(int argc, const char *argv[])
{
	ptreeNode proot, pt, pt2;
	proot = createTreeNode(5);
	strcpy(proot -> label, "Main items");
	addNodeTree(proot, "Items");
	addNodeTree(proot, "Item 1");
	addNodeTree(proot, "Item 2");
	addNodeTree(proot, "Item 3");
	addNodeTree(proot, "Item 4");
	addNodeTree(proot, "Item 5");
	listChild(proot);
	
	pt = findLabel(proot, "1");
	addNodeTree(pt, "2");
	addNodeTree(pt, "3");
	pt2 =findLabel(proot, "3");
	addNodeTree(pt2, "4");
	printf("\n");
	listChild(pt);
	listSubtree(proot);
	
	//deleteTree(proot);
	//printf("\n Tree Deleted. \n\n");
	
	//deleteLeaf(proot);
	//printf("\nLeaf Deleted.");
	return 0;
}
