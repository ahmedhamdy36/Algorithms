//-- Problem description --//
// 
// Given:      There are N different items in a store.
//             Item i weighs wi pounds and is worth $vi
//             A thief breaks in
//             He can carry up to W pounds in his knapsack
//             Fractions of items can be taken
//             e.g., A thief stealing gold dust
// Required:   get the maximum benefit.
// Case:       knapsackCapacity = 50, weight: {10, 20, 30}, and values : {60, 100, 120}.
// Soloution:  240

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item 
{
    int weight;
    int value;
};

bool getMax(Item i1, Item i2) 
{
    double ratio1 = (double)i1.value / i1.weight;
    double ratio2 = (double)i2.value / i2.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(int knapsackCapacity, vector<Item>& items) 
{
    sort(items.begin(), items.end(), getMax);

    double totalValue = 0;
    int currentWeight = 0;

    for (const auto& item : items) 
    {
        if (currentWeight + item.weight <= knapsackCapacity) 
        {
            currentWeight += item.weight;
            totalValue += item.value;
        }
        else 
        {
            int remainingCapacity = knapsackCapacity - currentWeight;
            totalValue += (double)item.value / item.weight * remainingCapacity;
            break;
        }
    }

    return totalValue;
}

int main() 
{
    int knapsackCapacity = 50;
    vector<Item> items = 
    {
        {10, 60},
        {20, 100},
        {30, 120}
    };

    cout << "Maximum value in the knapsack: " << fractionalKnapsack(knapsackCapacity, items) << endl;

    return 0;
}