#include <stdio.h>
#define MAX 10
#define true 1
#define false 0

struct QUEUE
{
    int F;
    int R;
    int data[MAX];
};

int isFull(struct QUEUE *s)
{
    if (s->R == MAX - 1)
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
    if (s->R < s->F)
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
    s->R += 1;
    s->data[s->R] = element;
}

int Dequeue(struct QUEUE *s)
{
    int ret = s->data[s->F];
    s->F += 1;
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
    int tmp1, tmp2, choice;
    struct QUEUE LQ = {0, -1};

    do
    {
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.CHECK FRONT\n4.CHECK REAR\n5.EXIT\n");
        printf("> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isFull(&LQ))
            {
                printf("QUEUE IS FULL \n");
            }
            else
            {
                printf("Enter Element:");
                scanf("%d", &tmp1);
                Enqueue(&LQ, tmp1);
                printf("%d Was Inserted\n", tmp1);
            }
            break;

        case 2:
            if (isEmpty(&LQ))
            {
                printf("QUEUE IS EMPTY \n");
            }
            else
            {
                printf("%d WAS REMOVED\n", Dequeue(&LQ));
            }
            break;

        case 3:
            if (isEmpty(&LQ))
            {
                printf("QUEUE IS EMPTY \n");
            }
            else
            {
                printf("%d is at FRONT\n", CheckFront(&LQ));
            }
            break;

        case 4:
            if (isEmpty(&LQ))
            {
                printf("QUEUE IS EMPTY \n");
            }
            else
            {
                printf("%d is at REAR\n", CheckRear(&LQ));
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
