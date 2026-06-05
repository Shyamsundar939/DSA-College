// stack as an ADT in C

#include <stdio.h>
#define MAX 5
#define true 1
#define false 0

struct stack
{
    int top;
    int data[MAX];
};

int isFull(struct stack s)
{
    if (s.top == MAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int isEmpty(struct stack s)
{
    if (s.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(struct stack *s, int element)
{
    if (s->top == MAX - 1)
        printf("stack overfloe/n");

    if (s->top == -1)
    {
        s->top++;
        s->data[s->top] = element;
    }
}

int pop(struct stack *s)
{
    int element;
    if (s->top == -1)
    {
        printf("stack underflow \n");
        return -1;
    }
    else
    {
        element=  s->data[(s->top)--];
        printf("Element %d is popped from stack \n", element);
        return element;

    }
    
}

int main()
{

    struct stack s = {-1};

    int choice, element;

    do
    {

        printf("chooose the operation you want to perform \n");
        printf(" \n 1.Push\n 2.pop \n 3.Exist \n ");
        printf("Enter your choice?-> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int element;
            printf("Enter the element you want to push \n ");
            scanf("%d", &element);

            push(&s, element);
            printf("Element %d is pushed to stack \n", element);

            break;
        }
        case 2:
        {
            pop(&s);
            break;
        }
        case 3:
        {
            printf("Thank you  \n");
            break;
        }
        default:
        {
            printf("Invalid choice \n");
            break;
        }
        }

    } while (choice != 3);

    return 0;
}