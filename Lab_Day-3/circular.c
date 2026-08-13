#include <stdio.h>
#define MAX 5
#define true 1
#define false 0

struct QUEUE
{
    int F;
    int R;
    int size;
    int data[MAX];
};

int isFull(struct QUEUE *s)
{
    if (s->size == MAX )
    {
        return true;
    }
    else
    {
        return false;
    }
}

int isEmpty(struct QUEUE *s)
{
    if (s->size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Enqueue(struct QUEUE *s, int element)
{
    s->R = (s->R+1)%MAX;
    s->data[s->R] = element;
    s->size ++;
}

int Dequeue(struct QUEUE *s)
{

    int ret = s->data[s->F];
    s->F =(s->F +1)% MAX;
    s->size --;
    return ret;
}

int CheckFront(struct QUEUE *s)
{
    return s->data[s->F];
}

int CheckRear(struct QUEUE *s)
{
    return s->data[s->R];
}

int main()
{
    int value, choice;
    struct QUEUE Queue={0,-1,0};

    do
    {
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.CHECK FRONT\n4.CHECK REAR\n5.EXIT\n");
        printf("> ");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isFull(&Queue))
            {
                printf("QUEUE IS FULL \n");
            }
            else
            {
                printf("Enter Element:");
                scanf("%d", &value);
                Enqueue(&Queue, value);
                printf("%d Was Inserted\n", value);
            }
            break;

        case 2:
            if (isEmpty(&Queue))
            {
                printf("QUEUE IS EMPTY \n");
            }
            else
            {
                printf("%d WAS REMOVED\n", Dequeue(&Queue));
            }
            break;

        case 3:
            if (isEmpty(&Queue))
            {
                printf("QUEUE IS EMPTY \n");
            }
            else
            {
                printf("%d is at FRONT\n", CheckFront(&Queue));
            }
            break;

        case 4:
            if (isEmpty(&Queue))
            {
                printf("QUEUE IS EMPTY \n");
            }
            else
            {
                printf("%d is at REAR\n", CheckRear(&Queue));
            }
            break;

        case 5:
            printf("BYE\n");
            break;

        default:
            printf("Please Enter 1,2,3,4 or 5 only\n");
            break;
        }

    } while(choice != 5);
    printf("\n");
    return 0;

}
