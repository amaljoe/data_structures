#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int coeff;
    int exp;
    struct node *link;
};

struct node *getNode();
void initialize(struct node *);
void input(struct node *);
void display(struct node *);
void add();
void multiply();

struct node* p1_header;
struct node* p2_header;
struct node* a_header;
struct node* m_header;

void main()
{
    p1_header = getNode();
    p2_header = getNode();
    a_header = getNode();
    m_header = getNode();
    if (p1_header == NULL || p2_header == NULL || a_header == NULL || m_header == NULL)
    {
        printf("Memory not available.\n");
        return;
    }
    initialize(p1_header);
    initialize(p2_header);
    initialize(a_header);
    initialize(m_header);

    printf("\nPOLYNOMIAL 1\n");
    input(p1_header);
    printf("\nPOLYNOMIAL 2\n");
    input(p2_header);
    
    printf("\nPOLYNOMIAL 1\n");
    display(p1_header);
    printf("\nPOLYNOMIAL 2\n");
    display(p2_header);

    add();
    printf("\nSUM:\n");
    display(a_header);

    multiply();
    printf("\nPRODUCT:\n");
    display(m_header);
}

struct node *getNode()
{
    return (struct node *)malloc(sizeof(struct node));
}

void initialize(struct node *header){
    header->coeff = 0;
    header->exp = 0;
    header->link = NULL;
}

void input(struct node *header)
{
    int i, n;
    printf("Enter the no. of terms in the polynomial:\n");
    scanf("%d", &n);
    struct node *node = header;
    printf("Enter the co-efficient followed by exponent for each term in descending order of exponents:\n");
    for (i = 0; i < n; i++)
    {
        struct node *term = getNode();
        if (term == NULL)
        {
            printf("Memory not available.\n");
            return;
        }
        scanf("%d", &(term->coeff));
        scanf("%d", &(term->exp));
        term->link = NULL;
        node->link = term;
        node = node->link;
    }
}

void display(struct node *header)
{
    struct node *node = header->link;
    while (node != NULL)
    {
        if (node->exp == 0)
        {
            printf("%d", node->coeff);
        }
        else if (node->exp == 1)
        {
            printf("%dx", node->coeff);
        }
        else
        {
            printf("%dx%d", node->coeff, node->exp);
        }
        node = node->link;
        if(node != NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

void add()
{
    struct node *node1 = p1_header->link;
    struct node *node2 = p2_header->link;
    struct node *result = a_header;
    while(node1 != NULL && node2 != NULL){
        struct node *term = getNode();
        if(term == NULL){
            printf("Memory not available.\n");
            return;
        }
        if(node1->exp == node2->exp){
            term->coeff = node1->coeff + node2->coeff;
            term->exp = node1->exp;
            term->link = NULL;
            node1 = node1->link;
            node2 = node2->link;
        }
        else if(node1->exp > node2->exp){
            term->coeff = node1->coeff;
            term->exp = node1->exp;
            term->link = NULL;
            node1 = node1->link;
        }
        else{
            term->coeff = node2->coeff;
            term->exp = node2->exp;
            term->link = NULL;
            node2 = node2->link;
        }
        result->link = term;
        result = result->link;
    }
    while(node1 != NULL){
        struct node *term = getNode();
        if(term == NULL){
            printf("Memory not available.\n");
            return;
        }
        term->coeff = node1->coeff;
        term->exp = node1->exp;
        term->link = NULL;
        node1 = node1->link;
        result->link = term;
        result = result->link;
    }
    while(node2 != NULL){
        struct node *term = getNode();
        if(term == NULL){
            printf("Memory not available.\n");
            return;
        }
        term->coeff = node2->coeff;
        term->exp = node2->exp;
        term->link = NULL;
        node2 = node2->link;
        result->link = term;
        result = result->link;
    }
}

void multiply()
{
    struct node *node1 = p1_header->link;
    while(node1 != NULL){
        struct node *node2 = p2_header->link;
        while(node2 != NULL)
        {
            struct node* term = getNode();
            if(term == NULL)
            {
                printf("Memory not available.");
                return;
            }
            term->coeff = node1->coeff * node2->coeff;
            term->exp = node1->exp + node2->exp;
            term->link = NULL;
            struct node *result = m_header;
            bool exists = false;
            while(result->link != NULL && !exists)
            {
                result = result->link;
                if(result->exp == term->exp)
                {
                    result->coeff += term->coeff;
                    exists = true;
                    break;
                }
            }
            if(!exists)
            {
                result->link = term;
            }
            node2 = node2->link;
        }
        node1 = node1->link;
    }
}
