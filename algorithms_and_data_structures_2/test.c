#include <stdio.h>

void quickSort(int arr[], int low, int high, int* maxDepth, int* minDepth, int currentDepth);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);

int main()
{
    int arr[] = {19, 42, 20, 57, 53};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", n);
    int maxDepth = 0, minDepth = n;
    quickSort(arr, 0, n - 1, &maxDepth, &minDepth, 1);
    printf("Maximum depth of extreme nodes: %d\n", maxDepth);
    printf("Minimum depth of extreme nodes: %d\n", minDepth);
    return 0;
}

void quickSort(int arr[], int low, int high, int* maxDepth, int* minDepth, int currentDepth)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1, maxDepth, minDepth, currentDepth + 1);
        quickSort(arr, pi + 1, high, maxDepth, minDepth, currentDepth + 1);
    }
    else
    {
        // update maximum and minimum depths of extreme nodes
        if (currentDepth > *maxDepth)
        {
            *maxDepth = currentDepth;
        }
        if (currentDepth < *minDepth)
        {
            *minDepth = currentDepth;
        }
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
