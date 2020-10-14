#include <stdio.h>
#define SIZE 50

int deque[SIZE];
int max;
int rear = -1;
int front = -1;
void insert_front();
void delete_front();
void insert_rear();
void delete_rear();
void print();

int main()
{
    int ch;
    //get the maximum size of deque
    printf("Enter the maximum size of deque: \n");
    scanf("%d", &max);
    //menu driven program
    do
    {
        printf("\nEnter your choice :\n1 - insert at front \t2 - delete from front \n3 - insert at rear \t4 - delete from rear \n5 - display \t\t6 - stop\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_front();
            break;
        case 2:
            delete_front();
            break;
        case 3:
            insert_rear();
            break;
        case 4:
            delete_rear();
            break;
        case 5:
            print();
            break;
        case 6:
            break;
        default:
            printf("Invalid Option\n");
        }
    } while (ch != 6);
}


//insert at front
void insert_front()
{
    //check if deque is full
    if ((rear + 1) % max == front)
    {
        printf("Deque full\n");
        //insertion not possible
        return;
    }
    //check if deque is empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    //if front = first index, then set front = last index
    else if (front == 0)
    {
        front = max - 1;
    }
    else
    {
        front--;
    }
    //insert the element
    printf("Enter the element:\n");
    scanf("%d", &deque[front]);
}

//delete from front
void delete_front()
{
    //check if deque is empty
    if (front == -1)
    {
        printf("Empty deque\n");
        return;
    }
    //print the element to be deleted
    printf("%d deleted\n", deque[front]);
    //check if only one element is present
    if (front == rear)
    {
        //set front and rear to -1 denoting empty deque
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % max;
    }
}

//insert at rear
void insert_rear()
{
    //check if deque is full
    if ((rear + 1) % max == front)
    {
        printf("Deque full\n");
        return;
    }
    //check if deque is empty
    if (rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % max;
    }
    //insert the element
    printf("Enter the element:\n");
    scanf("%d", &deque[rear]);
}

//delete from rear
void delete_rear()
{
    //check if deque is empty
    if (rear == -1)
    {
        printf("Empty deque\n");
        return;
    }
    //print the element to be deleted
    printf("%d deleted\n", deque[rear]);
    //check if only one element is present
    if (front == rear)
    {
        //set front and rear to -1 denoting empty deque
        front = -1;
        rear = -1;
    }
    //if front = first index, then set front = last index
    else if(rear == 0)
    {
        rear = max - 1;
    }
    else{
        rear--;
    }
}

void print()
{
    //check if deque is empty
    if (rear == -1 || front == -1)
    {
        printf("Empty deque\n");
        return;
    }
    //print the elements
    printf("DEQUE:\n");
    int i = front;
    //the following loop will exit before printing last element
    while(i != rear){
        printf("%d\t", deque[i]);
        i = (i + 1) % max;
    }
    //print last element
    printf("%d\n", deque[i]);
}

