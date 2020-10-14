#include <stdio.h>
#define SIZE 50

void sort(int[], int);
void input(int[], int*);
void add(int[], int[], int[], int, int, int*);
void output(int[], int);

int main()
{
    //declaring variables for storing polynomials and its sizes
    int n1, n2, n3;
    int poly1[SIZE], poly2[SIZE], poly3[SIZE];
    printf("FIRST POLYNOMIAL:\n");
    input(poly1, &n1);
    printf("SECOND POLYNOMIAL:\n");
    input(poly2, &n2);
    sort(poly1, n1);
    sort(poly2, n2);
    add(poly1, poly2, poly3, n1, n2, &n3);
    printf("\nFIRST POLYNOMIAL:\n");
    output(poly1, n1);
    printf("SECOND POLYNOMIAL:\n");
    output(poly2, n2);
    printf("SUM OF THE TWO POLYNOMIALS:\n");
    output(poly3, n3);
}

void sort(int poly[], int n){
    int i,j;
    //sorting elements in the array with respect to the exponents
    for(i = 1; i < n - 2; i += 2){
        for(j = 1; j < n - i - 1; j += 2)
        {
            //swapping
            if(poly[j] < poly[j + 2]){
                int t1 = poly[j];
                int t2 = poly[j - 1];
                poly[j] = poly[j+2];
                poly[j-1] = poly[j+1];
                poly[j+2] = t1;
                poly[j+1] = t2;
            }
        }
    }
}

void input(int poly[], int* n){
    int i;
    printf("Enter the no. of terms in the polynomial:\n");
    scanf("%d", n);
    //size of the array = no. of term * 2
    *n *= 2;
    printf("Enter the co-effecient followed by exponent for each term:\n");
    for(i = 0; i < *n; i++){
        scanf("%d", &poly[i]);
    }
}

void add(int poly1[], int poly2[], int poly3[], int n1, int n2, int *n3){
    int index1 = 1, index2 = 1, index3 = 1;
    //iterate through each term in both polynomials assuming the terms are stored in descending order of their exponents
    while(index1 < n1 && index2 < n2){
        //if first polynomail has larger exponent term
        if(poly1[index1] > poly2[index2]){
            poly3[index3] = poly1[index1];
            poly3[index3 - 1] = poly1[index1 - 1];
            index1 += 2;
            index3 += 2;
        }
        //if second polynomial has larger exponent term
        else if(poly2[index2] > poly1[index1]){
            poly3[index3] = poly2[index2];
            poly3[index3 - 1] = poly2[index2 - 1];
            index2 += 2;
            index3 += 2;
        }
        //if both terms have same exponents, add them
        else{
            poly3[index3] = poly1[index1];
            poly3[index3 - 1] = poly1[index1 - 1] + poly2[index2 - 1];
            index1 += 2;
            index2 += 2;
            index3 += 2;
        }
    }
    //the above while loop will end when one of the two polynomials reaches its end
    //the following two while loops will include the remaining elements to the resultant polynomial
    while(index1 < n1){
        poly3[index3] = poly1[index1];
        poly3[index3 - 1] = poly1[index1 - 1];
        index1 += 2;
        index3 += 2;
    }
    while(index2 < n2){
        poly3[index3] = poly2[index2];
        poly3[index3 - 1] = poly2[index2 - 1];
        index2 += 2;
        index3 += 2;
    }
    //store the size of array in a variable
    *n3 = index3 - 1;
}

void output(int poly[], int n){
    int i;
    //print the output as polynomial
    for(i = 0; i < n; i++){
        //print the number only if it is a co-efficient or an exponent other than 0 and 1
        if(i % 2 == 0 || (poly[i] != 0 && poly[i] != 1)){
            printf("%d", poly[i]);
        }
        //if reached the end of array break out of the loop(don't check for other conditions)
        if(i + 1 == n){
            printf("\n");
            break;
        }
        //even index contain co-effecient so it should be followed by a variable
        else if(i % 2 == 0){
            //if exponent of that term is zero don't print the variable
            if(poly[i+1] != 0)
            {
                printf("x");
            }
        }
        //if it is the exponent part, print + after that
        else{
            printf(" + ");
        }
    }
}
    
/* int i, j;
    int index = 1;
    for(i = 1; i < n1 * 2; i += 2){
        bool flag = false;
        for(j = 1; j < n2 * 2; j +=2){
            if(poly1[i] == poly2[j]){
                flag = true;
                poly3[index] = poly1[i];
                poly3[index - 1] = poly1[i - 1] + poly2[j - 1];
                index += 2;
                printf("%d", poly1[i - 1] + poly2[j - 1]);
                break;
            }
        }
        if(!flag){
            poly3[index] = poly1[i];
            poly3[index - 1] = poly1[i - 1];
            index += 2;
        }
    }
    for(i = 1; i < n2 * 2; i += 2){
        bool flag = false;
        for(j = 1; j < n1 * 2; j +=2){
            if(poly1[j] == poly2[i]){
                flag = true;
                break;
            }
        }
        if(!flag){
            poly3[index] = poly2[i];
            poly3[index - 1] = poly2[i - 1];
            index += 2;
        }
    }
    *n3 = (index - 2) / 2;
    */





