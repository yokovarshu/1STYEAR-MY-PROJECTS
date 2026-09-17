/*
    Queue Program using Linked List
    FIFO implementation.
*/

#include<stdio.h>
#include<stdlib.h>

int value;

// node structure
struct node
{
    int data;
    struct node *next;

} *front = NULL, *rear = NULL, *newNode, *tempNode;


// enqueue operation
void enqueue()
{
    newNode = (struct node*)malloc(sizeof(struct node));

    printf("Enter value : ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if(front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Element inserted successfully\n");
}


// dequeue operation
void dequeue()
{
    if(front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    tempNode = front;

    printf("Deleted element is %d\n", tempNode->data);

    front = front->next;

    if(front == NULL)
    {
        rear = NULL;
    }

    free(tempNode);
}


// peek operation
void peek()
{
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Front element is %d\n", front->data);
}


// display queue
void display()
{
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    tempNode = front;

    printf("\nQueue elements are : ");

    while(tempNode != NULL)
    {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }

    printf("\n");
}


// count elements
void countElements()
{
    int count = 0;

    tempNode = front;

    while(tempNode != NULL)
    {
        count++;
        tempNode = tempNode->next;
    }

    printf("Number of elements = %d\n", count);
}


// main function
int main()
{
    int choice;

    do
    {
        printf("\n\n========= QUEUE USING LIST MENU =========");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Count Elements");
        printf("\n0. Exit");

        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                countElements();
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
