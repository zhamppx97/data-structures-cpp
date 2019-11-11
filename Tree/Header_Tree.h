#ifndef Tree_h
#define Tree_h

typedef struct tree * ptreeNode;
struct tree
{
	char * label;
	ptreeNode firstChild;
	ptreeNode Sibling;
};

ptreeNode createTreeNode(int labelSize);
ptreeNode findLabel(ptreeNode proot, char * label);
ptreeNode addNode(ptreeNode parentNode, char * label);
ptreeNode addNodeTree(ptreeNode parentNode, char * label);
void listChild(ptreeNode parentNode);
void listSubtree(ptreeNode  parentNode);
void deleteTree(ptreeNode parentNode);
void deleteLeaf(ptreeNode parentNode);

#endif
