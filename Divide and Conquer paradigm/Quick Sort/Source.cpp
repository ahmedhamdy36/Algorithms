//-- Problem description --//
// 
// Given:      array of N numbers
// Required:   sort the array
// Case:       { 31, 41, 59, 26, -53, 58, 97, -93, -23, 84 }
// Soloution:  { -93, -53, -23, 26, 31, 41, 58, 59, 84, 97 }


#include<iostream>
using namespace std;

int partition(int arr[], int l, int r) 
{
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; ++j)
        if (arr[j] <= pivot)
            swap(arr[++i], arr[j]);

    swap(arr[i + 1], arr[r]);

    return (i + 1);
}

void quickSort(int arr[], int l, int r) 
{
    if (l < r)
    {
        int position = partition(arr, l, r);

        quickSort(arr, l, position - 1);
        quickSort(arr, position + 1, r);
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

    quickSort(arr, 0, size - 1);

    cout << "Elements after sort : ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;
}