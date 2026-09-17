/*
    Circular Queue Program
    Using arrays for implementation.
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int cqueue[SIZE];

int front = -1;
int rear = -1;

int value, i;


// enqueue operation
void enqueue()
{
    if((rear + 1) % SIZE == front)
    {
        printf("Circular Queue Overflow\n");
        return;
    }

    printf("Enter value : ");
    scanf("%d", &value);

    if(front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % SIZE;
    }

    cqueue[rear] = value;

    printf("Element inserted successfully\n");
}


// dequeue operation
void dequeue()
{
    if(front == -1)
    {
        printf("Circular Queue Underflow\n");
        return;
    }

    printf("Deleted element is %d\n", cqueue[front]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}


// display operation
void display()
{
    if(front == -1)
    {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("\nCircular Queue elements are : ");

    i = front;

    while(i != rear)
    {
        printf("%d ", cqueue[i]);
        i = (i + 1) % SIZE;
    }

    printf("%d", cqueue[rear]);

    printf("\n");
}


// peek operation
void peek()
{
    if(front == -1)
    {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Front element is %d\n", cqueue[front]);
}


// main function
int main()
{
    int choice;

    do
    {
        printf("\n\n========= CIRCULAR QUEUE MENU =========");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
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

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 0);

    return 0;
}
