#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
} * root;

struct node *insert(int);
struct node *search(int);
struct node *parent_search(int);
struct node *delete (int);
struct node *inorder(struct node *);
struct node *tree_successor(struct node *);
int tree_height(struct node *);

void main()
{
    int ht, ch, key;

    do
    {
        printf("\n\tOperations Available on Binary Search Tree: \n");
        printf("\t      1.Insert to tree\n");
        printf("\t      2.Delete from tree\n");
        printf("\t      3.Inorder traversal of tree\n");
        printf("\t      4.Height of tree\n");
        printf("\t      5.Exit\n");

        printf("    Enter the choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            printf("\n  Enter the element to be inserted: ");
            scanf("%d", &key);
            insert(key);
        }
        break;

        case 2:
        {
            if (root == NULL)
                printf("    --> Tree is empty, Deletion not possible!!\n");
            else
            {
                printf("\n  Enter the element to be deleted: ");
                scanf("%d", &key);
                delete (key);
            }
        }
        break;

        case 3:
        {
            if (root == NULL)
                printf("    --> Inorder traversal of Binary Search Tree:  Tree is empty\n");
            else
            {
                printf("    --> Inorder traversal of Binary Search Tree:  \n");
                printf("\t");
                inorder(root);
                printf("\n");
            }
        }
        break;

        case 4:
        {
            if (root == NULL)
                printf("    --> Height of Binary Search Tree: 0 (Tree is empty)\n");
            else
            {
                ht = tree_height(root);
                printf("    --> Height of Binary Search Tree: %d\n", ht);
            }
        }
        break;

        case 5:
        {
            printf("\n    Exited from program!!\n");
            exit(0);
        }

        default:
            printf("    --> Wrong choice, Enter a valid choice!!\n");
        }

    } while (ch != 5);
}

struct node *search(int key)
{
    struct node *ptr = root;

    while (ptr != NULL && ptr->info != key)
    {
        if (ptr->info > key)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return (ptr);
}

struct node *parent_search(int key)
{
    struct node *par = NULL;
    struct node *ptr = root;

    while (ptr != NULL && ptr->info != key)
    {
        par = ptr;

        if (ptr->info > key)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return (par);
}

struct node *inorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        printf("%d ", ptr->info);
        inorder(ptr->right);
    }
}

struct node *tree_successor(struct node *z)
{
    struct node *ptr = z->right;

    while (ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    return (ptr);
}

int tree_height(struct node *ptr)
{
    int lht, rht;

    if (ptr == NULL)
        return (0);
    else
    {
        lht = tree_height(ptr->left);
        rht = tree_height(ptr->right);

        if (lht > rht)
            return (lht + 1);
        else
            return (rht + 1);
    }
}

struct node *insert(int key)
{
    struct node *ptr = search(key);

    if (ptr != NULL)
    {
        printf("    --> Element is already present in tree!!\n");
        return (0);
    }
    else
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->info = key;
        newnode->left = newnode->right = NULL;

        if (root == NULL)
        {
            root = newnode;
        }
        else
        {
            struct node *par = parent_search(key);

            if (key > par->info)
                par->right = newnode;
            else
                par->left = newnode;
        }
    }

    printf("    --> Element %d is inserted to the tree\n", key);
}

struct node *delete (int key)
{
    struct node *x, *y, *z, *par;

    z = search(key);

    if (z == NULL)
    {
        printf("    --> Element not present in the tree,Cannot be deleted!!\n");
        return (0);
    }

    if (z->left == NULL || z->right == NULL)
        y = z;
    else
        y = tree_successor(z);

    if (y->left != NULL)
        x = y->left;
    else
        x = y->right;

    par = parent_search(y->info);

    if (par == NULL)
        root = x;
    else if (par->left == y)
        par->left = x;
    else
        par->right = x;

    if (y != z)
        z->info = y->info;

    free(y);
    printf("    --> Element %d is deleted from the tree\n", key);
}