#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 50

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

void inorder(struct node *);
void postorder(struct node *);
struct node *create(char[]);
int getPriority(char);
void substring(char[], char[], int, int);

void main()
{
    char exp[SIZE];
    printf("Enter the expression:\n");
    scanf("%s", exp);
    struct node *root = create(exp);
    printf("INORDER:\n");
    inorder(root);
    printf("\nPOSTORDER:\n");
    postorder(root);
}

struct node *create(char exp[SIZE])
{
    printf("expression = %s\n", exp);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if(strlen(exp) == 1) {
        newNode->data = exp[0];
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    } else if(strlen(exp) < 1) {
        return NULL;
    }
    //FIXME: find lowest priority opertor index in i
    int i = 0;
    int minPriority = getPriority(exp[0]);
    int index = 1;
    while(index < strlen(exp)) {
        if(getPriority(exp[index]) <= minPriority) {
            minPriority = getPriority(exp[index]);
            i = index;
        }
        index++;
    }
    printf("data = %c\n", exp[i]);
    char left[SIZE];
    char right[SIZE];
    substring(exp, left, 0, i);
    substring(exp, right, i + 1, strlen(exp));
    //printf("left = %s\n", left);
    //printf("right = %s\n", right);
    newNode->data = exp[i];
    newNode->left = create(left);
    newNode->right = create(right);
    return newNode;
}

void substring(char ch[], char sub[], int start, int end) {
    int i = 0;
    while(start < end) {
        sub[i] = ch[start];
        start++;
        i++;
    }
    sub[i] = '\0';
}

int getPriority(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 0;
    }
    else if (ch == '*' || ch == '/')
    {
        return 1;
    }
    else if (ch == '^')
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}