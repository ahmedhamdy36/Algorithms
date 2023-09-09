//-- Problem description --//
// 
// Given:      Set of N tasks and each task has processing time P[i].
//             CPU can run 1 task at a time and the tasks run in non - preparation manner.
// Required:   Schedule these tasks to minimize their average computational time =  1/N  (∑_(i=1)^N▒C[i] )
// Case:       ProcessingTimes = {10, 5, 8, 12, 6}
// Soloution:  Minimum average computational time = 28.2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double minimizeAverageTime(const vector<int>& processingTimes) 
{
    int n = processingTimes.size();

    vector<int> sortedTimes = processingTimes;
    sort(sortedTimes.rbegin(), sortedTimes.rend());

    vector<int> completionTimes(n);
    completionTimes[0] = sortedTimes[0];

    for (int i = 1; i < n; i++)
        completionTimes[i] = completionTimes[i - 1] + sortedTimes[i];

    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += completionTimes[i];

    return (sum / n);
}

int main() 
{
    vector<int> processingTimes = { 10, 5, 8, 12, 6 };
    cout << "Minimum average computational time: " << minimizeAverageTime(processingTimes) << endl;
    return 0;
}