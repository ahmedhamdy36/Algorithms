//-- Problem description --//
// 
// Given:     array of N numbers
// Required:  find a sequence of contiguous numbers with max
// Case:      { 31, -41, 59, 26, -53, 58, 97, -93, -23, 84 }: 
// Soloution: { 59, 26, -53, 58, 97 }

#include <iostream>
#include <vector>
using namespace std;

vector<int> maximumSequenceSum(int arr[], int size) 
{
    int maxSum = arr[0];
    int currentSum = arr[0];
    int start = 0;
    int end = 0;
    int tempStart = 0;

    for (int i = 1; i < size; i++) 
    {
        if (arr[i] > currentSum + arr[i]) 
        {
            tempStart = i;
            currentSum = arr[i];
        }
        else
            currentSum = currentSum + arr[i];
        if (currentSum > maxSum) 
        {
            start = tempStart;
            end = i;
            maxSum = currentSum;
        }
    }

    vector<int> sequence;
    for (int i = start; i <= end; i++)
        sequence.push_back(arr[i]);

    return sequence;
}

int main() 
{
    int arr[] = { 31, -41, 59, 26, -53, 58, 97, -93, -23, 84 };
    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> sequence = maximumSequenceSum(arr, size);

    int sum = 0;
    for (int i = 0; i < sequence.size(); i++)
        sum += sequence[i];
    cout << "Maximum sum: " << sum << endl;

    cout << "Maximum sequence sum: ";
    for (int i = 0; i < sequence.size(); i++)
        cout << sequence[i] << " ";

    return 0;
}