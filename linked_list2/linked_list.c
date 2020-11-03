#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void insert();
void delete();
void reverse();
void display();
void insertAtBeginning();
void insertInMiddle();
void insertAtEnd();
void deleteFromBeginning();
void deleteFromMiddle();
void deleteFromEnd();

struct node {
    int info;
    struct node* link;
};

struct node* header;

struct node* getNode();

void main(){
    //initialise header of linked list
    header = getNode();
    if(header == NULL){
        printf("Memory not available\n");
        return;
    }
    //linked list is empty at first
    header -> link = NULL;
    //menu driven program
    int ch;
    do{
        printf("\nEnter your choice:\n1) insert\n2) delete\n3) reverse\n4) display\n5) stop\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                reverse();
                break;
            case 4:
                display();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(ch != 5);
}

struct node* getNode(){
    //allocate space for new node and return its address
    struct node* node = (struct node*) malloc(sizeof(struct node));
    return node;
}

void insert(){
    //menu for insertion
    int ch;
    printf("\nEnter your choice:\n1) insert at beginning\n2) insert in the middle\n3) insert at the end\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                insertAtBeginning();
                break;
            case 2:
                insertInMiddle();
                break;
            case 3:
                insertAtEnd();
                break;
            default:
                printf("Invalid choice\n");
        }
}

void delete(){
    //check if linked list is empty
    if(header -> link == NULL){
        printf("Linked list is empty\n");
        return;
    }
    //menu for deletion
    int ch;
    printf("\nEnter your choice:\n1) delete from beginning\n2) delete from middle\n3) delete from end\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                deleteFromBeginning();
                break;
            case 2:
                deleteFromMiddle();
                break;
            case 3:
                deleteFromEnd();
                break;
            default:
                printf("Invalid choice\n");
        }
}

void insertAtBeginning(){
    struct node* new = getNode();
    if(new == NULL){
        printf("Memory not available\n");
        return;
    }
    int num;
    printf("Enter the element:\n");
    scanf("%d", &num);
    //insert the node
    new -> link = header -> link;
    header -> link = new;
    new -> info = num;
}

void insertInMiddle(){
    struct node* new = getNode();
    if(new == NULL){
        printf("Memory not available\n");
        return;
    }
    int index;
    printf("Enter the index:\n");
    scanf("%d", &index);
    struct node* ptr = header;
    int i = 0;
    bool flag = false;
    //iterate through each node
    while(ptr != NULL){
        //if element is to be inserted at current index, break
        if(i++ == index){
            flag = true;
            break;
        }
        ptr = ptr -> link;
    }
    //check if index is not available in the linked list
    if(!flag){
        printf("Index out of bound\n");
        return;
    }
    int num;
    printf("Enter the element:\n");
    scanf("%d", &num);
    //insert the node
    new -> link = ptr -> link;
    ptr -> link = new;
    new -> info = num;
}

void insertAtEnd(){
    struct node* new = getNode();
    if(new == NULL){
        printf("Memory not available\n");
        return;
    }
    int num;
    printf("Enter the element:\n");
    scanf("%d", &num);
    struct node* ptr = header;
    //iterate through each node
    while(ptr -> link != NULL){
        ptr = ptr -> link;
    }
    //insert the node
    new -> link = NULL;
    ptr -> link = new;
    new -> info = num;
}

void deleteFromBeginning(){
    //empty condition will be checked beforehand in delete function
    //point header to first node
    header = header -> link;
    //change the header data to -1
    header -> info = -1;
}

void deleteFromMiddle(){
    int index;
    printf("Enter the index:\n");
    scanf("%d", &index);
    struct node* ptr = header;
    int i = -1;
    bool flag = false;
    //iterate through each node
    while(ptr != NULL){
        //if element needs to be inserted next, break
        if(++i == index){
            flag = true;
            break;
        }
        ptr = ptr -> link;
    }
    //check if index was not available in the linked list
    if(!flag){
        printf("Index out of bound\n");
        return;
    }
    struct node* next = ptr -> link;
    //check if its last node
    if(next == NULL){
        //no need to connect to next node since its last node
        ptr -> link = NULL;
    }
    else{
        //connect to next node
        ptr -> link = next -> link;
    }
}

void deleteFromEnd(){
    struct node* ptr = header;
    //iterate through each node
    while(ptr -> link != NULL){
        //if second last node is reached, break the loop
        if(ptr -> link -> link == NULL){
            break;
        }
        ptr = ptr -> link;
    }
    //delete the reference to the last node
    ptr -> link = NULL;
}

void reverse(){
    //check if linked list is empty
    if(header -> link == NULL){
        printf("Linked list is empty\n");
        return;
    }
    struct node* prev = NULL;
    struct node* ptr = header -> link;
    struct node* next;
    //iterate through each node
    while(ptr != NULL){
        //store the next link for later use
        next = ptr -> link;
        //change the next link to point previous node
        ptr -> link = prev;
        //go to next node
        prev = ptr;
        ptr = next;
    }
    //change header link to point former last node
    header -> link = prev;
    printf("Linked list reversed\n");
}

void display(){
    struct node* ptr = header -> link;
    //check if linked list empty
    if(ptr == NULL){
        printf("Empty linked list\n");
        return;
    }
    printf("\nLinked List:\n");
    printf("%d", ptr -> info);
    //iterate through each node
    while(ptr -> link != NULL){
        ptr = ptr -> link;
        printf(" -> %d", ptr -> info);
    }
    printf("\n");
}