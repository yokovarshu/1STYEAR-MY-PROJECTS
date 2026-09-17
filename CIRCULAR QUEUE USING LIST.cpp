/*
    Circular Queue using Linked List
    Rear node points back to front.
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

    if(front == NULL)
    {
        front = rear = newNode;
        rear->next = front;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    printf("Element inserted successfully\n");
}


// dequeue operation
void dequeue()
{
    if(front == NULL)
    {
        printf("Circular Queue Underflow\n");
        return;
    }

    tempNode = front;

    printf("Deleted element is %d\n", tempNode->data);

    // only one node present
    if(front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }

    free(tempNode);
}


// peek operation
void peek()
{
    if(front == NULL)
    {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Front element is %d\n", front->data);
}


// display operation
void display()
{
    if(front == NULL)
    {
        printf("Circular Queue is empty\n");
        return;
    }

    tempNode = front;

    printf("\nCircular Queue elements are : ");

    do
    {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;

    } while(tempNode != front);

    printf("\n");
}


// count elements
void countElements()
{
    int count = 0;

    if(front == NULL)
    {
        printf("Number of elements = 0\n");
        return;
    }

    tempNode = front;

    do
    {
        count++;
        tempNode = tempNode->next;

    } while(tempNode != front);

    printf("Number of elements = %d\n", count);
}


// main function
int main()
{
    int choice;

    do
    {
        printf("\n\n========= CIRCULAR QUEUE USING LIST MENU =========");
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
