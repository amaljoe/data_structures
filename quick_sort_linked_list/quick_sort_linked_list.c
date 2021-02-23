#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    int index;
    struct node *next;
};

struct node *header;

struct node *input(struct node *);
void quickSort(struct node *, struct node *);
struct node *partition(struct node *, struct node *);
void swap(struct node *, struct node *);
void display(struct node *);

void main()
{
    header = (struct node *)malloc(sizeof(struct node));
    header->prev = NULL;
    header->data = 0;
    header->index = -1;
    header->next = NULL;
    printf("Enter -1 to stop\n");
    struct node *lastNode = input(header);
    display(header);
    quickSort(header->next, lastNode);
    printf("SORTED LIST:\n");
    display(header);
}

//returns the last node
struct node *input(struct node *header)
{
    printf("Enter element:\n");
    int num;
    scanf("%d", &num);
    //terminating condition
    if (num == -1)
    {
        return header;
    }
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->prev = header;
    newNode->next = NULL;
    newNode->index = header->index + 1;
    header->next = newNode;
    return input(newNode);
}

void quickSort(struct node *start, struct node *end)
{
    if (start != NULL && end != NULL && start->index < end->index)
    {
        struct node *mid = partition(start, end);
        quickSort(start, mid->prev);
        quickSort(mid->next, end);
    }
}

struct node *partition(struct node *start, struct node *end)
{
    struct node *pivot = start;
    while (start != NULL && end != NULL && start->index < end->index)
    {
        while (start != NULL && start->data <= pivot->data)
        {
            start = start->next;
        }
        while (end != NULL && end->data > pivot->data)
        {
            end = end->prev;
        }
        if (start == NULL && end == NULL && start->index < end->index)
        {
            swap(start, end);
        }
    }
    swap(pivot, end);
    return end;
}

void swap(struct node *start, struct node *end)
{
    if (start == NULL || end == NULL)
    {
        return;
    }

    int tempData = start->data;
    start->data = end->data;
    end->data = tempData;

    // struct node *tempNode = start->prev;
    // start->prev = end->prev;
    // end->prev = tempNode;
    // tempNode = start->next;
    // start->next = end->next;
    // end->next = tempNode;
    // int tempIndex = start->index;
    // start->index = end->index;
    // end->index = tempIndex;

    // tempNode = start;
    // start = end;
    // end = tempNode;

    // start->prev->next = start;
    // end->prev->next = end;
    // start->next->prev = start;
    // end->next->prev = end;
}

void display(struct node *header)
{
    header = header->next;
    while (header != NULL)
    {
        printf("%d ", header->data);
        header = header->next;
    }
    printf("\n");
}
