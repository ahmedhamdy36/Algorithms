//-- Problem description --//
// 
// Given:      array of N numbers
// Required:   sort the array
// Case:       { 31, 41, 59, 26, -53, 58, 97, -93, -23, 84 }:
// Soloution:  { -93, -53, -23, 26, 31, 41, 58, 59, 84, 97 }


#include<iostream>
using namespace std;

void merge(int arr[], int l, int center, int r)
{
    int lSize = center - l + 1;
    int rSize = r - center;

    int* leftArr;
    int* rightArr;
    leftArr = new int[lSize];
    rightArr = new int[rSize];

    for (int i = 0; i < lSize; ++i)
        leftArr[i] = arr[l + i];

    for (int j = 0; j < rSize; ++j)
        rightArr[j] = arr[center + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < lSize && j < rSize)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            ++i;
        }
        else 
        {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    while (i < rSize)
    {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    while (j < rSize)
    {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}


void mergeSort(int arr[], int l, int r) 
{
    if (l < r) 
    {
        int center = l + (r - l) / 2;

        mergeSort(arr, l, center);
        mergeSort(arr, center + 1, r);

        merge(arr, l, center, r);
    }
}

int main()
{
    int arr[] = { 31, 41, 59, 26, -53, 58, 97, -93, -23, 84 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Elements before sort: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;

    mergeSort(arr, 0, size - 1);

    cout << "Elements after sort : ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;

    return 0;
}