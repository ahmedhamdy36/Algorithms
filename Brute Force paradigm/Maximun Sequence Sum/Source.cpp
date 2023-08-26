#include<iostream>
#include<vector>
using namespace std;

vector<int> findMaxSumSubarray(const vector<int>& arr) {
    int maxSum = arr[0];
    int startIndex = 0;
    int endIndex = 0;

    // Iterate through all possible subarrays
    for (int i = 0; i < arr.size(); ++i) {
        int currentSum = 0;
        for (int j = i; j < arr.size(); ++j) {
            currentSum += arr[j];
            if (currentSum > maxSum) {
                maxSum = currentSum;
                startIndex = i;
                endIndex = j;
            }
        }
    }
    vector<int> maxSumSubarray(arr.begin() + startIndex, arr.begin() + endIndex + 1);
    return maxSumSubarray;
}

int main()
{
    vector<int> arr = { 31, 41, 59, 26, -53, 58, 97, -93, -23, 84 };
    vector<int> maxSumSubarray = findMaxSumSubarray(arr);

    // Print the maximum sum and the subarray
    cout << "Maximum Sum: " << maxSumSubarray.size() << endl;
    cout << "Subarray: ";

    for (int num : maxSumSubarray) {
        cout << num << " ";
    }

	return 0;
}