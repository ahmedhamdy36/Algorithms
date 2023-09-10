//-- Problem description --//
// 
// Given:      A set of items into the minimum number of bins with a fixed capacity and each item has a specific size.
// Required:   We need to minimize the number of bins used.
// Case:       Items = 5 & bin capacity = 100 units & sizes = { 20, 30, 40, 50, 60 }
// Soloution:  3 bins

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculateBinsUsed(const vector<int>& packing, int binCapacity) 
{
    int n = packing.size();
    vector<int> bins;

    for (int i = 0; i < n; i++)
    {
        bool packed = false;

        for (int j = 0; j < bins.size(); j++)
            if (bins[j] + packing[i] <= binCapacity) 
            {
                bins[j] += packing[i];
                packed = true;
                break;
            }

        if (!packed)
            bins.push_back(packing[i]);
    }

    return bins.size();
}

vector<vector<int>> generateNeighbors(const vector<int>& packing) 
{
    vector<vector<int>> neighbors;
    int n = packing.size();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j) 
            {
                vector<int> neighbor = packing;
                neighbor[i] = packing[j];
                neighbor[j] = packing[i];
                neighbors.push_back(neighbor);
            }

    return neighbors;
}

vector<int> incrementalBinPacking(const vector<int>& items, int binCapacity) 
{
    int n = items.size();
    vector<int> currentPacking = items;
    vector<int> bestPacking = currentPacking;

    int currentBinsUsed = calculateBinsUsed(currentPacking, binCapacity);
    int bestBinsUsed = currentBinsUsed;

    while (true) 
    {
        vector<vector<int>> neighbors = generateNeighbors(currentPacking);
        bool improvement = false;

        for (const auto& neighbor : neighbors) 
        {
            int binsUsed = calculateBinsUsed(neighbor, binCapacity);

            if (binsUsed < currentBinsUsed) 
            {
                currentPacking = neighbor;
                currentBinsUsed = binsUsed;
                improvement = true;
                break;
            }
        }

        if (!improvement)
            break;

        if (currentBinsUsed < bestBinsUsed) 
        {
            bestPacking = currentPacking;
            bestBinsUsed = currentBinsUsed;
        }
    }

    return bestPacking;
}

int main() 
{
    vector<int> items = { 20, 30, 40, 50, 60 };
    int binCapacity = 100;

    vector<int> packing = incrementalBinPacking(items, binCapacity);

    cout << "Bins Used: " << calculateBinsUsed(packing, binCapacity) << endl;

    cout << "Packing: ";
    for (int item : packing)
        cout << item << " ";

    return 0;
}