#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *link;
};

struct node *getNode();
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
    printf("\nPOLYNOMIAL 1\n");
    input(p1_header);
    printf("\nPOLYNOMIAL 2\n");
    input(p2_header);
    printf("\nPOLYNOMIAL 1\n");
    display(p1_header);
    printf("\nPOLYNOMIAL 2\n");
    display(p2_header);
}

struct node *getNode()
{
    return (struct node *)malloc(sizeof(struct node));
}

void input(struct node *header)
{
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

}

void multiply()
{
}
