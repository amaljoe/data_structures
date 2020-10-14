#include <stdio.h>
#define SIZE 50

//declaring all parameters for stack and queue as global variables
int stack[SIZE];
int smax;
int top = -1;
int queue[SIZE];
int qmax;
int rear = -1;
int front = -1;

//function prototypes
void insert();
void delete();
void qprint();
void push();
void pop();
void sprint();
void stackMenu();
void queueMenu();

void main(){
    int ch;
    do{
        //menu driven program for main screen
        printf("Enter your choice (1 - stack, 2 - queue, 3 - exit) :\n");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            stackMenu();
            break;
        case 2:
            queueMenu();
            break;
        case 3:
            break;
        default:
            printf("Invalid choice\n");
    }
    }while(ch != 3);
}

void queueMenu(){
    int ch;
    printf("Enter the maximum size of queue: \n");
    scanf("%d", &qmax);
    do{
        //menu driven program for queue
        printf("\nEnter your choice (1 - insert, 2 - delete, 3 - display, 4 - stop) :\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                qprint();
            case 4:
                break;
            default:
                printf("Invalid Option\n");
        }
    }while(ch != 4);
}

void stackMenu(){
    int ch;
    printf("Enter the maximum size of stack: \n");
    scanf("%d", &smax);
    do{
        //menu driven program for stack
        printf("\nEnter your choice (1 - push, 2 - pop, 3 - display, 4 - stop) :\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                sprint();
            case 4:
                break;
            default:
                printf("Invalid Option\n");
        }
    }while(ch != 4);
}

void push(){
    //check if stack is full
    if(top == smax - 1){
        printf("Stack Overflow\n");
        return;
    }
    //else increment the top by 1 and add the element at top
    top++;
    printf("Enter the element:\n");
    scanf("%d", &stack[top]);
}

void pop(){
    //check if stack is empty
    if(top == -1){
        printf("Stack Underflow\n");
        return;
    }
    //else print the element at top and decrement top by 1
    printf("%d popped\n", stack[top]);
    top--;
}

void sprint(){
    //check if stack is empty
    if(top == -1){
        printf("Empty stack\n");
        return;
    }
    //print the elements of stack from top to 0 index
    int i;
    for(i = top; i >= 0; i--){
        printf("%d\t", stack[i]);
    }
}

void insert(){
    //check if queue is full
    if(rear == qmax - 1){
    printf("Queue full\n");
        return;
    }
    //check if queue is empty
    if(front == -1){
        front++;
    }
    //else increment rear by 1 and add the element at rear
    rear++;
    printf("Enter the element:\n");
    scanf("%d", &queue[rear]);
}

void delete(){
    //check if queue is empty
    if(front == -1){
        printf("Empty queue\n");
        return;
    }
    //else print the element at front
    printf("%d deleted\n", queue[front]);
    //check if only 1 element exists in the queue
    if(front == rear){
        //make the queue empty
        front = -1;
        rear = -1;
    }
    //else increment front by 1 to remove the element at front from queue
    else{
        front++;
    }
}

void qprint(){
    //check if queue is empty
    if(rear == -1 || front == -1){
        printf("Empty queue\n");
        return;
    }
    int i;
    //print the elements of queue from front to rear
    for(i = front; i <= rear; i++){
        printf("%d\t", queue[i]);
    }
}
