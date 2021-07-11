#include <stdio.h>

#define SIZE 50;

void display(int[], int);
void max_heapify(int[], int, int);
void build_heap(int[], int);
void heap_sort(int[], int);

int main()
{
    int length = 6;
    int arr[50] = {9,3,6,8,1,2};
    printf("Hello world\n");
    display(arr, length);
    heap_sort(arr, length);
    display(arr, length);
}

void display(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void max_heapify(int arr[], int i, int heapsize)
{
    int l = (i + 1) * 2 - 1;
    int r = (i+ 1) * 2;
    int largest = i;
    if (l < heapsize && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < heapsize && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        max_heapify(arr, largest, heapsize);
    }
}

void build_heap(int arr[], int heapsize)
{
    for (int i = heapsize / 2 - 1; i >= 0; i--)
    {
        max_heapify(arr, i, heapsize);
    }
}

void heap_sort(int arr[], int heapsize)
{
    build_heap(arr, heapsize);
    for (int i = heapsize - 1; i >= 1; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        max_heapify(arr, 0, i);
    }
}