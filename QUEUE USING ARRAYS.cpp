/*
    Queue Program using Arrays
    FIFO implementation.
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

int queue[SIZE];

int front = -1;
int rear = -1;

int value, i;


// enqueue operation
void enqueue()
{
    if(rear == SIZE - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter value : ");
    scanf("%d", &value);

    if(front == -1)
    {
        front = 0;
    }

    rear++;
    queue[rear] = value;

    printf("Element inserted successfully\n");
}


// dequeue operation
void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element is %d\n", queue[front]);

    front++;

    // resetting queue
    if(front > rear)
    {
        front = rear = -1;
    }
}


// display queue
void display()
{
    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("\nQueue elements are : ");

    for(i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}


// peek front element
void peek()
{
    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Front element is %d\n", queue[front]);
}


// count elements
void countElements()
{
    if(front == -1)
    {
        printf("Number of elements = 0\n");
    }
    else
    {
        printf("Number of elements = %d\n", rear - front + 1);
    }
}


// main function
int main()
{
    int choice;

    do
    {
        printf("\n\n========= QUEUE MENU =========");
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
