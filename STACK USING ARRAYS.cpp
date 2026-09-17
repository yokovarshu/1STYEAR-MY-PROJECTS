/*
    Stack Program using Arrays
    Simple menu driven implementation.
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

int value, i;


// push operation
void push()
{
    if(top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter value to push : ");
    scanf("%d", &value);

    top++;
    stack[top] = value;

    printf("Element pushed successfully\n");
}


// pop operation
void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("Deleted element is %d\n", stack[top]);
    top--;
}


// peek operation
void peek()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element is %d\n", stack[top]);
}


// display stack
void display()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("\nStack elements are : \n");

    for(i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}


// count elements
void countElements()
{
    printf("Number of elements = %d\n", top + 1);
}


// main function
int main()
{
    int choice;

    do
    {
        printf("\n\n========= STACK MENU =========");
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
