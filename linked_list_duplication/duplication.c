#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *input();
void traverse(struct node *);
void findDuplicate(struct node *);
void delete (struct node *, struct node *);
void display(struct node *);

void main()
{
    printf("Input elements (-1 to stop):\n");
    struct node *header = (struct node *)malloc(sizeof(struct node));
    header->next = input();
    printf("List before removing duplicate elements:\n");
    display(header);
    traverse(header);
    printf("List after removing duplicate elements:\n");
    display(header);
}

struct node *input()
{
    int data;
    scanf("%d", &data);
    if (data == -1)
    {
        return NULL;
    }
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = input();
    return newNode;
}

void traverse(struct node *header)
{
    header = header->next;
    while (header != NULL)
    {
        findDuplicate(header);
        header = header->next;
    }
}

void findDuplicate(struct node *item)
{
    //printf("finding dup for %d\n", item->data);
    struct node *tempNode = item->next;
    struct node *lastNode = item;
    while (tempNode != NULL)
    {
        if (tempNode->data == item->data)
        {
            //printf("dup found for %d\n", item->data);
            delete (tempNode, lastNode);
        }
        lastNode = lastNode->next;
        if (lastNode != NULL)
        {
            tempNode = lastNode->next;
        }
        else
        {
            tempNode = NULL;
        }
    }
}

void delete (struct node *currentNode, struct node *lastNode)
{
    //printf("deleting %d after %d\n", currentNode->data, lastNode->data);
    lastNode->next = currentNode->next;
    free(currentNode);
}

void display(struct node *header)
{
    header = header->next;
    while (header != NULL)
    {
        printf("%d  ", header->data);
        header = header->next;
    }
    printf("\n");
}