#include <stdio.h>

struct node{
    int coeff;
    int exp;
    struct node* link;
};

struct node p1_header;
struct node p2_header;
struct node a_header;
struct node m_header;

struct node* getNode();
void input(struct node*);
void display(struct node*);
void add();
void multiply();

void main(){
    
}

struct node* getNode(){
    return (struct node*) malloc(sizeof(struct node)); 
}


void input(struct node* header){
    struct node* header = getNode();
    if(header == NULL){
        printf("Memory not available.\n");
        return;
    }
    int i, n, coeff, exp;
    printf("Enter the no. of terms in the polynomial:\n");
    scanf("%d", &n);
    struct node* node = header -> link;
    printf("Enter the co-efficient followed by exponent for each term:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &coeff);
        scanf("%d", &exp);
        struct node* term = getNode();
        if(term == NULL){
            printf("Memory not available.\n");
            return;
        }
        term -> coeff = coeff;
        term -> exp = exp;
        term -> link = NULL;
        node -> link = term;
    }
}

void display(struct node* header){

}

void add(){

}

void multiply(){

}

