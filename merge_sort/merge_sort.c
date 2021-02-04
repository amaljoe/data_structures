#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int p, int q, int r)
{
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    // create temporary arrays
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = a[p + i];
    for (j = 0; j < n2; j++)
        R[j] = a[q + j + 1];

    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int p, int r)
{
    if (p < r)
    {

        int q = (p + r) / 2;    //mid of the array
        mergeSort(a, p, q);     //sort 1st half
        mergeSort(a, q + 1, r); // sort 2nd half
        merge(a, p, q, r);      //merge both
    }
}

void printArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void main()
{
    int i, a[20], n;
    printf("Enter array size \n");
    scanf("%d", &n);
    printf("Enter array element \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Given array is \n");
    printArray(a, n);

    mergeSort(a, 0, n - 1);

    printf("\nSorted array is \n");
    printArray(a, n);
}