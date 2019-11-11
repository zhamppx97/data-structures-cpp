#include <stdio.h>
#include <stdlib.h>
#include "Header_LinkedList.h"
#include "Source_LinkedList.cpp"

int main(int argc, char *argv[])
{
	int input_val, position, selected_elements, array[20];
	printf("How much element do you want? (Maximum is 20 element) : ");
	scanf("%d", &selected_elements); // Receive value from user.
	printf("Please enter %d elements of integers then space. If done please push \"Enter\" : ", selected_elements);
	
	pnode phead1;
	phead1 = createNode();
	for(int i = 0; i < selected_elements; i++) // Loop add list node.
	{
		scanf("%d", &array[i]);
	    addListNode(array[i], phead1);
	}
	printf("\nThis is results of travel lists.\n");
	travelList(phead1); // Travel list when add completed.
	
	isEmpty(phead1);
	printf("\nFirst data in linked list is : %d", firstData(phead1));
	printf("\nMinimum data in linked list is : %d\n", findMinData(phead1));
	findPositionData(phead1);
	findLenghtOfList(phead1);
	
	// Menu
	int seleted_menu;
	printf("\n----- Menu -----\n");
	printf("1.Add list\n");
	printf("2.Insert\n");
	printf("3.Delete some position\n");
	printf("4.Delete all\n");
	printf("5.Exit\n");
	printf("Please enter number of menu : ");
	scanf("%d", &seleted_menu);
	switch(seleted_menu) // User selete menu.
	{
		case 1: printf("\nYou seleted menu 1.Add list\n");
		//-------- This for add list ---------//
		printf("How much element do you want to add? (Maximum is 20 element) : ");
	    scanf("%d", &selected_elements); // Receive value from user.
	    printf("Please enter %d elements of integers then space for add to list. If done please push \"Enter\" : ", selected_elements);
	    for(int i = 0; i < selected_elements; i++) // Loop add list node.
	    {
		    scanf("%d", &array[i]);
	        addListNode(array[i], phead1);
	    }
		travelList(phead1);
		printf("Added!");
		//-----------------------------------//
			break;
			case 2: printf("\nYou seleted menu 2.Insert\n");
			printf("Please enter position for insert : ");
			scanf("%d", &position);
			printf("Please enter integer data for insert : ");
			scanf("%d", &input_val);
			if (position != 0)
			{
			    insertIth(position, phead1, input_val);
			    travelList(phead1);
			    printf("Inserted!");
			}
				break;
				case 3: printf("\nYou seleted menu 3.Delete some position\n");
				printf("Please enter position number for delete : ");
				scanf("%d", &position);
				if (position <= selected_elements)
				{
					deleteIth(position, phead1);
				    travelList(phead1);
				    printf("Deleted!");
				}
				else
				{
					printf("Wrong position!");
				}
					break;
					case 4: printf("\nYou seleted menu 4.Delete all\n");
				    deleteAll(phead1);
				    printf("Deleted!");
						break;
						case 5:printf("\nYou seleted menu 5.Exit\n"); 
						printf("Goodbye.");
						break;
						default: printf("Wrong choice!\n");
						break;
	}
	return 0;
}
