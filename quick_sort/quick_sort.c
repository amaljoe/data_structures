#include <stdio.h>
#define SIZE 20

int arr[SIZE];
int n;

int partition(int, int);
void quickSort(int, int);
void display();

void main() {
    printf("Enter the no. of elements:\n");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++) {
        scanf(" %d", &arr[i]);
    }
    quickSort(0, n);
    display();
}

int partition(int start, int end) {
    int pivot = start;
    while(start < end) {
        while(arr[start] <= arr[pivot]) {
            start++;
        }
        while(arr[end] > arr[pivot]) {
            end--;
        }
        if(start < end) {
            // swap the elements
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    int temp = arr[end];
    arr[end] = arr[pivot];
    arr[pivot] = temp;
    return end;
}

void quickSort(int start, int end) {
    if(start < end) {
        int pivot = partition(start, end);
        quickSort(start, pivot -1);
        quickSort(pivot + 1, end);
    }
}

void display() {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}