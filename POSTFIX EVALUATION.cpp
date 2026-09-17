/*
    Postfix Evaluation Program
    Using stack implementation.
*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int stack[100];
char postfix[100];

int top = -1;
int i;


// push value
void push(int value)
{
    top++;
    stack[top] = value;
}


// pop value
int pop()
{
    return stack[top--];
}


// evaluation function
void evaluate()
{
    int op1, op2, result;

    printf("Enter postfix expression : ");
    scanf("%s", postfix);

    for(i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        if(isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();

            switch(ch)
            {
                case '+':
                    result = op1 + op2;
                    break;

                case '-':
                    result = op1 - op2;
                    break;

                case '*':
                    result = op1 * op2;
                    break;

                case '/':
                    result = op1 / op2;
                    break;

                case '^':
                    result = pow(op1, op2);
                    break;

                default:
                    printf("Invalid operator\n");
                    return;
            }

            push(result);
        }
    }

    printf("Result = %d\n", pop());
}


// main function
int main()
{
    int choice;

    do
    {
        printf("\n\n========= POSTFIX EVALUATION MENU =========");
        printf("\n1. Evaluate Expression");
        printf("\n0. Exit");

        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                evaluate();
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
