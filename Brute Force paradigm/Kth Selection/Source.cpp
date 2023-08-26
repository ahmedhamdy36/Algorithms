//-- Problem description --//
// 
// Given:      array of N numbers
// Required:   find value of K th smallest / largest element
// Case:       {14, 23, 45, 98, 6, 33, 42, 67} 
// Soloution:  3rd Smallest: 23
//             2nd Largest:  67


#include<iostream>
using namespace std;

void swap(int *k, int *l)
{
    int temp = *k;
    *k = *l;
    *l = temp;
}

void bubbleSort(int arr[],int size) {
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main()
{
	int arr[] = { 31, 41, 59, 26, -53, 58, 97, -93, -23, 84 };
    int size = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, size);

    cout << "the 2nd smallest element is: " << arr[1] << endl;
    cout << "the 2nd largest element is: " << arr[size - 2] << endl;
}