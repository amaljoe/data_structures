#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//single node of polynomial
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
    //initialise all linked list headers
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

    //input polynomials
    printf("\nPOLYNOMIAL 1\n");
    input(p1_header);
    printf("\nPOLYNOMIAL 2\n");
    input(p2_header);
    
    //output polynomials
    printf("\nPOLYNOMIAL 1\n");
    display(p1_header);
    printf("\nPOLYNOMIAL 2\n");
    display(p2_header);

    //add polynomials
    add();
    printf("\nSUM:\n");
    display(a_header);

    //multiply polynomials
    multiply();
    printf("\nPRODUCT:\n");
    display(m_header);
}

//allocate memory for a node and return the address to it
struct node *getNode()
{
    return (struct node *)malloc(sizeof(struct node));
}

//initialises the header of a linked list
void initialize(struct node *header){
    header->coeff = 0;
    header->exp = 0;
    header->link = NULL;
}

//input the values of polynomial
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
        //input coefficient and exponent terms
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
        //if exponent term is 0, just print the coefficient part
        if (node->exp == 0)
        {
            printf("%d", node->coeff);
        }
        //if exponent term is 0, print the coefficient part and the variable
        else if (node->exp == 1)
        {
            printf("%dx", node->coeff);
        }
        //else print the coefficient part, variable and exponent part
        else
        {
            printf("%dx%d", node->coeff, node->exp);
        }
        node = node->link;
        //if its not last node, print " + "
        if(node != NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

//add two polynomials
void add()
{
    struct node *node1 = p1_header->link;
    struct node *node2 = p2_header->link;
    struct node *result = a_header;
    //iterate through each term in both polynomials assuming the
    //terms are stored in descending order of their exponents
    while(node1 != NULL && node2 != NULL){
        struct node *term = getNode();
        if(term == NULL){
            printf("Memory not available.\n");
            return;
        }
        //if both terms have same exponents, add them
        if(node1->exp == node2->exp){
            term->coeff = node1->coeff + node2->coeff;
            term->exp = node1->exp;
            term->link = NULL;
            node1 = node1->link;
            node2 = node2->link;
        }
        //if first polynomail has larger exponent term, add it to result
        else if(node1->exp > node2->exp){
            term->coeff = node1->coeff;
            term->exp = node1->exp;
            term->link = NULL;
            node1 = node1->link;
        }
        //if second polynomail has larger exponent term, add it to result
        else{
            term->coeff = node2->coeff;
            term->exp = node2->exp;
            term->link = NULL;
            node2 = node2->link;
        }
        result->link = term;
        result = result->link;
    }
    //the above while loop will end when one of the two polynomials reaches its end
    //the following two while loops will include the remaining elements to the resultant polynomial
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
    //loop through first polynomial terms
    while(node1 != NULL){
        struct node *node2 = p2_header->link;
        //loop through second polynomial terms
        while(node2 != NULL)
        {
            struct node* term = getNode();
            if(term == NULL)
            {
                printf("Memory not available.");
                return;
            }
            //multiply coefficient terms
            term->coeff = node1->coeff * node2->coeff;
            //add exponent terms
            term->exp = node1->exp + node2->exp;
            term->link = NULL;
            struct node *result = m_header;
            bool exists = false;
            //if same power term already exits in the result, add the coefficient to it
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
            //else add the new term to the result
            if(!exists)
            {
                result->link = term;
            }
            node2 = node2->link;
        }
        node1 = node1->link;
    }
}
