#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};

//declaring all parameters for stack and queue as global variables
struct node* top;
struct node* front;
struct node* rear;

//function prototypes
void insert();
void delete();
void qprint();
void push();
void pop();
void sprint();
void stackMenu();
void queueMenu();
struct node* getNode();

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

struct node* getNode(){
    //allocate space for new node and return its address
    struct node* node = (struct node*) malloc(sizeof(struct node));
    return node;
}

void stackMenu(){
    //initialise top of stack
    top = getNode();
    if(top == NULL){
        printf("Memory not available\n");
        return;
    }
    //stack is empty at first
    top -> link = NULL;
    int ch;
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
    struct node* new = getNode();
    if(new == NULL){
        printf("Memory not available\n");
        return;
    }
    int num;
    printf("Enter the element:\n");
    scanf("%d", &num);
    //insert the node
    new -> link = top -> link;
    top -> link = new;
    new -> info = num;
}

void pop(){
    //check if stack is empty
    if(top -> link == NULL){
        printf("Stack is empty\n");
        return;
    }
    //point header to first node
    top = top -> link;
    //print deleted element
    printf("%d deleted.\n", top -> info);
    //change the header data to -1
    top -> info = -1;
}

void sprint(){
    struct node* ptr = top -> link;
    //check if stack is empty
    if(ptr == NULL){
        printf("Stack is empty.\n");
        return;
    }
    printf("\nStack:\n");
    //print first element
    printf("%d", ptr -> info);
    //iterate through each node
    while(ptr -> link != NULL){
        ptr = ptr -> link;
        printf(" <- %d", ptr -> info);
    }
    printf("\n");
}

void queueMenu(){
    //initialise front of stack
    front = getNode();
    if(front == NULL){
        printf("Memory not available\n");
        return;
    }
    //queue is empty at first
    front -> link = NULL;
    rear = front;
    int ch;
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

void insert(){
    struct node* new = getNode();
    if(new == NULL){
        printf("Memory not available\n");
        return;
    }
    int num;
    printf("Enter the element:\n");
    scanf("%d", &num);
    //insert the node
    rear -> link = new;
    new -> link = NULL;
    new -> info = num;
    rear = new;
}

void delete(){
    //check if queue is empty
    if(front -> link == NULL){
        printf("Queue is empty\n");
        return;
    }
    //point front to first node
    front = front -> link;
    //print deleted element
    printf("%d deleted.\n", front -> info);
    //change the header data to -1
    front -> info = -1;
}

void qprint(){
    struct node* ptr = front -> link;
    //check if queue is empty
    if(ptr == NULL){
        printf("Queue is empty.\n");
        return;
    }
    printf("\nQueue:\n");
    //print first element
    printf("%d", ptr -> info);
    //iterate through each node
    while(ptr -> link != NULL){
        ptr = ptr -> link;
        printf(" <- %d", ptr -> info);
    }
    printf("\n");
}
