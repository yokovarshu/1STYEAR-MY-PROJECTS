/*
    Infix to Postfix Conversion Program
    Using stack implementation.
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

char stack[100];
char infix[100], postfix[100];

int top = -1;
int i, j = 0;


// push character
void push(char ch)
{
    top++;
    stack[top] = ch;
}


// pop character
char pop()
{
    return stack[top--];
}


// precedence function
int precedence(char ch)
{
    if(ch == '^')
        return 3;

    else if(ch == '*' || ch == '/')
        return 2;

    else if(ch == '+' || ch == '-')
        return 1;

    return 0;
}


// conversion function
void convert()
{
    printf("Enter infix expression : ");
    scanf("%s", infix);

    for(i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if(isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if(ch == '(')
        {
            push(ch);
        }
        else if(ch == ')')
        {
            while(stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            pop();
        }
        else
        {
            while(top != -1 && precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    while(top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression is : %s\n", postfix);
}


// main function
int main()
{
    int choice;

    do
    {
        printf("\n\n========= INFIX TO POSTFIX MENU =========");
        printf("\n1. Convert Expression");
        printf("\n0. Exit");

        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                convert();
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
