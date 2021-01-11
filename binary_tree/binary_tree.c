#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
};

struct node* create(){
    int data;
    struct node *root = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    } else {
        root -> data = data;
        printf("Enter the left child of %d:\n", data);
        root -> left = create();
        printf("Enter the right child of %d:\n", data);
        root -> right = create();
    }
}

void preorder(struct node *root){
    if(root == NULL) {
        return;
    }
    printf("%d  ", root -> data);
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(struct node *root){
    if(root == NULL) {
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    printf("%d  ", root -> data);
}

void inorder(struct node *root){
    if(root == NULL) {
        return;
    }
    inorder(root -> left);
    printf("%d  ", root -> data);
    inorder(root -> right);
}

void main() {
    printf("Enter the root node(-1 to stop):\n");
    struct node* root = create();
    printf("\nPre-order traversal:\n");
    preorder(root);
    printf("\nIn-order traversal:\n");
    inorder(root);
    printf("\nPost-order traversal:\n");
    postorder(root);
}