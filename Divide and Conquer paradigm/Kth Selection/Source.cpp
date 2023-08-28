//-- Problem description --//
// 
// Given:      array of N numbers
// Required:   find value of K th smallest / largest element
// Case:       find kth Smallest element in: { 31, 41, 59, 26, -53, 58, 97, -93, -23, 84 } 
// Soloution:  3rd Smallest: 23

#include <iostream>
using namespace std;

void swap(int* k, int* l)
{
    int temp = *k;
    *k = *l;
    *l = temp;
}

int partition(int arr[], int l, int r) 
{
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; ++j)
        if (arr[j] <= pivot)
            swap(&arr[++i], &arr[j]);

    swap(&arr[i + 1], &arr[r]);

    return i + 1;
}

int kthSmallest(int arr[], int l, int r, int k) 
{
    if (l <= r) 
    {
        int pivotIndex = partition(arr, l, r);

        if (pivotIndex == k - 1)
            return arr[pivotIndex];

        else if (pivotIndex > k - 1)
            return kthSmallest(arr, l, pivotIndex - 1, k);

        else
            return kthSmallest(arr, pivotIndex + 1, r, k);
    }
    return -1;
}

int main()
{
    int arr[] = { 31, 41, 59, 26, -53, 58, 97, -93, -23, 84 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int kth = 3;

    cout << "the 2nd smallest element is: " << kthSmallest(arr, 0, size - 1, kth) << endl;
}