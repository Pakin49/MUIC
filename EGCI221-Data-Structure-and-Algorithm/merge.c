#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int comparison = 0; // Global variable
int size = 3000;

void merge_sort(int a[size], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        Merge(a, low, mid, high);
        comparison++;
    }
}

void Merge(int a[size], int low, int mid, int high)
{
    int b[size];
    int i0 = low, i1 = mid + 1;
    for (int j = low; j <= high; j++) 
    {
        if (i0 <= mid && (i1 > high || a[i0] <= a[i1]))
        {
            comparison++; 
            b[j] = a[i0];
            i0 += 1;
        }
        else
        {
            comparison++; 
            b[j] = a[i1];
            i1 += 1; 
        }
    }
    for (int i = low; i <= high; i++) 
        a[i] = b[i];
}

int main()
{   
    srand ( time(NULL) );
    int a[size]; // random array

    for (int i = 0; i < size; i++)
    {
        int random_number = (int)(((double)rand() / RAND_MAX) * 2000001) - 1000000;
        a[i] = random_number;
    }

    merge_sort(a, 0, size-1);
    printf("after sorting\n--------------------------------------------------------\n");

    for (int i = 0; i < size; i++)
        printf("%d : %d\n", i + 1, a[i]);
    printf("\nNumber of comparision = %d\n", comparison);
}
