#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    int weight;
    struct node *right;
};

struct node *create();
int cumulativeWeight(struct node *);
void inorder(struct node *);
struct node *findNode();

void main()
{
    printf("Enter the root node: (-1 to stop):\n");
    struct node *root = create();
    printf("The elements are:\n");
    inorder(root);
    printf("\nEnter the element to find cumulative weight of:\n");
    int data;
    scanf("%d", &data);
    struct node *key = findNode(data, root);
    int cWeight = cumulativeWeight(key);
    printf("Cumulative weight of %d = %d", key->data, cWeight);
}

// return cumulative weight of given node
int cumulativeWeight(struct node *root)
{
    // check for end of tree
    if (root == NULL)
    {
        return 0;
    }
    // add left and right nodes weight with its weight
    return cumulativeWeight(root->left) + cumulativeWeight(root->right) + root->weight;
}

// search for a specific data and return its node or return null if not found
struct node *findNode(int data, struct node *root)
{
    // check for end of tree
    if (root == NULL)
    {
        return NULL;
    }
    // check if the node data is equal to the search data
    if (root->data == data)
    {
        return root;
    }
    // else traverse the left branch
    struct node *left = findNode(data, root->left);
    // if node found in left branch, return it
    if (left != NULL)
    {
        return left;
    }
    // else check in right branch
    struct node *right = findNode(data, root->right);
    return right;
}

// inorder traversal of tree
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d  ", root->data);
    inorder(root->right);
}

//create a node and its children recursively
struct node *create()
{
    int data;
    struct node *root = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &data);
    // terminate if input is -1
    if (data == -1)
    {
        return NULL;
    }
    else
    {
        root->data = data;
        printf("Enter the weight of %d:\n", data);
        scanf("%d", &(root->weight));
        printf("Enter the left child of %d:\n", data);
        root->left = create();
        printf("Enter the right child of %d:\n", data);
        root->right = create();
        return root;
    }
}