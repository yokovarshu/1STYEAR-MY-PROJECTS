#include<stdio.h>
#include<stdlib.h>
int value, pos, i;
struct node
{
    int data;
    struct node *prev;
    struct node *next;

} *head = NULL, *tail = NULL, *newNode, *tempNode;
void createList()
{
    char choice;

    do
    {
        newNode = (struct node*)malloc(sizeof(struct node));

        printf("Enter value : ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        // if list empty
        if(head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        printf("Do you want to add another node? (y/n) : ");
        scanf(" %c", &choice);

    } while(choice == 'y' || choice == 'Y');
}
void insertAtBeginning()
{
    newNode = (struct node*)malloc(sizeof(struct node));

    printf("Enter value to insert at beginning : ");
    scanf("%d", &value);

    newNode->data = value;

    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
    {
        head->prev = newNode;
    }
    else
    {
        // list was empty before insertion
        tail = newNode;
    }

    head = newNode;
}
void insertAtEnd()
{
    newNode = (struct node*)malloc(sizeof(struct node));

    printf("Enter value to insert at end : ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;

    if(tail != NULL)
    {
        tail->next = newNode;
    }
    else
    {
        head = newNode;
    }

    tail = newNode;
}


// insertion at specific position
void insertAtPosition()
{
    newNode = (struct node*)malloc(sizeof(struct node));

    printf("Enter position : ");
    scanf("%d", &pos);

    printf("Enter value : ");
    scanf("%d", &value);

    tempNode = head;

    // moving temp node to required position
    for(i = 1; i < pos - 1; i++)
    {
        if(tempNode == NULL)
        {
            printf("Invalid position\n");
            return;
        }

        tempNode = tempNode->next;
    }

    newNode->data = value;

    newNode->next = tempNode->next;
    newNode->prev = tempNode;

    if(tempNode->next != NULL)
    {
        tempNode->next->prev = newNode;
    }

    tempNode->next = newNode;

    // if inserted at last
    if(newNode->next == NULL)
    {
        tail = newNode;
    }

    // honestly DLL pointer work gets confusing sometimes :)
}


// delete from beginning
void deleteAtBeginning()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    tempNode = head;

    printf("Deleted node is %d\n", tempNode->data);

    head = head->next;

    if(head != NULL)
    {
        head->prev = NULL;
    }
    else
    {
        tail = NULL;
    }

    free(tempNode);
}


// delete from end
void deleteAtEnd()
{
    if(tail == NULL)
    {
        printf("List is empty\n");
        return;
    }

    tempNode = tail;

    printf("Deleted node is %d\n", tempNode->data);

    tail = tail->prev;

    if(tail != NULL)
    {
        tail->next = NULL;
    }
    else
    {
        head = NULL;
    }

    free(tempNode);
}


// delete from specific position
void deleteAtPosition()
{
    printf("Enter position : ");
    scanf("%d", &pos);

    tempNode = head;

    for(i = 1; i < pos; i++)
    {
        if(tempNode == NULL)
        {
            printf("Invalid position\n");
            return;
        }

        tempNode = tempNode->next;
    }

    if(tempNode == NULL)
    {
        printf("Node not found\n");
        return;
    }

    printf("Deleted node is %d\n", tempNode->data);

    tempNode->prev->next = tempNode->next;

    if(tempNode->next != NULL)
    {
        tempNode->next->prev = tempNode->prev;
    }
    else
    {
        // deleting last node
        tail = tempNode->prev;
    }

    free(tempNode);
}
void displayForward()
{
    tempNode = head;

    printf("\nList in forward direction : ");

    while(tempNode != NULL)
    {
        printf("%d <-> ", tempNode->data);
        tempNode = tempNode->next;
    }

    printf("NULL\n");
}


// display reverse
void displayReverse()
{
    tempNode = tail;

    printf("\nList in reverse direction : ");

    while(tempNode != NULL)
    {
        printf("%d <-> ", tempNode->data);
        tempNode = tempNode->prev;
    }

    printf("NULL\n");
}


// count nodes
void numberOfNodes()
{
    int count = 0;

    tempNode = head;

    while(tempNode != NULL)
    {
        count++;
        tempNode = tempNode->next;
    }

    printf("Number of nodes = %d\n", count);
}


// linear search operation
void linearSearch()
{
    int key;
    int found = 0;
    int position = 1;

    printf("Enter key element : ");
    scanf("%d", &key);

    tempNode = head;

    while(tempNode != NULL)
    {
        if(tempNode->data == key)
        {
            found = 1;
            break;
        }

        tempNode = tempNode->next;
        position++;
    }

    if(found == 1)
    {
        printf("Key found at position %d\n", position);
    }
    else
    {
        printf("Key not found\n");
    }
}


// reverse doubly linked list
void reverseList()
{
    struct node *currentNode, *nextNode;

    currentNode = head;

    while(currentNode != NULL)
    {
        nextNode = currentNode->next;

        currentNode->next = currentNode->prev;
        currentNode->prev = nextNode;

        currentNode = nextNode;
    }

    // swapping head and tail
    tempNode = head;
    head = tail;
    tail = tempNode;

    printf("List reversed successfully\n");
}


// main function
int main()
{
    int choice;

    do
    {
        printf("\n\n========= MENU =========");
        printf("\n1. Create List");
        printf("\n2. Insert At Beginning");
        printf("\n3. Insert At End");
        printf("\n4. Insert At Position");
        printf("\n5. Delete At Beginning");
        printf("\n6. Delete At End");
        printf("\n7. Delete At Position");
        printf("\n8. Display Forward");
        printf("\n9. Display Reverse");
        printf("\n10. Number Of Nodes");
        printf("\n11. Linear Search");
        printf("\n12. Reverse List");
        printf("\n0. Exit");

        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createList();
                break;

            case 2:
                insertAtBeginning();
                break;

            case 3:
                insertAtEnd();
                break;

            case 4:
                insertAtPosition();
                break;

            case 5:
                deleteAtBeginning();
                break;

            case 6:
                deleteAtEnd();
                break;

            case 7:
                deleteAtPosition();
                break;

            case 8:
                displayForward();
                break;

            case 9:
                displayReverse();
                break;

            case 10:
                numberOfNodes();
                break;

            case 11:
                linearSearch();
                break;

            case 12:
                reverseList();
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 0);

    return 0;
}
