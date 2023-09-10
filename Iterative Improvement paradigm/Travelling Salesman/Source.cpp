//-- Problem description --//
// 
// Given:      A salesperson needs to visit a set of cities exactly once and return to the starting city.
// Required:   Get the minimize the total of distance traveled 
// Case:       The cities: {A, B, C, D} & The distances : { AB = 10, AC = 15, AD = 20, BC = 25, BD = 30, and CD = 35}
// Soloution:  A B C D , Distance = 90

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculateDistance(const vector<int>& solution, const vector<vector<int>>& distances) 
{
    int totalDistance = 0;
    int n = solution.size();

    for (int i = 0; i < n - 1; i++)
        totalDistance += distances[solution[i]][solution[i + 1]];

    totalDistance += distances[solution[n - 1]][solution[0]];

    return totalDistance;
}

vector<vector<int>> generateNeighbors(const vector<int>& solution) 
{
    vector<vector<int>> neighbors;
    int n = solution.size();

    for (int i = 1; i < n - 1; i++)
        for (int j = i + 1; j < n; j++) 
        {
            vector<int> neighbor = solution;
            swap(neighbor[i], neighbor[j]);
            neighbors.push_back(neighbor);
        }

    return neighbors;
}

vector<int> incrementalTSP(const vector<vector<int>>& distances) 
{
    int n = distances.size();
    vector<int> currentSolution(n);
    vector<int> bestSolution(n);

    for (int i = 0; i < n; i++) 
    {
        currentSolution[i] = i;
        bestSolution[i] = i;
    }

    int currentDistance = calculateDistance(currentSolution, distances);
    int bestDistance = currentDistance;

    while (true) 
    {
        vector<vector<int>> neighbors = generateNeighbors(currentSolution);
        bool improvement = false;

        for (const auto& neighbor : neighbors) 
        {
            int neighborDistance = calculateDistance(neighbor, distances);

            if (neighborDistance < currentDistance) 
            {
                currentSolution = neighbor;
                currentDistance = neighborDistance;
                improvement = true;
                break;
            }
        }

        if (!improvement)
            break;

        if (currentDistance < bestDistance) 
        {
            bestSolution = currentSolution;
            bestDistance = currentDistance;
        }
    }

    return bestSolution;
}

int main() 
{
    vector<vector<int>> distances = 
    {
        {0, 10, 15, 20},
        {10, 0, 25, 30},
        {15, 25, 0, 35},
        {20, 30, 35, 0}
    };

    vector<int> solution = incrementalTSP(distances);

    cout << "Total Distance: " << calculateDistance(solution, distances) << endl;

    cout << "Optimal Solution: ";
    for (int city : solution)
        cout << city << " ";

    return 0;
}