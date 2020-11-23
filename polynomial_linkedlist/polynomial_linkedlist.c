#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *link;
};

struct node* p1_header;
struct node* p2_header;
struct node* a_header;
struct node* m_header;

struct node *getNode();
void input(struct node *);
void display(struct node *);
void add();
void multiply();

void main()
{
    input(p1_header);
    display(p1_header);
}

struct node *getNode()
{
    return (struct node *)malloc(sizeof(struct node));
}

void input(struct node *header)
{
    header = getNode();
    if (header == NULL)
    {
        printf("Memory not available.\n");
        return;
    }
    header->coeff = 0;
    header->exp = 0;
    header->link = NULL;
    int i, n;
    printf("Enter the no. of terms in the polynomial:\n");
    scanf("%d", &n);
    struct node *node = header;
    printf("Enter the co-efficient followed by exponent for each term:\n");
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
    printf("DEBUG0 display\n");
    struct node *node = header->link;
    printf("DEBUG1 display\n");
    while (node != NULL)
    {
        printf("DEBUG2 display\n");
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
    }
}

void add()
{
}

void multiply()
{
}
