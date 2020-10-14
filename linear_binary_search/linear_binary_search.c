#include <stdio.h>
#include <stdbool.h>
#define SIZE 50

void linear_search();
void binary_search();
void input(int[], int*);

int main()
{
    int ch;
    printf("Enter your option(1 - linear search, 2 - binary search):\n");
    scanf("%d", &ch);
    //menu driven program
    switch(ch){
        case 1:
            linear_search();
            break;
        case 2:
            binary_search();
            break;
        default:
            printf("Invalid option");
    }
    
}

void linear_search(){
    int a[SIZE];
    int n;
    input(a, &n);
    //enter key element
    int key, i;
    bool flag = false;
    printf("Enter the element to be searched:\n");
    scanf("%d", &key);
    //linear_search
    for(i = 0; i < n; i++){
        if(a[i] == key){
            //element found
            flag = true;
            printf("Element %d found at position %d\n", key, i + 1);
            break;
        }
    }
    //if element not found
    if(!flag){
        printf("Element %d not found\n", key);
    }
}

//assuming the array is sorted - otherwise sort before doing binary search
void binary_search(){
    int a[SIZE];
    int n;
    input(a, &n);
    //enter key element
    int key, i;
    bool flag = false;
    printf("Enter the element to be searched:\n");
    scanf("%d", &key);
    //binary search
    int start = 0, end = n, mid;
    while(start <= end){
        mid = (start + end) / 2;
        if(key > a[mid]){
            //ignore first half
            start = mid + 1;
        }
        else if(key < a[mid]){
            //ignore second half
            end = mid - 1;
        }
        else{
            //element found
            flag = true;
            printf("Element %d found at position %d\n", key, mid + 1);
            break;
        }
    }
    //if element not found
    if(!flag){
        printf("Element %d not found\n", key);
    }
}

void input(int a[], int* n){
    int i;
    printf("Enter the no. of elements:\n");
    scanf("%d", n);
    printf("Enter the elements:\n");
    //inputting the elements
    for(i = 0; i < *n; i++){
        scanf("%d", &a[i]);
    }
}


