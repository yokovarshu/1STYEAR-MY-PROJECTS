/*
    Stack Program using Linked List
    Dynamic memory allocation version.
*/

#include<stdio.h>
#include<stdlib.h>

int value, i;

// node structure
struct node
{
    int data;
    struct node *next;

} *top = NULL, *newNode, *tempNode;


// push operation
void push()
{
    newNode = (struct node*)malloc(sizeof(struct node));

    printf("Enter value to push : ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = top;

    top = newNode;

    printf("Element pushed successfully\n");
}


// pop operation
void pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    tempNode = top;

    printf("Deleted element is %d\n", tempNode->data);

    top = top->next;

    free(tempNode);
}


// peek operation
void peek()
{
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element is %d\n", top->data);
}


// display operation
void display()
{
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    tempNode = top;

    printf("\nStack elements are : \n");

    while(tempNode != NULL)
    {
        printf("%d\n", tempNode->data);
        tempNode = tempNode->next;
    }
}


// count nodes
void countElements()
{
    int count = 0;

    tempNode = top;

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
        printf("\n\n========= STACK USING LIST MENU =========");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Count Elements");
        printf("\n0. Exit");

        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
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
