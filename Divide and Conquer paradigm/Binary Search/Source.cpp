//-- Problem description --//
// 
// Given:      sorted array of N numbers
// Required:   find value of in the array
// Case:       find '7' in {1, 3, 7, 8, 9, 10, 11}:
// Soloution:  check the center {8}: (7 < 8)
//             then we select the right {1, 3, 7}: 
//             check the center {3}: (7 > 3)
//             then we select the left {7}: 
//             check the center{ 7 } then return 7


#include<iostream>
using namespace std;

bool Binarysearch(int arr[], int first, int end, int value)
{
    int center = (end + first) / 2;

    if (value == arr[center])
        return true;

    if (first == end)
    {
        return (value == arr[first]);
        return false;
    }
    else if (value < arr[center])
        Binarysearch(arr, first, center - 1, value);
    else
        Binarysearch(arr, center + 1, end, value);
}

int main()
{
    int arr[] = { 1, 3, 7, 8, 9, 10, 11 };
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int value = 11;
    cout << "Number " << value << ": " << Binarysearch(arr, 0, size - 1, value) << endl;

    value = 15;
    cout << "Number " << value << ": " << Binarysearch(arr, 0, size - 1, value) << endl;
}