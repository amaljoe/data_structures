#include <stdio.h>
#include <stdlib.h>

struct node *create();
void inorder(struct node *);
int cumulate();
struct node *search(int, struct node *ptr);

struct node
{
    int data, weight;
    struct node *left, *right;
};

void inorder(struct node *ptr)
{
    inorder(ptr->left);
    printf("%d", ptr->data);
    inorder(ptr->right);
}

int cumulate(struct node *ptr)
{
    int c;
    c = ptr->weight + cumulate(ptr->left) + cumulate(ptr->right);
    return c;
}

struct node *search(int item, struct node *root)
{
    if (root->data == item)
    {
        return root;
    }
    else
    {
        root = search(item, root->left);
        root = search(item, root->right);
    }
}

struct node *create()
{
    struct node *temp;
    int choice;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nPress 0 to exit");
    printf("\nPress 1 for new node");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    if (choice == 0)
    {
        return 0;
    }
    else
    {
        printf("\nEnter the data:");
        scanf("%d", &temp->data);
        printf("Enter the weight of %d:", temp->data);
        scanf("%d", &temp->weight);
        printf("\nEnter the left child of %d", temp->data);
        temp->left = create();
        printf("\nEnter the right child of %d", temp->data);
        temp->right = create();
        return temp;
    }
}

void main()
{
    int item, cumweight;
    struct node *root, *cw;
    root = create();
    printf("\nElements are:\n");
    printf("%d", root->data);
    inorder(root);
    printf("\nEnter the element whose cumulative weight is to be found:");
    scanf("%d", item);
    cw = search(item, root);
    cumweight = cumulate(cw);
}