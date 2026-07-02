#pragma once

#include <stdlib.h>

static void Merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;


    int* leftArr  = (int*)malloc(n1 * sizeof(int));
    int* rightArr = (int*)malloc(n2 * sizeof(int));

    int i;
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];


    int iLeft = 0, iRight = 0, k = left;
    while (iLeft < n1 && iRight < n2)
    {
        if (leftArr[iLeft] <= rightArr[iRight])
            arr[k++] = leftArr[iLeft++];
        else
            arr[k++] = rightArr[iRight++];
    }


    while (iLeft < n1)
        arr[k++] = leftArr[iLeft++];


    while (iRight < n2)
        arr[k++] = rightArr[iRight++];

    free(leftArr);
    free(rightArr);
}

void MergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        Merge(arr, left, mid, right);
    }
}

